#include <iostream>
#include <Windows.h>
#include <process.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>
#include <mbstring.h>
#define BUF_SIZE 256
static void cat(LPTSTR, LPTSTR);

int main(DWORD argc, LPTSTR argv[])
{
	HANDLE hTempFile;
	BOOL prov;
	TCHAR outFile[MAX_PATH + 100];
	SECURITY_ATTRIBUTES StdOutSA =
	{ 
	sizeof
	(SECURITY_ATTRIBUTES), NULL, TRUE };
	TCHAR CommandLine[MAX_PATH + 100];
	STARTUPINFO StartUpSearch, StartUp;
	PROCESS_INFORMATION ProcessInfo;
	DWORD iProc, ExCode;
	HANDLE* hProc;
	typedef struct
	{
		TCHAR TempFile[MAX_PATH];
	}
	PROCFILE;
	PROCFILE* ProcFile;
	GetStartupInfo(&StartUpSearch);
	GetStartupInfo(&StartUp);
	ProcFile = (PROCFILE*)malloc((argc - 2) * sizeof(PROCFILE));
	hProc = (HANDLE*)malloc((argc - 2) * sizeof(HANDLE));
	for (iProc = 0; iProc < argc - 2; iProc++)
	{
		printf_s(("%s"), ("grep "), argv[1], argv[iProc + 2]);
		printf(("%s\n"), CommandLine);
		hTempFile = CreateFile(ProcFile[iProc].TempFile, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, &StdOutSA, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		StartUpSearch.dwFlags = STARTF_USESTDHANDLES;
		StartUpSearch.hStdOutput = hTempFile;
		StartUpSearch.hStdError = hTempFile;
		StartUpSearch.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
		CreateProcess(NULL, CommandLine, NULL, NULL,
			TRUE, 0, NULL, NULL, &StartUpSearch, &ProcessInfo);
		CloseHandle(hTempFile);
		CloseHandle(ProcessInfo.hThread);
		hProc[iProc] = ProcessInfo.hProcess;
	}
	for (iProc = 0; iProc < argc - 2; iProc += MAXIMUM_WAIT_OBJECTS)
		WaitForMultipleObjects(min(MAXIMUM_WAIT_OBJECTS, argc - 2 -
			iProc), &hProc[iProc], TRUE, INFINITE);
	for (iProc = 0; iProc < argc - 2; iProc++)
	{
		printf("Proc= %d\n", iProc);
		prov = GetExitCodeProcess(hProc[iProc], &ExCode);
		if (ExCode != 0) DeleteFile(ProcFile[iProc].TempFile);
		if (GetExitCodeProcess(hProc[iProc], &ExCode) && ExCode == 0)
		{
			if (argc > 3) printf(("%s : \n"), argv[iProc + 2]);
			fflush(stdout);
			printf_s(("%s"), ProcFile[iProc].TempFile);
			cat(argv[iProc + 2], (LPTSTR)outFile);
			printf_s(("%s%s"), ("cat "), ProcFile[iProc].TempFile);
			printf(("%s\n"), CommandLine);
			CreateProcess(NULL, CommandLine, NULL, NULL, TRUE, 0, NULL, NULL, &StartUp, &ProcessInfo);
			WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
			CloseHandle(ProcessInfo.hProcess);
			CloseHandle(ProcessInfo.hThread);
		}
		CloseHandle(hProc[iProc]);
	}
	free(ProcFile);
	free(hProc);
	return 0;
}
static VOID cat(LPTSTR hInFile, LPTSTR hOutFile)
{
	CopyFile(hInFile, hOutFile, FALSE);
	return;
}

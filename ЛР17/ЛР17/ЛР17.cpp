#include "pch.h"
using namespace System;
using namespace System::IO;
namespace ЛР17
{
	public ref class Program
	{
	public:
		static void Main()
		{
			for each (String ^ entry in Directory::GetDirectories("C:\\"))
			{
				DisplayFileSystemInfoAttributes(gcnew DirectoryInfo(entry));
			}
			for each (String ^ entry in Directory::GetFiles("C:\\"))
			{
				DisplayFileSystemInfoAttributes(gcnew FileInfo(entry));
			}
		}
		static void DisplayFileSystemInfoAttributes(FileSystemInfo^ fsi)
		{
			String^ entryType = "File";
			if ((fsi->Attributes & FileAttributes::Directory) == FileAttributes::Directory)
			{
				entryType = "Directory";
			}
			Console::WriteLine("{0} entry {1} was created on {2:D}", entryType, fsi->FullName, fsi->CreationTime);
		}
	};
};
int main()
{
	ЛР17::Program::Main();
}

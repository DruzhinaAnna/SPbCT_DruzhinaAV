#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pID = fork();

    /* child */
    if (pID == 0)
    {
        printf("\nFire in the hole!\n");
        kill(getppid(), 9);
        printf("\nI killed it with fire!\n");
    }
    /* parent */
    else
    {
        printf("\nYou fit my crosshair perfectly!\n");
    }
}
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    int n;

    if (argc < 2)
        n = 1;
    else
        n = atoi(argv[1]);

    if (n < 0 || n > 20)
        n = 2;

    int x = 0;
    int pid = 0;

    for (int k = 0; k < n; k++)
    {
        pid = fork();
        if (pid > 0)
        {
            sleep(500);
            kill(pid, 1);
        }

        else
        {
            pause();
            for (int z = 0; z < 3000000000; z += 1)
            {
                x = x + 3.14 * 89.64;
            }
            break;
        }
    }
    exit();
}

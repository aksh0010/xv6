#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"


int main(int argc, char *argv[]) {
    int m;
    int i=0;
    int k=0;
    if(argc<2)                      // if argument character is less 2 
    {
        m = 1;                      // we will set m to 1
    }
    else                            //else
    {
        m = atoi(argv[1]);             // we will convert the first argument character to integer and will assign it to m 
    }
    if(m<0 || m>20)                 // if m is less than 0 and greater than 20 
    {
        m = 2;                      // we will set m to 2
    }

    int x=0;
    int pid=0;

    for (i=0;i<m;i++)               // Creating a for loop for forking the process
    {
        pid=fork();                 // Forking a process
        if(pid>0)                   // Parent process will wait for the child process 
        {
            wait();
        }

        else{           
            for(k=0;k<3000000000;k+=1)  // child process will execute the loop by performing the calculations and will exit the system call 
            x=x+3.14*89.64;
            break;
        }
    }
    exit();
}

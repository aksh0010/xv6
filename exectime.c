
/* Aksh Patel
*  110028941
*  University of Windsor
*/

#include "types.h"
#include "stat.h"
#include "user.h"

int main ( int argc , char *argv[])
{

    if(argc <=1){
        // usage msg if arguments are less than one
        printf(1,"usage : exectime command argument-list\n");
        exit();
    }
    int upTime;
	upTime = uptime(); // variable to store current time
	int downTime;       // variable to store final time
    printf(1, "uptime: %d \n", upTime);

    int pid;
    pid = fork(); 
    char **arguments = &argv[1];
    if(pid < 0) {
        //child was not created successfully
        printf(1,"Unsuccesfull creation of child\n");
        exit();
    }
    else if(pid == 0) {        
        // Child body
        // child will execute the exec command
        exec(argv[1], arguments);

    }
    else {
        //Parent body.
        // Parent should wait else will create zombie process
        wait();
        
    }
	downTime=uptime(); 
    printf(1, "uptime: %d \n", downTime);
    wait();  // waiting called by parent incase child is behind 
	exit();
}

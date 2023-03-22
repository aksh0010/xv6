#include "types.h"
#include "fcntl.h"
#include "user.h"
#include "stat.h"

int main(int argc, char *argv[])
{
	int pid;	  // It is the priority ID of the process whose priority we have to set
	int priority; // It is the priority value which we have to set.
				  // atoi() is a function which takes argument from command line and converts string into integer
	pid = atoi(argv[1]);
	priority = atoi(argv[2]);
	if (priority < 0 || priority > 20)
	{
		printf(1, "Please input number between 1 to 20\n"); // It will print warning message if we enter number more than 20 or less than 1
		exit();
	}
	set(pid, priority);
	exit();
}

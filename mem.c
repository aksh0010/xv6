
#include "types.h"
#include "stat.h"
#include "user.h"
// #include "defs.h"

int main ( int argc , char *argv[])
{


	int *p = malloc(sizeof(int));
	 if(p!=0){
     printf(1, "%d Address pointed to by p : %d \n", getpid(), p);
	//   printf(1,"(%s) address pointed to by p: %p\n", getpid(), p);
	 *p =0;
	while(1) {
	  sleep(100);
	  *p = *p +1;
	   printf(1, "%d p: %d \n\n", getpid(), *p);
	// printf("(%s) p: %d\n", getpid(), *p);
	}
	 
	}
	exit();
}

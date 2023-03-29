# xv6
Xv6 source code with my modifications.

For purposes of learning I used below books 

    1) https://pages.cs.wisc.edu/~remzi/OSTEP/ 
    2) https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf

Original source code can be found out from : https://github.com/mit-pdos/xv6-public 

If you want to learn more about operating system, here are books i am refereing for my modifications of code

    1) https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf
    2) https://pages.cs.wisc.edu/~remzi/OSTEP/ 

Programs I have added or updated

    1)mem.c (Memory virtualization demo)
    2)exectime.c (exec time but return times to execute the program)
    3)sh.c ( added whoami implementation)
    4)mystdiotest.c (Buffered I/O )
    5)pstate.c ( created my own System call similar to ps() in unix)
    6)set.c (for priority scheduling)
    7)pause() ( system call which causes the current process to be suspended, waiting for a signal to proceed )
    8)kill(pid, flag) ( Extend system call kill(pid) to kill(pid, flag) where flag can be 0 or 1. kill(pid, 0) should work like kill(pid): terminate the process with           pid. kill(pid, 1) should send a signal to process pid to resume this process if it has been suspended with pause().)


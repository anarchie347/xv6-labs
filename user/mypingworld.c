#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    int mypid = getpid();
    printf("Main pid: %d\n", mypid);

    int pipe_ParentChild[2];
    int pipe_ChildParent[2];
    pipe(pipe_ParentChild);
    pipe(pipe_ChildParent);
    int pid = fork();
    
    if (pid == 0) {
        //child
        //int cpid = getpid();
        //printf("cpid: %d\n", cpid);
        char recieved[5]; 
        read(pipe_ParentChild[0], recieved, 5);
        printf("Child-%d: ", getpid());
        write(1,recieved,5);
        write(1,"\n",1);
        
        char msg[] = "World!";
        write(pipe_ChildParent[1],msg,6);
} else {
        //parent
        //pid = child pid
        char msg[] = "Hello"; //5
        //int ignore[1];
        //wait(ignore);
        //printf("ppid: %d\n", getpid());
        write(pipe_ParentChild[1], msg,5);
        char sent_back[6];
        read(pipe_ChildParent[0], sent_back, 6);
        printf("Parent-%d: ", getpid());
        write(1,sent_back,6);
        write(1, "\n", 1);
}

    exit(0);
}

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {

    int pipe_ParentChild[2];
    int pipe_ChildParent[2];
    pipe(pipe_ParentChild);
    pipe(pipe_ChildParent);
    int pid = fork();
    
    if (pid == 0) {
        //child
        //int cpid = getpid();
        //printf("cpid: %d\n", cpid);
        char recieved[1]; 
        read(pipe_ParentChild[0], recieved, 1);
        if (recieved[0] != 'a')
            exit(1);

        printf("%d: received ping\n", getpid());
        char msg[] = "b";
        write(pipe_ChildParent[1],msg,6);
} else {
        //parent
        //pid = child pid
        char msg[] = "a"; //5
        //int ignore[1];
        //wait(ignore);
        //printf("ppid: %d\n", getpid());
        write(pipe_ParentChild[1], msg,1);
        char sent_back[1];
        read(pipe_ChildParent[0], sent_back, 1);
        if (sent_back[0] != 'b')
            exit(2);
        printf("%d: received pong\n", getpid());
}

    exit(0);
}

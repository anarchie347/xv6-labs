// sleep

#include "kernel/types.h"
#include "user/user.h"
#include "kernel/stat.h"

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        fprintf(2, "Error: sleep requires 1 argument\n");
        exit(1);
    }
    
    int sleeplen = atoi(argv[1]);
    sleep(sleeplen);

    exit(0);
}
    

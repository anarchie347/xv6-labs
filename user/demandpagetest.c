#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main() {
    printf("expanind heap...\n");
    void *ptr = sbrk(3276800);
    *(char *)ptr = 'A';
    printf("success\n");
    exit(0);
}

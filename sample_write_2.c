#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
 
int main()
{
    // The syscall function takes the system call number as the first argument
    syscall(SYS_write, 1, "Hello world!\n", 14);
    return 0;
}

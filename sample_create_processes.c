#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
 
int main() {
   pid_t pid;
 
   // Create a child process
   pid = fork();
   if (pid == -1) {
      // fork failed
      perror("fork");
      return 1;
   } else if (pid == 0) {
      // This is the child process
      printf("Child process: pid = %d\n", getpid());
   } else {
      // This is the parent process
      printf("Parent process: pid = %d, child pid = %d\n", getpid(), pid);
      wait(NULL);
   }
 
   return 0;
}

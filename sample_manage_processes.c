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
 
      // Replace the child process with a new program
      execl("/bin/ls", "ls", "-l", NULL);
      perror("execl");
      return 1;
   } else {
      // This is the parent process
      printf("Parent process: pid = %d, child pid = %d\n", getpid(), pid);
 
      // Wait for the child process to complete
      int status;
      waitpid(pid, &status, 0);
      if (WIFEXITED(status)) {
         printf("Child process exited with status %d\n", WEXITSTATUS(status));
      } else {
         printf("Child process did not exit normally\n");
      }
   }
 
   return 0;
}
 

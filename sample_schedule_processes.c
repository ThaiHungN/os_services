#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/wait.h>

 
#define NUM_PROCESSES 3
 
int main() {
   int i;
   pid_t pid[NUM_PROCESSES];
 
   // Create child processes
   for (i = 0; i < NUM_PROCESSES; i++) {
      pid[i] = fork();
      if (pid[i] == 0) {
         // This is the child process
         break;
      }
   }
 
   if (pid[i] == 0) {
      // This is the child process
      int count = 0;
      while (count < 10) {
         printf("Child %d: count = %d\n", i, count);
         count++;
         sched_yield();
      }
   } else {
      // This is the parent process
      for (i = 0; i < NUM_PROCESSES; i++) {
         wait(NULL);
      }
   }
 
   return 0;
}
 

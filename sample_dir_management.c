#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
 
int main() {
   int status;
 
   // Create a new directory
   status = mkdir("test_dir", 0700);
   if (status == 0) {
      printf("Directory created\n");
   } else {
      perror("mkdir");
   }
 
   return 0;
}

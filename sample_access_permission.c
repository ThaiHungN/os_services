#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
 
int main() {
   int status;
 
   // Set the permissions of a file to read-only for the owner
   status = chmod("file2.txt", 0400);
   if (status == 0) {
      printf("Permissions set\n");
   } else {
      perror("chmod");
   }
 
   return 0;
}

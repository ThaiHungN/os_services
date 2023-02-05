#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fp;

   // File creation
   fp = fopen("file_create.txt", "w");
   if (fp == NULL) {
      printf("Could not create file\n");
      exit(1);
   }
   printf("File created successfully\n");
   fclose(fp);

   // File deletion
   if (remove("file_create.txt") != 0) {
      printf("Could not delete file\n");
      exit(1);
   }
   printf("File deleted successfully\n");

   return 0;
}

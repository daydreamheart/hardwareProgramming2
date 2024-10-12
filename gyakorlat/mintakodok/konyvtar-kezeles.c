// Könyvtár listázása

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
   DIR *d;
   struct dirent *entry;
   d = opendir(".");
   printf(" -my ls:\n");

   while ((entry = readdir(d)) != NULL)
   {
      if ((*entry).d_name[0] != '.')
         printf("%s\t", (*entry).d_name);
   }

   closedir(d);

   printf("\n -system ls:\n");
   chdir("."); // Valójában nem szükséges, csak példa
   system("ls");

   return 0;
}

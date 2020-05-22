// Tallózó program
// Magyar Melinda Barbara - E5JCB7

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main (int argc, char* argv[]) {
    DIR *d;
    int tmp;
    struct dirent *entry;
    struct stat inode;
    d = opendir(getenv("HOME"));

    // alapértelmezett könyvtár tartalma (rejtett fájlok is)
    printf("Default directory's ls:\n");
    while((entry = readdir(d)) != NULL)  
        printf("%s\t", (*entry).d_name);

    printf("\n");

    char name[500];
    char path[500], save[500];

    while(1) {
      char* dir = getenv("HOME");      
      strcpy(path, dir);

      start:
      printf("\nPlease choose a directory or a file from above.\n");
      scanf("%s", name);
      strcat(path, "/");
      strcpy(save, path);
      strcat(path, name);

      tmp = stat(path, &inode);
      // ha nem fájl/könyvtár kérjünk be új nevet
      if(tmp < 0) {
        fprintf(stderr, "Bad name!\n");
        strcpy(path, save);
        goto start;
      }

      // ha könyvtár -> ismétlés, amíg nem fájlt ír be a felhasználó
      if(inode.st_mode&S_IFDIR) {
        printf("\n\"%s\" is a directory.\n", name);

        d = opendir(path);

        printf("\nDirectory's ls:\n");
        while((entry = readdir(d)) != NULL)  
            printf("%s\t", (*entry).d_name);

        printf("\n");
        goto start;
      }

      // ha fájl, írja ki a méretét és fejezze be a programot
      if(inode.st_mode&S_IFREG) {
        printf("\n\"%s\" is a file.\n", name);
        printf("Size: %d byes\n", (int)inode.st_size);
        return 0;
      }

    }

    closedir(d);
    return 0;
}
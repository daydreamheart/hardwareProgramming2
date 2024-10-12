// Példa formázott fájlhasználatra

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BlockSize 1024

int main(int argc, char *argv[])
{
   char buff[BlockSize];
   int in, out;
   int nread;

   if (argc < 3)
   {
      write(2, " 1st argument: origin file\n 2nd argument: copy file\n", 52);
      return 1;
   }

   in = open(argv[1], O_RDONLY);
   out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

   while ((nread = read(in, buff, BlockSize)) > 0)
      write(out, buff, nread);

   close(in);
   close(out);

   return 0;
}

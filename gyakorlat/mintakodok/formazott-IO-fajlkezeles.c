// Példa formázott fájlhasználatra

#include <stdio.h>

int main()
{
   int pos;
   char c, text[100];
   FILE *f;

   // Fájl megnyitása
   f = fopen("file.txt", "w+");
   if (f == NULL)
   {
      fprintf(stderr, " There is a file opening problem!\n");
      return 1;
   }

   // Fájlba írás
   fprintf(stdout, " What word would you like to write into the file?\n   ");
   fscanf(stdin, "%s", text);
   fprintf(f, "%s", text);

   // Pozícionálás és felülírás
   fprintf(stdout, " Let's owerwrite something!\n  From which character? Give a number! ");
   fscanf(stdin, "%d", &pos);
   fprintf(stdout, "  What is the new text? ");
   fscanf(stdin, "%s", text);
   fseek(f, pos - 1, SEEK_SET);
   fprintf(f, "%s", text);

   // Fájl olvasása
   fprintf(stdout, " Now the file contetnt is:\n   ");
   fseek(f, 0, SEEK_SET);

   while (1)
   {
      fscanf(f, "%c", &c);

      if (feof(f))
         break;

      fprintf(stdout, "%c", c);
   }

   // Fájl bezárása
   fclose(f);

   return 0;
}

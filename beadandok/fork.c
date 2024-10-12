/*
A hallgatók feladata egy program írása, amely a következőt valósítja meg:
- Tartalmaz egy 100 lépéses ciklust.
- A ciklus minden lépésben kiírja a ciklusváltozó értékét a standard kimenetre és egy fájlba.
- Ezt forkolással valósítja meg:
       - A szülő folyamat felelős a ciklusszervezésért és a standard kimenetre írásért.
       - A gyermek folyamat végzi a fájlba írást.
- Futás után mind a fájlban, mind a standard kimeneten szeretnénk látni az összes értéket egymás alatt, amelyet felvett a ciklusváltozó.
*/

// Magyar Melinda Barbara

#include <stdio.h>
#include <unistd.h>

int main()
{
    __pid_t pid = fork();
    FILE *f = fopen("out.txt", "w");

    for (int i = 0; i < 100; i++)
    {
        if (pid == 0)
        {
            fprintf(f, "%d\n", i + 1);
        }
        else
            fprintf(stdout, "%d\n", i + 1);
    }

    fclose(f);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // Környezeti változó; aktuális felhasználó nevének kiírása
    printf("%s\n", getenv("LOGNAME"));

    // Kilistázza az aktuális elérési helyen lévő fájlokat
    // A vezérlés átkerül a meghívott programhoz, majd ha lefutott vissza a rendszerhez
    system("ls");

    return 0;
}

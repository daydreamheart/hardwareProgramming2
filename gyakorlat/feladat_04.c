#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

    // környezeti változó; aktuális felhasználó nevének kiírása
    printf("%s\n", getenv("LOGNAME")); 

    // kilistázza az aktuális elérési helyen lévő fájlokat
    // a vezérlés átkerül a meghívott programhoz, majd ha lefutott
    // vissza a rendszerhez
    system("ls");

    return 0;
}

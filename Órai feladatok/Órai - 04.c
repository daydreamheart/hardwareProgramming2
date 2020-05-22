#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

    printf("%s\n", getenv("LOGNAME")); 
    // környezeti változó; aktuális felhasználó nevének kiírása

    system("ls");
    // kilistázza az aktuális elérési helyen lévő fájlokat
    // a vezérlés átkerül a meghívott programhoz, majd ha lefutott
    // vissza a rendszerhez

    return 0;
}
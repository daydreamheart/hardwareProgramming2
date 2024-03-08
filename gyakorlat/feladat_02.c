#include <stdio.h>

int main(int argc, char *argv[]) {
    
    fprintf(stdout, "Standard kimenet\n");
    fprintf(stderr, "Standard hiba\n");

    return 0;

    // ./02 1> kimenet.txt 2> hiba.txt - átirányítja ide
}

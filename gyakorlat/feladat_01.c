#include <stdio.h>

int main(int argc, char *argv[]) {
    
    if (argc == 1)
        return 1;
    
    for (int i = 0; i < argc; i++)
        printf("%s\n", argv[i]);

    return 0;

    // gcc 01.c -o 01
    // ./01 alma 1 2 3 4
    // ./01 "alma 1"
}

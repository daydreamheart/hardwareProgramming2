#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    if (argc == 1)
        printf("Hello %s!\n", getenv("LOGNAME"));
    else
        printf("Hello %s!\n", argv[1]);

    return 0;
    
}

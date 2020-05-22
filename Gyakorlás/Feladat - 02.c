#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    printf("Hello %s!\n", getenv("LOGNAME"));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
        printf("Hello, %s!\n", getenv("LOGNAME"));
    else if ((argc == 2) && (strcmp(argv[1], "-hu") == 0))
    {
        printf("Hello, %s!\n", getenv("LOGNAME"));
        return 0;
    }
    else if ((argc == 3) && (strcmp(argv[1], "-hu") == 0))
    {
        printf("Hello, %s!\n", argv[2]);
        return 0;
    }
    else
        printf("Hello, %s!\n", argv[1]);

    return 0;
}

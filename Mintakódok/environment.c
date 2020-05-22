// Környezeti változók lekérdezése és beállítása
// parancssori argumentumokkal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NoArg 1

int main(int argc, char* argv[]) {
    char *var, *value;

    if(argc == 1) {
        printf(" %s: I need an argument. \n", argv[0]);
        return NoArg;
    }

    if(argc == 2) {
        var = argv[1];
        value = getenv(var);

        if(value != NULL)
            printf("$%s=%s\n", var, value);
        else
            printf("$%s has no value\n", var);
    }

    if(argc == 3) {
        char *string;
        var = argv[1];
        value = argv[2];
        string = (char*)malloc(strlen(var)+strlen(value)+ 2);
        strcpy(string, var);
        strcat(string, "=");
        strcat(string, value);
        printf("Calling putenv with: %s\n", string);
        putenv(string);
        free(string);
    }

    return 0;
}
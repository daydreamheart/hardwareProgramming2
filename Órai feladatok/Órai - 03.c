#include <stdio.h>

int main (int argc, char *argv[]){

    char array[100];
    scanf("%s", array);
    printf("X%s\n", array);

    return 0;

    // echo abc / ./03 - az abc kimenetét a ./03-ból olvassa be
    // kimenet: Xabc lesz
}
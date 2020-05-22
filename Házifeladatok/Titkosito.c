// Titkosító program
// Magyar Melinda Barbara - E5JCB7
// bemenet.txt tartalma, amivel teszteltem: 123abc
// math.h miatt -lm kapcsolóval kell fordítani - gcc nev.c -o nev -lm

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BlockSize 1024

// első és utolsó bit cseréje
char* swapBits (int number) {
    static char binary[32];
    sprintf(binary, "%d", number);
    int size = strlen(binary);

    int elso = binary[size-1];
    binary[size-1] = binary[0];
    binary[0] = elso;

   return binary;  
}

// átváltás kettes számrendszer beli számra
int decimalToBinary (int decimal) {
    int size = 0, number = 0;
    int binary[32], tmp[32];

    while(decimal > 0) {
        tmp[size++] = decimal % 2;
        decimal /= 2;
    }

    for(int i = size-1, s = 0; i >= 0; i--) 
        binary[s++] = tmp[i];

    // int tömb átalakítása intiger típussá
    for(int j = 0; j < size; j++)
        number = 10 * number + binary[j];

    return number;
}

// átváltás tizes számrendszer beli számra
int binaryToDecimal (int binary) {
    int decimal = 0, rem = 0;
    int base = 2, power = 0;

    while (binary != 0) {
        rem = binary % 10;
        binary /= 10;
        decimal += rem * pow(base, power);
        ++power;
    }
    return decimal;
}

int main(int argc, char *argv[]) {
    FILE *file, *file2;
    char tmp[BlockSize], binaryArray[BlockSize];
    int input, output, array[BlockSize];

    // valamelyik parancssori argumentum hiányzik
    if(argc < 4) {
        write(2, " 1st argument: -t or -v\n 2nd argument: input file\n 3rd argument: output file\n", 77);
        return 1;
    } 

    // az első nem -t vagy -v
    if((strcmp(argv[1], "-t") != 0) && (strcmp(argv[1], "-v") != 0)) {
        write(2, " 1st argumentum: -t or -v\n", 26);
        return 1;
    } 

    input = open(argv[2], O_RDONLY);
    output = open(argv[3], O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);

    // bemenet megnyitása nem sikerült
    if(input < 0) {
        write(2, "Input file is not found.\n", 25);
        return 1;
    }

    // ha a kimenet megnyitása/létrehozása nem sikerült
    if(output < 0) {
        write(2, "There is problem with the output.\n", 33);
    }

    // titkosítás
    if(strcmp(argv[1], "-t") == 0) {
        file = fopen(argv[2], "r");
        file2 = fopen(argv[3], "w");
        fseek(file, 0, SEEK_END);
        int size = ftell(file);
        rewind(file);

        for(int k = 0; k < size; k++) 
            fread(tmp, 1, BlockSize, file);             

        for(int l = 0; l < size - 1; l++) 
            array[l] = (int) tmp[l];    

        printf("TXT\tASCII\tBinary\t\tSwap\t\tAppended\n");

        int binaryNumber = 0;
        for(int m = 0; m < size - 1; m++) {
            printf("%c\t%d\t", tmp[m], array[m]);
            printf("%d\t", binaryNumber = decimalToBinary(array[m]));
            char* swapped = swapBits(binaryNumber);
            printf("\t%s\t\t", swapped);
           
            // random bájt hozzáadása minden bájt után
            int size = strlen(swapped);
            char* appended = calloc(2 * size, sizeof(char));
            strcpy(appended, swapped);
            
            int location = 1;
            for(int n = 0; n < size; n++) {
                int number = rand()%2;
                appended[n * 2] = swapped[n];
                
                if(n <= size - 1)
                    appended[(n * 2) + 1] = number + '0';
            }
              
            printf("%s", appended);
            printf("\n");
            fprintf(file2, "%s\n", appended);
            free(appended);
        }

        fclose(file);
        fclose(file2);
    }

    // visszafejtés
    if(strcmp(argv[1], "-v") == 0) {
        file = fopen(argv[2], "r");
        file2 = fopen(argv[3], "w");
        fseek(file, 0, SEEK_END);
        int size = ftell(file);
        rewind(file);

        printf("Delete\t\tUnswap\t\tDecimal\t\tASCII\tTXT\n");

        // random bájt eltávolítása minden bájt után
        while(fgets(tmp, BlockSize, file)) {
            char *delete = calloc(size/2, sizeof(char));

            for (size_t i = 0, j = 0; i < strlen(tmp) - 1; i+= 2) {
                delete[j++] = tmp[i];
                printf("%c", tmp[i]);
            }
            
            printf("\t\t");

            // első és utolsó bit visszacserélése
            int elso = delete[strlen(delete)-1];
            delete[strlen(delete)-1] = delete[0];
            delete[0] = elso;

            printf("%s\t\t", delete);
            int number = atoi(delete);
            printf("%d\t", binaryToDecimal(number));
            printf("\t%d\t", binaryToDecimal(number));
            printf("%c", (char) binaryToDecimal(number));

            fprintf(file2, "%c\n", (char) binaryToDecimal(number));
            free(delete);
            printf("\n");
        }

        fclose(file);
        fclose(file2);
    }

    printf("\nThe finished encryption can be found in the output file.\n");

    close(input);
    close(output);

    return 0;
}
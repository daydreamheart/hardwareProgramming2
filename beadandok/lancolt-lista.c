// Láncolt lista implementálása

// Magyar Melinda Barbara

#include<stdio.h>
#include<stdlib.h>

// 2. feladat
typedef struct node {
    int data;
    struct node *next;
} node;

// 4. feladat
void AddNumber(node** first, int number) {
    node* current = *first;
    node* newNode = (node*)malloc(sizeof(node));
        
    newNode -> data = number;
    newNode -> next = NULL; // 3. feladat

    if (current == NULL)
        *first = newNode;
    else {
        while(current -> next != NULL) {
            current = current -> next;
        }

        current -> next = newNode;
    }
}

// 5. feladat
void Print(node *first) {
    while(first != NULL) {
        printf("%d ", (first -> data));
        first = first -> next;
    }
}

// 6. feladat
int Delete(node** first) {
    int number;
    node *current = *first;
    node *previous;

    if ((**first).next == NULL) {
        number = (**first).data;
        free(*first); // 7. feladat
        *first = NULL;
    }
    else {
        while (current -> next != NULL) {
            previous = current;
            current = current -> next;
            number = current -> data;
        }

        free(previous -> next); // 7. feladat
        previous -> next = NULL;
    }

    return number;
}

// 7. feladat
void FreeList (node* first) {
    node* current;

    while(first != NULL) {
        current = first;
        first = first -> next;
        free(current);
    }
}

// 8. feladat
// Példa bemenet: 1 2 3 4 5 0 
int main(int argc, char *argv[]) {
    int Number;
    struct node *First = NULL; // 1. feladat

    do {
        scanf("%d", &Number);
            
        if (Number == 0) 
            break;
        else 
            AddNumber(&First, Number);
       
    } while (1);

    printf("\nThe list: ");
    Print(First);
    printf("\n");

    int deleted = Delete(&First);
    printf("Deleted number: %d\n", deleted);

    printf("List after deleting one number: ");
    Print(First);
    printf("\n");

    int deleted2 = Delete(&First);
    printf("2nd deleted number: %d\n", deleted2);

    printf("List after deleting numbers: ");
    Print(First);
    printf("\n");

	FreeList(First); // 7. feladat

    return 0;
}

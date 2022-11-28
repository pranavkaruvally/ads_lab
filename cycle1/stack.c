#include <stdio.h>
#define MAX 100

int arr[MAX+1];
int *arr_beg = arr;
int *arr_end = &arr[MAX-1];
int *top = arr;

void push(int value) {
    top++;
    if (top > arr_end) {
        printf("Stack overflow\n");
        return ;
    }
    *top = value;
}

void pop() {
    if (top < arr_beg-1) {
        printf("Stack underflow\n");
        return ;
    }
    int del_val = *top;
    printf("Deleted value is %d\n", del_val);

    top--;
}

void traversal() {
    printf("The elements in the array are\n");
    for(int* i=arr_beg+1; i <= top; i++)
        printf("%d\t", *i);
    printf("\n");
}

void search() {
    int element;
    printf("Enter element to search: ");
    scanf("%d", &element);
    for (int* i=arr_beg+1; i <= top; i++)
        if (*i == element) {
            printf("Item present at %ld\n", (i - arr_beg - 1));
            return ;
        }
    printf("Item not present\n");
}

int main() {
    int data;
    char ch;

    printf("a -> push, d -> pop, t -> traversal, s -> search, q -> quit\n\n");
    printf("Enter option: ");
    while((ch = getchar()) != EOF) {
        switch(ch) {
            case 'a':
                printf("Enter a number: ");
                scanf("%d", &data);
                push(data);
                break;
            case 'd':
                pop();
                break;
            case 't':
                traversal();
                break;
            case 's':
                search();
                break;
            case 'q':
                return 0;
        }
    }

    return 0;
}

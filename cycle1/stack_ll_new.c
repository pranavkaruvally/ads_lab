#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef enum {PUSH='a', POP='d', DISP='v', QUIT='q'}Operation;

node* top = NULL;

void push(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;

    if (top == NULL) {
        top = newnode;
        top->next = NULL;
    }
    else if (newnode == NULL) /* malloc returns a NULL pointer if it fails to allocate memory */
        {
            printf("Stack overflow\n");
            free(newnode);
        }
    else {
        newnode->next = top;
        top = newnode;
    }
}

void pop() {
    if (top == NULL)
        printf("Stack underflow\n");
    else {
        node* temp = top;
        top = temp->next;
        
        int del_val = temp->data;
        printf("Deleted value is %d\n", del_val);

        free(temp);
    }
}

void update(void (*operation)(int), int data) {
    operation(data);
}

void display(void) {
    node* temp = top;
    node* disp_ll = NULL;
    while (temp != NULL) {
        node* newnode = malloc(sizeof(node));
        newnode->data = temp->data;
        temp = temp->next;
        newnode->next = disp_ll;
        disp_ll = newnode;
    }
    while (disp_ll != NULL) {
        printf("%d\t", disp_ll->data);
        node* temp = disp_ll;
        disp_ll = disp_ll->next;
        free(temp);
    }
    printf("\n");
}

int main() {
    char op;
    printf("Enter option: ");
    while((op = getchar()) != EOF) {
        switch(op) {
            case PUSH:
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                update(push, data);
                printf("Enter option: ");
                break;
            case POP:
                update(pop, -1);
                printf("Enter option: ");
                break;
            case DISP:
                display();
                printf("Enter option: ");
                break;
            case QUIT:
                return 0;
        }
    }

    return 0;
}


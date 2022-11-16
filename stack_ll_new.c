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

    if (top == NULL)
        top = newnode;
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

int main() {
    update(push, 5);
    update(push, 7);
    update(push, 8);
    update(pop, -1);
    update(push, 9);
    update(pop, -1);

    return 0;
}


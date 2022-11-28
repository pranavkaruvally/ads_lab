#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node *top = NULL;

void push(int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = val;
    if (top == NULL) {
        top = newnode;
        top->prev = NULL;
    }
    else {
        top->next = newnode;
        newnode -> prev = top;
        top = newnode;
    }
}

void pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return ;
    }
    struct node *del_node = top;
    int del_val = del_node->data;
    printf("Deleted value: %d\n", del_val);

    top = del_node->prev;
    free(del_node);
}

int main() {
    push(5);
    push(6);
    push(7);

    pop();
    pop();
    pop();
    pop();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *front=NULL, *rear=NULL;

void enqueue(int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    if (front == NULL) {
        front = rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue underflow\n");
        return;
    }
    struct node *del_node = front;
    int del_val = del_node->data;
    front = del_node->next;

    printf("Delete value is: %d\n", del_val);
    free(del_node);
}

int main() {
    char ch;
    int val;

    printf("e -> enqueue, d -> dequeue, q -> quit\n\n");
    printf("Enter option: ");

    while ((ch = getchar()) != EOF) {
        switch(ch) {
            case 'e':
                printf("Enter integer to insert: ");
                scanf("%d", &val);
                enqueue(val);
                printf("Enter option: ");
                break;
            case 'd':
                dequeue();
                printf("Enter option: ");
                break;
            case 'q':
                printf("Exiting...\n");
                exit(0);
        }
    }
}

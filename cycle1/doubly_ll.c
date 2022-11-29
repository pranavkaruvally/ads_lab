#include <stdio.h>
#include <stdlib.h>

typedef struct node* {
    int data;
    struct node* next;
    struct node* prev;
}node;

void insert(**node, int, unsigned int);
void delete(**node, unsigned int);
void search(*node, int);
void display(*node);

int main() {
    enum options = {ADD='a', DEL='d', SEARCH='s', DISP='p', QUIT='q'};
    char ch;
    int ele;
    unsigned int pos;

    node* head = malloc(sizeof(node));

    while ((ch=getchar()) != EOF) {
        switch(ch) {
            case ADD:
                printf("Enter element: ");
                scanf("%d", &ele);
                printf("Enter position: ");
                scanf("%u", &pos);
                insert(&head, ele, pos);
                printf("Enter option: ");
                break;
            case DEL:
                printf("Enter postion: ");
                scanf("%u", &pos);
                insert(&head, pos);
                printf("Enter option: ");
                break;
            case SEARCH:
                printf("Enter element: ");
                scanf("%d", &ele);
                search(head, ele);
                printf("Enter option: ");
                break;
            case DISP:
                display(head);
                break;
            case QUIT:
                return;
            default:
                printf("Options are a->add, d->delete, s->search, p->display, q->quit\n");
                printf("Enter option: ");
        }
    }

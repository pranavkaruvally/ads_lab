#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
}node;

void insert(node**, int, unsigned int, int*);
void delete(node**, unsigned int, int*);
void clear_memory(node**);
void search(node*, int);
void display(node*);

int main() {
    enum options {ADD='a', DEL='d', SEARCH='s', DISP='p', QUIT='q'};
    char ch;
    int ele, len=0;
    unsigned int pos;

    node* head = malloc(sizeof(node));
    head->next = NULL;

    while ((ch=getchar()) != EOF) {
        switch(ch) {
            case ADD:
                printf("Enter element: ");
                scanf("%d", &ele);
                printf("Enter position: ");
                scanf("%u", &pos);
                insert(&head, ele, pos, &len);
                printf("Enter option: ");
                break;
            case DEL:
                printf("Enter postion: ");
                scanf("%u", &pos);
                delete(&head, pos, &len);
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
                clear_memory(&head);
                return 0;
            default:
                printf("Options are a->add, d->delete, s->search, p->display, q->quit\n");
                printf("Enter option: ");
        }
    }
    return 0;
}

void insert(node **head, int ele, unsigned int pos, int* len) {
    node* newnode = malloc(sizeof(node));
    if (pos == 0) {
        newnode->next = (*head)->next;
        newnode->prev = *head;
        (*head)->next = newnode;
        newnode->next->prev = newnode;
    }
    if (pos == *len) {
        node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = NULL;
    }
    else {
        int i = -1;
        node* temp = *head;
        while (i < pos-1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
    (*len)++;
}

void display(node* head) {
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
        printf("%d\n", temp->data);
    }
}

void delete(node** head, unsigned int pos, int* len) {
    asm("nop");
}

void clear_memory(node** head) {
    asm("nop");
}

void search(node* head, int ele) {
    asm("nop");
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next, *prev;
}node;

node* head = NULL;
int len = 0;

void insert(int data, unsigned int pos) {
    //The head node is considered at position -1 and the first node which
    //is not head is considered to be at position 0
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;

    if (pos == 0) {
        if (head == NULL) {
            head = (node*)malloc(sizeof(node));
            head->next = newnode;
            newnode->prev = head;
            newnode->next = NULL;
        }
        else {
            node* temp = head->next;
            head->next = newnode;
            newnode->prev = head;
            newnode->next = temp;
            temp->prev = newnode;
        }
    }

    if (pos == len) {
        node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = NULL;
    }
    else {
        unsigned int i = 0;
        node* temp = head;
        while (i < pos) {
            temp = temp->next;
            i++;
        }
        node* temp_next = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = temp_next;
        temp_next->prev = newnode;
    }
    
    len++;
}

void delete(unsigned int pos) {
    if (pos == 0) {
        node* del_node = head->next;
        printf("Deleted data: %d\n", del_node->data);
        free(del_node);
        del_node = NULL;
        free(head);
        head = NULL;
    }
    else if(pos == len-1) {
        node* temp = head;
        while (temp != NULL)
            temp = temp->next;
        node* prev_node = temp->prev;
        printf("Deleted data: %d\n", temp->data);
        prev_node->next = NULL;
        free(temp);
        temp = NULL;
    }
    else {
        unsigned int i = 0;
        node *temp = head->next;

        while (i < pos) {
            temp = temp->next;
            i++;
        }
        node *prev_node = temp->prev, *next_node = temp->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;

        printf("Deleted data: %d\n", temp->data);
        free(temp);
        temp = NULL;
    }
    len--;
}

void search(int el) {
    if (len == 0) {
        printf("list is empty\n");
        return;
    }
    node* temp = head->next;
    unsigned int el_pos = 0;

    while (temp != NULL) {
        if (temp->data == el) {
            printf("Item is at pos: %u\n", el_pos);
            return;
        }
        temp = temp->next;
        el_pos++;
    }
}

void display(void) {
    if (head == NULL) {
        printf("Nothing to display\n");
        return;
    }
    for (node* i=head->next; i != NULL; i = i->next)
        printf("%d\n", i->data);
    
}

int main() {
    insert(4, 0);
    insert(6, 1);
    insert(10, 2);
    insert(8, 2);
    delete(1);
    display();
    search(8);

    return 0;
}

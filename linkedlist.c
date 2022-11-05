#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node head;
int list_len = 0;

void insertion(int data, int pos) {
    struct node newnode;
    newnode.data = data;

    if (pos == 0) {
        newnode.next = head.next;
        head.next = &newnode;
        list_len++;
    }
    else if (pos == list_len+1) {
        struct node *temp = &head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = &newnode;
        newnode.next = NULL;
    }
    else {
        int i = 0;
        struct node *temp = &head;

        while (i < pos-1) {
            if (temp->next != NULL && temp->next->next != NULL) {
                temp = temp->next;
                i++;
            }
            else {
                printf("Not as many positions in the linked list\n");
                return;
            }
        }
        newnode.next = temp->next;
        temp->next = &newnode;
    }
}

void deletion(int pos) {
    struct node *temp = head.next;
    if (temp == NULL)
        return;
    if (pos == 0) {
        head.next = temp->next;
        temp->next = NULL;
        free(temp);
    }
    else if(pos == list_len) {
        while (temp->next != NULL && temp->next->next != NULL) {
            temp = temp->next;
        }

        struct node *delete_node = temp->next;
        temp->next = NULL;
        free(delete_node);
    }
    else
    {
        int i = 0;
        if (pos > list_len) {
            printf("Position not within range\n");
            return;
        }
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        struct node *delete_node = temp->next;
        temp->next = delete_node->next;
        delete_node->next = NULL;
        free(delete_node);
    }
}

int main() {
    return 0;
}

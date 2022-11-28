#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node head;
int list_len = 0;

void insertion(int data, int pos) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if (pos == 0) {
        newnode->next = head.next;
        head.next = newnode;
    }
    else if (pos == list_len) {
        struct node *temp = &head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
    }
    else {
        int i = 0;
        struct node *temp = &head;

        while (i < pos) {
            if (temp->next != NULL) {
                temp = temp->next;
                i++;
            }
            else {
                printf("Not as many positions in the linked list\n");
                return;
            }
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    list_len++;
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
    else if(pos == list_len - 1) {
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

void traversal() {
    struct node *temp = &head;
    while (temp->next != NULL) {
        temp = temp->next;
        printf("%d\t", temp->data);
    printf("\n");
    }
}

int main() {
    char ch;
    do {
        printf("Enter option: ");
        scanf("%c", &ch);
        switch(ch) {
            case 'a':
                int val, pos;
                printf("Enter value: ");
                scanf("%d", &val);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertion(val, pos);
                break;
            case 'd':
                printf("Enter position: ");
                scanf("%d", &pos);
                deletion(pos);
                break;
            case 't':
                traversal();
                break;
            case 'q':
                return 0;
        }
    }while (ch != EOF);

    return 0;
}

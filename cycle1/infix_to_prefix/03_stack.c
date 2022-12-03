void push(node** top, char val) {
    node* newnode = (node*)malloc(sizeof(node));

    newnode->data = val;
    newnode->next = *top;
    *top = newnode;
}

char pop(node** top) {
    node* delnode = *top;

    char popped = delnode->data;
    *top = delnode->next;
    free(delnode);

    return popped;
}

char peek(node* top) {
    return top->data;
}

bool stack_is_empty(node* top) {
    if (top == NULL)
        return true;
    return false;
}

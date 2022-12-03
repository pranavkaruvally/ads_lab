//The push function for stack
void push(node** top, char val) {
    node* newnode = (node*)malloc(sizeof(node));

    newnode->data = val;
    newnode->next = *top;
    *top = newnode;
}

//The pop function for stack
char pop(node** top) {
    node* delnode = *top;

    char popped = delnode->data;
    *top = delnode->next;
    free(delnode);

    return popped;
}

//Peek function to display the top most element in a stack
char peek(node* top) {
    return top->data;
}

//Function to check whether the stack is empty
bool stack_is_empty(node* top) {
    if (top == NULL)
        return true;
    return false;
}

//The push function for stack
void push(node** top, const char val) {
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
static inline char peek(const node* top) {
    return top->data;
}

//Function to check whether the stack is empty
static inline bool stack_is_empty(const node* top) {
    return (top == NULL) ? true : false;
}

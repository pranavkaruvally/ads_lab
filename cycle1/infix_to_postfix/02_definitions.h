//node used for the implementation of stack using linked list
typedef struct node
{
    char data;
    struct node* next;
}
node;

char* input = "infix.txt"; //Input file
char* output = "postfix.txt"; //Output file


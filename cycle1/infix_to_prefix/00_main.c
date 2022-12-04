#include <stdio.h>    
#include <stdlib.h>    
#include <stdbool.h>    
#include"01_functions.c"    
#include "02_definitions.h"    
#include "03_stack.c"

int main() {
    node* top = NULL; //Stack to be used
    char* infix = read_infix(input); //Infix expression
    char ch, op, temp, postfix[1000];
    int i=0;

    while ((ch = *infix++) != '\0') {
        //First we avoid white spaces
        if (ch == ' ')
            continue;

        //If we see a number we print in out
        if (is_num(ch)) {
            //A number maybe a multidigit number
            //So we print it out until ch is not a number
            while (is_num(ch)) {
                postfix[i++] = ch;
                ch = *infix++;
            }
            infix--; //Since last infix++ was unnecessary
            postfix[i++] = ' ';
            continue;
        }

        //we push operators naively when
        //stack is empty or when ch is an opening bracket
        //and when stack is not empty, if the scanned operator has a higher precedence
        //than that of the operator at the top of the stack, push the operator into the stack
        //when ch is '^', scanned '^' has higher priority even when top->data is '^'
        //due to the right associative nature of '^'
        if (top == NULL || ch == '(' || ch == '^') {
            push(&top, ch);
            continue;
        } else {
            op = peek(top);
            if (precedence(ch) > precedence(op)) {
                push(&top, ch);
                continue;
            }
        }

        //when we encounter a closing bracket all operators up until
        //opening bracket is popped from stack into the output
        if (ch == ')') {
            while ((temp = pop(&top)) != '(') {
                postfix[i++] = temp;
                postfix[i++] = ' ';
            }
            continue;
        }
        //operator is popped until the precedence of the operator in the stack is smaller
        //when compared with the scanned operator or until the stack is empty
        op = peek(top);
        while (precedence(ch) <= precedence(op)) {
            postfix[i++] = op;
            postfix[i++] = ' ';
            pop(&top);
            if (top == NULL)
                break;
            op = peek(top);
        }
        //Then the scanned operator is pushed back into the stack
        push(&top, ch);
    }
    //After the infix expression is completely processed all that inside the stack is popped
    while (top != NULL) {
        postfix[i++] = pop(&top);
        postfix[i++] = ' ';
    }
    postfix[i] = '\0';
    write_postfix(postfix, output);

    return 0;
}

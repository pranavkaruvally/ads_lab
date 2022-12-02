#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "01_functions.c"
#include "02_definitions.h"
#include "03_stack.c"

int main() {
    node* top = NULL;
    char* infix = read_infix("infix.txt");
    char ch, op, temp, postfix[1000];
    int i=0;

    while ((ch = *infix++) != '\0') {
        if (is_num(ch)) {
            while (is_num(ch)) {
                postfix[i++] = ch;
                ch = *infix++;
            }
            infix--;
            postfix[i++] = ' ';
            continue;
        }
        
        if (top == NULL) {
            push(&top, ch);
            continue;
        }
        else {
            if (ch == '(') {
                push(&top, ch);
                continue;
            }
            if (ch == ')') {
                while ((temp = pop(&top)) != '(') {
                    postfix[i++] = temp;
                    postfix[i++] = ' ';
                }
                continue;
            }
            op = top->data;
            if (op == '(') {
                push(&top, ch);
                continue;
            }
            if (precedence(ch) > precedence(op)) {
                push(&top, ch);
                continue;
            }
            else {
                postfix[i++] = pop(&top);
                postfix[i++] = ' ';
            }
        }
    }
    postfix[i] = '\0';

    printf("%s\n", postfix);

    return 0;
}

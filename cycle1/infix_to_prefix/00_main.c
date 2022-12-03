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

    //printf("%c\n", infix[7]);

    while ((ch = *infix++) != '\0') {
        postfix[i] = '\0';
        for (int j=0; postfix[j] != '\0'; j++)
            printf("%c", postfix[j]);
        if (top != NULL)
            printf("\ttop: %c\tch: %c", top->data, ch);
        printf("\n");
        if (ch == ' ')
            continue;

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
                while (precedence(op) != 0 && precedence(ch) <= precedence(op)) {
                    if (ch == '^' && op == '^') {
                        push(&top, ch);
                        continue;
                    }
                    postfix[i++] = op;
                    postfix[i++] = ' ';
                    pop(&top);
                    if (top == NULL) {
                        push(&top, ch);
                        continue;
                    }
                    op = top->data;
                }
                //postfix[i++] = pop(&top);
                //postfix[i++] = ' ';
                //printf("ch: %c\n", ch);
                push(&top, ch);
            }
        }
    }
    while (top != NULL) {
        postfix[i++] = pop(&top);
        postfix[i++] = ' ';
    }
    postfix[i] = '\0';

    write_postfix(postfix, "postfix.txt");

    return 0;
}

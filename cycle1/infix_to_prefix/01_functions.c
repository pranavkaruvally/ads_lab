#define EXP_SIZE 1000

char* read_infix(char* filename) {
    char* expression = (char*)calloc(EXP_SIZE, sizeof(char));
    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("No such file!!!\n");
        exit(0);
    }
    fgets(expression, EXP_SIZE, fptr);
    fclose(fptr);

    return expression;
}

void write_postfix(char* expression, char* filename) {
    FILE *fptr = fopen(filename, "w");
    fprintf(fptr, "%s", expression);
    fclose(fptr);
    //free(expression);
}

int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }

    return 0;
}

bool is_right_associative(char ch) {
    return (ch == '^') ? true : false;
}

bool is_num(char n) {
    char num = n - '0';
    if (0 <= num && num <= 9)
        return true;
    return false;
}

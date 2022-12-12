#define EXP_SIZE 1000

//A function to read input from the required file
char* read_infix(const char* filename) {
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

//A function to write output into a particular file
void write_postfix(const char* expression, const char* filename) {
    FILE *fptr = fopen(filename, "w");
    fprintf(fptr, "%s", expression);
    fclose(fptr);
    //free(expression);
}

//A function that denotes the precedence of the operators
int precedence(const char ch) {
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

//Function which checks whether the scanned character is a number
bool is_num(const char n) {
    char num = n - '0';
    bool condition = (0 <= num && num <= 9);
    return condition ? true : false;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define BITLENGTH 64

int bit_length(char* a) {
    int a_len = 0;

    while (*a++ != '\0')
        a_len++;

    return a_len;
}

bool check_length(char* a, char* b) {
    return (bit_length(a) == bit_length(b));
}

int* string_to_int(char* a) {
    int len = bit_length(a);
    int *int_bitstring = (int*)calloc(len, sizeof(int));

    while (*a != '\0')
        *int_bitstring++ = (*a++ == '1') ? 1 : 0;

    return int_bitstring - len;
}

int* set_union(char* a, char* b) {
    if (!check_length(a, b)) {
        printf("Incompatible length\n");
        exit(0);
    }
    
    int len = bit_length(a), *bitint_a = string_to_int(a), *bitint_b = string_to_int(b);
    int *result = (int*)calloc(len, sizeof(int));
    
    for (int i=0; i<len; i++) {
        result[i] = (*bitint_a || *bitint_b);
        bitint_a++; bitint_b++;
    }

    return result;
}

int* set_intersection(char* a, char* b) {
    if (!check_length(a, b)) {
        printf("Incompatible length\n");
        exit(0);
    }
    
    int len = bit_length(a), *bitint_a = string_to_int(a), *bitint_b = string_to_int(b);
    int *result = (int*)calloc(len, sizeof(int));
    
    for (int i=0; i<len; i++) {
        result[i] = (*bitint_a && *bitint_b);
        bitint_a++; bitint_b++;
    }

    return result;
}

int* set_compliment(char* a) {
    int len = bit_length(a);
    int *result = (int*)calloc(len, sizeof(int));

    for (int i=0; i<len; i++) {
        result[i] = (*a++ == '1') ? 0 : 1;
    }

    return result;
}

int* set_difference(char* a, char* b) {
    if (!check_length(a, b)) {
        printf("Incompatible length\n");
        exit(0);
    }
    
    int len = bit_length(a), *bitint_a = string_to_int(a), *comp = set_compliment(b);
    int *result = (int*)calloc(len, sizeof(int));
    
    for (int i=0; i<len; i++) {
        result[i] = (*bitint_a && *comp);
        bitint_a++; comp++;
    }

    return result;
}

int main() {
    char* a = (char *)malloc(BITLENGTH*sizeof(char));
    char* b = (char *)calloc(BITLENGTH, sizeof(char));

    printf("Enter bit string one: ");
    scanf("%s", a);
    printf("Enter bit string two: ");
    scanf("%s", b);


    int* union_res = set_union(a, b);
    int* intersection_res = set_intersection(a, b);
    int* difference_res = set_difference(a, b);

    printf("Union between %s and %s: ", a, b);
    for(int i=0; i<6; i++)
        printf("%d", union_res[i]);
    printf("\n");
    
    printf("Intersection between %s and %s: ", a, b);
    for(int i=0; i<6; i++)
        printf("%d", intersection_res[i]);
    printf("\n");

    printf("Difference between %s and %s: ", a, b);
    for(int i=0; i<6; i++)
        printf("%d", difference_res[i]);
    printf("\n");
    
    return 0;
}

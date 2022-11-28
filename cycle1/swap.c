#include <stdio.h>
#define MAX 100

void swap(int*, int*, int, int);

int main() {
    int a[MAX], b[MAX], m, n;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &m);
    printf("Enter the elements in the array: ");
    for (int i=0; i<m; i++)
        scanf("%d", &a[i]);

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n);
    printf("Enter the elements in the array: ");
    for (int i=0; i<n; i++)
        scanf("%d", &b[i]);

    swap(a, b, m, n);

    printf("Elements in first array after swapping\n");
    for(int i=0; i<n; i++)
        printf("%d\t", a[i]);
    printf("\n");

    printf("Elements in second array after swapping\n");
    for(int i=0; i<m; i++)
        printf("%d\t", b[i]);
    printf("\n");
    
    return 0;
}

void swap(int* a, int* b, int m, int n) {
    int temp[MAX];
    
    for (int i=0; i<m; i++)
        temp[i] = a[i];
    for (int i=0; i<n; i++)
        a[i] = b[i];
    for(int i=0; i<m; i++)
        b[i] = temp[i];
}

#include <stdio.h>
#define MAX 100

int main() {
    int arr[MAX], len, ele, pos=-1;

    printf("Enter the number of elements: ");
    scanf("%d", &len);
    printf("Enter the elements: ");
    for(int i=0; i<len; i++)
        scanf("%d", &arr[i]);
    printf("Enter the element to search: ");
    scanf("%d", &ele);

    for (int i=0; i<len; i++)
        if (ele == arr[i]) {
            pos = i;
            break;
        }
    if (pos == -1)
        printf("Item not found\n");
    else
        printf("Item found at position %d\n", pos);

    return 0;
}

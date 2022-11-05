#include <stdio.h>
#define MAX 100

void merge_1(int arr1[], int arr2[], int m, int n);
void merge_2(int arr1[], int arr2[], int m, int n);

int main() {
    int arr1[MAX], arr2[MAX], m, n;
    
    printf("Enter the number of elements in first array: ");
    scanf("%d", &m);
    printf("Enter the array elements: ");
    for(int i=0; i<m; i++)
        scanf("%d", &arr1[i]);
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    for(int i=0; i<n; i++)
        scanf("%d", &arr2[i]);

    printf("The end-to-end merge is\n");
    merge_1(arr1, arr2, m, n);
    printf("The second type of merge is\n");
    merge_2(arr1, arr2, m, n);
    printf("\n");

    return 0;
}

void merge_1(int arr1[], int arr2[], int m, int n)
{
    int arr[m+n];
    for (int i=0; i<m; i++)
        arr[i] = arr1[i];
    for(int i=0; i<n; i++)
        arr[m+i] = arr2[i];

    for(int i=0; i<m+n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void merge_2(int arr1[], int arr2[], int m, int n) {
    int arr[m+n];
    int i=0, j=0;

    while (i+j < m+n) {
        if (i >= m) {
            arr[i+j] = arr2[j];
            j++;
        }
        else if (j >= n) {
            arr[i+j] = arr1[i];
            i++;
        }
        else {
            if ((i+j)%2 == 0) {
                arr[i+j] = arr1[i];
                i++;
            }
            else {
                arr[i+j] = arr2[j];
                j++;
            }
        }
    }

    for(int i=0; i<m+n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

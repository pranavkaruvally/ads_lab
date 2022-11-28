#include <stdio.h>
#define MAX 250


int partition(int arr[], int low, int high);
void quicksort(int arr[], int low, int high);

int main() {
    int arr[MAX], len;

    printf("Enter length of the array: ");
    scanf("%d", &len);
    printf("Enter array: ");
    for(int i=0; i<len; i++)
        scanf("%d", &arr[i]);

    quicksort(arr, 0, len-1);

    printf("Sorted array is: ");
    for(int i=0; i<len; i++)
        printf("%d\t", arr[i]);
    printf("\n");

    return 0;
}

int partition(int arr[], int low, int high)
{
    int ele = arr[high];
    int i = low - 1;

    for(int j=low; j<high; j++) {
        if (arr[j] <= ele) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

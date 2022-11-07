#include <stdio.h>
#define LIM 100
#define max(a, b) (a > b) ? a : b

int arr[LIM], front=-1, rear=-1;

void enqueue(int data) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
        arr[rear] = data;
    } else if (rear == LIM-1) {
        printf("Queue overflow\n");
        return ;
    } else {
        rear++;
        arr[rear] = data;
    }
}

void dequeue() {
    if (front > rear) {
        printf("Queue underflow\n");
        return ;
    } else {
        int del_item = arr[front];
        printf("Deleted item is %d\n", del_item);
        front++;
    }
}

void traversal() {
    for (int i=front; i <= rear; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int main() {
    enqueue(5);
    enqueue(6);
    enqueue(max(8, 10));
    enqueue(17);
    dequeue();
    enqueue(19);
    enqueue(20);
    dequeue();
    traversal();

    return 0;
}

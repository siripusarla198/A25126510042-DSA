/*A service centre uses a fixed-size request buffer in which released positions must be reused.
Write a C program to implement a Circular Queue using an array with insertion, deletion, display,
overflow and underflow operations. Demonstrate that positions freed after deletion can be reused
for new requests.*/
#include <stdio.h>
void enqueue(int queue[], int *front, int *rear, int size, int value) {
    if ((*rear + 1) % size == *front) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (*front == -1) {
        *front = 0;
    }
    *rear = (*rear + 1) % size;
    queue[*rear] = value;
    printf("Inserted %d into the queue.\n", value);
}
void dequeue(int queue[], int *front, int *rear, int size) {
    if (*front == -1) {
        printf("Queue Underflow! Cannot delete from an empty queue.\n");
        return;
    }
    int removedValue = queue[*front];
    if (*front == *rear) {
        *front = -1;
        *rear = -1;
    } else {
        *front = (*front + 1) % size;
    }
    printf("Deleted %d from the queue.\n", removedValue);
}
void display(int queue[], int front, int rear, int size) {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % size;
    }
    printf("\n");
}
int main() {
    int size;
    printf("Enter the size of the circular queue: ");
    scanf("%d", &size);
    int queue[size];
    int front = -1, rear = -1;
    int choice, value;
    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(queue, &front, &rear, size, value);
                break;
            case 2:
                dequeue(queue, &front, &rear, size);
                break;
            case 3:
                display(queue, front, rear, size);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}
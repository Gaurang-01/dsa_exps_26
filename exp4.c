#include <stdio.h>
#define SIZE 5  // maximum size of circular queue

int queue[SIZE];
int front = -1, rear = -1;

// Check if queue is full
int isFull() {
    return (front == (rear + 1) % SIZE);
}

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Enqueue operation (Insertion)
void enqueue(int x) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", x);
        return;
    }
    if (isEmpty()) { // first element
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = x;
    printf("%d enqueued to the queue.\n", x);
}

// Dequeue operation (Deletion)
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to dequeue.\n");
        return;
    }
    int removed = queue[front];
    if (front == rear) {
        // Only one element was present
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    printf("%d dequeued from the queue.\n", removed);
}

// Display Queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting Circular Queue Program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

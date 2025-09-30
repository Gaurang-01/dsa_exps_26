#include <stdio.h>
#define SIZE 100  // maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue operation (Insertion)
void enqueue(int x) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert %d\n", x);
        return;
    }
    if (front == -1) { // first element
        front = 0;
    }
    rear++;
    queue[rear] = x;
    printf("%d enqueued to the queue.\n", x);
}

// Dequeue operation (Deletion)
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No elements to dequeue.\n");
        return;
    }
    int removed = queue[front];
    front++;
    printf("%d dequeued from the queue.\n", removed);
    // Optional: reset pointers if queue becomes empty
    if (front > rear) {
        front = rear = -1;
    }
}

// Display Queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Linear Queue Menu ---\n");
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
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Function to create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insertion at beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        struct Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;
        head = newNode;
    }
    printf("%d inserted at beginning.\n", value);
}

// Insertion at end
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        struct Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
    printf("%d inserted at end.\n", value);
}

// Delete a node
void deleteNode(int value) {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct Node* current = head;

    // Search node with value
    do {
        if (current->data == value) {
            // Single node case
            if (current->next == current && current->prev == current) {
                free(current);
                head = NULL;
            }
            else {
                struct Node* prevNode = current->prev;
                struct Node* nextNode = current->next;

                prevNode->next = nextNode;
                nextNode->prev = prevNode;

                if (current == head) {
                    head = nextNode;  // move head
                }
                free(current);
            }
            printf("%d deleted from list.\n", value);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("Node %d not found.\n", value);
}

// Display forward
void displayForward() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Forward: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Display backward
void displayBackward() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct Node* last = head->prev;
    struct Node* temp = last;
    printf("Backward: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != last);
    printf("(back to last)\n");
}

// Main menu
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Display Forward\n");
        printf("5. Display Backward\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 4:
                displayForward();
                break;
            case 5:
                displayBackward();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

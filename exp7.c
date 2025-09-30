#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insertion at beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
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
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("%d inserted at end.\n", value);
}

// Deletion
void deleteNode(int value) {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    // Deleting head
    if (head->data == value) {
        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        if (head->next == head) { // only one node
            free(head);
            head = NULL;
        } else {
            last->next = head->next;
            struct Node* temp = head;
            head = head->next;
            free(temp);
        }
        printf("%d deleted from list.\n", value);
        return;
    }

    // Other node
    do {
        prev = current;
        current = current->next;
        if (current->data == value) {
            prev->next = current->next;
            free(current);
            printf("%d deleted from list.\n", value);
            return;
        }
    } while (current != head);

    printf("Node %d not found.\n", value);
}

// Display
void display() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Main menu
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Node\n");
        printf("4. Display\n");
        printf("5. Exit\n");
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
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

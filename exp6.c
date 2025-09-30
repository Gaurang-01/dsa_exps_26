
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define SONG_LEN 50

// Stack to store songs
char stack[MAX][SONG_LEN];
int top = -1;

// Push new song
void push(char song[]) {
    if (top == MAX - 1) {
        printf("Playlist is full!\n");
    } else {
        top++;
        strcpy(stack[top], song);
        printf("Now playing: %s\n", stack[top]);
    }
}

// Pop (Go back to previous song)
void pop() {
    if (top == -1) {
        printf("No songs in history!\n");
    } else {
        printf("Stopping: %s\n", stack[top]);
        top--;
        if (top >= 0) {
            printf("Now playing: %s\n", stack[top]);
        } else {
            printf("No song is playing now.\n");
        }
    }
}

// Peek (Show current song)
void peek() {
    if (top == -1) {
        printf("No song is currently playing.\n");
    } else {
        printf("Current song: %s\n", stack[top]);
    }
}

// Display playlist history
void display() {
    if (top == -1) {
        printf("No songs in playlist history.\n");
    } else {
        printf("Playlist History:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d. %s\n", (top - i + 1), stack[i]);
        }
    }
}

int main() {
    int choice;
    char song[SONG_LEN];

    while (1) {
        printf("\n--- Music Player Menu ---\n");
        printf("1. Play New Song (Push)\n");
        printf("2. Go Back to Previous Song (Pop)\n");
        printf("3. Show Current Song (Peek)\n");
        printf("4. Show Playlist History (Display)\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear input buffer

        switch (choice) {
            case 1:
                printf("Enter song name: ");
                fgets(song, SONG_LEN, stdin);
                song[strcspn(song, "\n")] = '\0'; // remove newline
                push(song);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
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

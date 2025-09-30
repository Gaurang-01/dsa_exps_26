#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert string to lowercase (for case-insensitive comparison)
void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Binary Search function
int binarySearch(char playlist[][50], int n, char target[]) {
    int low = 0, high = n - 1;
    char targetLower[50];
    strcpy(targetLower, target);
    toLowerCase(targetLower);

    while (low <= high) {
        int mid = (low + high) / 2;

        char midSong[50];
        strcpy(midSong, playlist[mid]);
        toLowerCase(midSong);

        int cmp = strcmp(targetLower, midSong);

        if (cmp == 0) {
            return mid; // song found
        } else if (cmp < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1; // not found
}

int main() {
    int n;
    printf("Enter number of songs: ");
    scanf("%d", &n);

    char playlist[n][50];
    printf("Enter songs in alphabetical order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", playlist[i]); // reads single word (no spaces)
    }

    char songToSearch[50];
    printf("Enter song to search: ");
    scanf("%s", songToSearch);

    int pos = binarySearch(playlist, n, songToSearch);

    if (pos != -1) {
        printf("Song '%s' found at position %d.\n", songToSearch, pos + 1);
    } else {
        printf("Song '%s' not found in playlist.\n", songToSearch);
    }

    return 0;
}

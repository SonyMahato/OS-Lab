#include <stdio.h>
#include <stdlib.h>

// Function to simulate FIFO page replacement algorithm
void fifo(int pages[], int n, int capacity) {
    int pageFaults = 0;
    int frame[capacity];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            if ((rear + 1) % capacity == front) {
                front = (front + 1) % capacity;
            }

            frame[rear] = pages[i];
            rear = (rear + 1) % capacity;
            pageFaults++;
        }
    }

    printf("FIFO Page Replacement:\n");
    printf("Number of page faults: %d\n", pageFaults);
}

// Function to simulate LRU page replacement algorithm
void lru(int pages[], int n, int capacity) {
    int pageFaults = 0;
    int frame[capacity];
    int counter[capacity];

    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
        counter[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int found = 0;
        int leastUsed = 0;

        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                counter[j] = i;
                break;
            }
        }

        if (!found) {
            leastUsed = 0;
            for (int j = 1; j < capacity; j++) {
                if (counter[j] < counter[leastUsed]) {
                    leastUsed = j;
                }
            }

            frame[leastUsed] = pages[i];
            counter[leastUsed] = i;
            pageFaults++;
        }
    }

    printf("LRU Page Replacement:\n");
    printf("Number of page faults: %d\n", pageFaults);
}

// Function to simulate Optimal page replacement algorithm
void optimal(int pages[], int n, int capacity) {
    int pageFaults = 0;
    int frame[capacity];
    int nextUse[capacity];

    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
        nextUse[i] = n;
    }

    for (int i = 0; i < n; i++) {
        int found = 0;
        int replaceIndex = -1;

        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }

            if (frame[j] == -1) {
                replaceIndex = j;
                break;
            }

            if (nextUse[j] > nextUse[replaceIndex]) {
                replaceIndex = j;
            }
        }

        if (!found) {
            frame[replaceIndex] = pages[i];
            nextUse[replaceIndex] = i;
            pageFaults++;
        }
    }

    printf("Optimal Page Replacement:\n");
    printf("Number of page faults: %d\n", pageFaults);
}

int main() {
    int n, capacity;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter the page references:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the capacity of page frames: ");
    scanf("%d", &capacity);

    fifo(pages, n, capacity);
    lru(pages, n, capacity);
    optimal(pages, n, capacity);

    return 0;
}

#include <stdio.h>


// FIFO Page Replacement
int fifo_page_replacement(int pages[], int n, int memory_size) {
    int memory[memory_size];
    int page_faults = 0, hits = 0, misses = 0, index = 0;


    // Initialize memory frames to -1 (indicating empty)
    for (int i = 0; i < memory_size; i++) {
        memory[i] = -1;
    }


    for (int i = 0; i < n; i++) {
        int found = 0;
        // Check if the page is already in memory
        for (int j = 0; j < memory_size; j++) {
            if (memory[j] == pages[i]) {
                found = 1;
                hits++;
                printf("Page %d: HIT\n", pages[i]);
                break;
            }
        }
        // If not found, page fault occurs (miss)
        if (!found) {
            memory[index] = pages[i];
            index = (index + 1) % memory_size;  // FIFO Replacement
            page_faults++;
            misses++;
            printf("Page %d: MISS (Page Fault)\n", pages[i]);
        }


        // Display current memory state
        printf("Memory: ");
        for (int j = 0; j < memory_size; j++) {
            if (memory[j] != -1)
                printf("%d ", memory[j]);
            else
                printf("- ");
        }
        printf("\n");
    }


    // Print total hits, misses, and page faults
    printf("Total Hits (FIFO): %d\n", hits);
    printf("Total Misses (FIFO): %d\n", misses);
    printf("Total Page Faults (FIFO): %d\n", page_faults);


    return page_faults;
}


// Find the least recently used page for LRU
int find_lru(int time[], int n) {
    int i, minimum = time[0], pos = 0;


    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}


// LRU Page Replacement
int lru_page_replacement(int pages[], int n, int memory_size) {
    int memory[memory_size], time[memory_size];
    int page_faults = 0, hits = 0, misses = 0, counter = 0, i, j, pos, found;


    // Initialize memory and time arrays
    for (i = 0; i < memory_size; ++i) {
        memory[i] = -1;
    }


    for (i = 0; i < n; ++i) {
        found = 0;
        // Check if the page is already in memory
        for (j = 0; j < memory_size; ++j) {
            if (memory[j] == pages[i]) {
                counter++;
                time[j] = counter;  // Update time for the page
                hits++;
                found = 1;
                printf("Page %d: HIT\n", pages[i]);
                break;
            }
        }


        if (!found) {  // Page Fault occurs (miss)
            if (i < memory_size) {
                memory[i] = pages[i];
                time[i] = counter;
            } else {
                pos = find_lru(time, memory_size);  // Find least recently used page
                memory[pos] = pages[i];
                time[pos] = counter;
            }
            page_faults++;
            misses++;
            printf("Page %d: MISS (Page Fault)\n", pages[i]);
        }


        // Display current memory state
        printf("Memory: ");
        for (j = 0; j < memory_size; ++j) {
            if (memory[j] != -1)
                printf("%d ", memory[j]);
            else
                printf("- ");
        }
        printf("\n");
    }


    // Print total hits, misses, and page faults
    printf("Total Hits (LRU): %d\n", hits);
    printf("Total Misses (LRU): %d\n", misses);
    printf("Total Page Faults (LRU): %d\n", page_faults);


    return page_faults;
}


// Find the optimal page to replace for OPT
int find_optimal(int pages[], int memory[], int n, int memory_size, int current_index) {
    int farthest = current_index, pos = -1;


    for (int i = 0; i < memory_size; i++) {
        int j;
        for (j = current_index; j < n; j++) {
            if (memory[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == n) return i;  // If page not found, choose this page
    }
    return (pos == -1) ? 0 : pos;
}


// OPT Page Replacement
int opt_page_replacement(int pages[], int n, int memory_size) {
    int memory[memory_size];
    int page_faults = 0, hits = 0, misses = 0;


    for (int i = 0; i < memory_size; i++) {
        memory[i] = -1;
    }


    for (int i = 0; i < n; i++) {
        int found = 0;
        // Check if the page is already in memory
        for (int j = 0; j < memory_size; j++) {
            if (memory[j] == pages[i]) {
                found = 1;
                hits++;
                printf("Page %d: HIT\n", pages[i]);
                break;
            }
        }


        if (!found) {  // Page fault occurs (miss)
            if (i < memory_size) {
                memory[i] = pages[i];
            } else {
                int pos = find_optimal(pages, memory, n, memory_size, i + 1);
                memory[pos] = pages[i];
            }
            page_faults++;
            misses++;
            printf("Page %d: MISS (Page Fault)\n", pages[i]);
        }


        // Display current memory state
        printf("Memory: ");
        for (int j = 0; j < memory_size; j++) {
            if (memory[j] != -1)
                printf("%d ", memory[j]);
            else
                printf("- ");
        }
        printf("\n");
    }


    // Print total hits, misses, and page faults
    printf("Total Hits (OPT): %d\n", hits);
    printf("Total Misses (OPT): %d\n", misses);
    printf("Total Page Faults (OPT): %d\n", page_faults);


    return page_faults;
}


int main() {
    int choice;
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int memory_size = 3;
    int n = sizeof(pages) / sizeof(pages[0]);


    printf("Choose Page Replacement Algorithm:\n");
    printf("1. FIFO\n");
    printf("2. LRU\n");
    printf("3. OPT\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);


    int faults;


    if (choice == 1) {
        faults = fifo_page_replacement(pages, n, memory_size);
    } else if (choice == 2) {
        faults = lru_page_replacement(pages, n, memory_size);
    } else if (choice == 3) {
        faults = opt_page_replacement(pages, n, memory_size);
    } else {
        printf("Invalid choice!\n");
    }


    return 0;
}

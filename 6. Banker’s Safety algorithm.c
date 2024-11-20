#include <stdio.h>
#include <stdbool.h>


#define MAX_PROCESSES 5
#define MAX_RESOURCES 3


int allocation[MAX_PROCESSES][MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
bool finish[MAX_PROCESSES] = {false};


// Function to check if a process can be allocated resources
bool canAllocate(int process) {
    for (int i = 0; i < MAX_RESOURCES; i++) {
        if (need[process][i] > available[i]) {
            return false;
        }
    }
    return true;
}


// Function to calculate the Need matrix
void calculateNeed() {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}


// Banker's Safety algorithm to check if the system is in a safe state
bool isSafeState() {
    int work[MAX_RESOURCES];
    for (int i = 0; i < MAX_RESOURCES; i++) {
        work[i] = available[i];
    }


    int safeSequence[MAX_PROCESSES];
    int count = 0;


    while (count < MAX_PROCESSES) {
        bool found = false;
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (!finish[i] && canAllocate(i)) {
                for (int j = 0; j < MAX_RESOURCES; j++) {
                    work[j] += allocation[i][j];
                }
                safeSequence[count++] = i;
                finish[i] = true;
                found = true;
            }
        }
        if (!found) {
            printf("The system is not in a safe state.\n");
            return false;
        }
    }


    printf("The system is in a safe state.\nSafe Sequence: ");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
    return true;
}


int main() {
    // Initialize allocation matrix
    allocation[0][0] = 0; allocation[0][1] = 1; allocation[0][2] = 0;
    allocation[1][0] = 2; allocation[1][1] = 0; allocation[1][2] = 0;
    allocation[2][0] = 3; allocation[2][1] = 0; allocation[2][2] = 2;
    allocation[3][0] = 2; allocation[3][1] = 1; allocation[3][2] = 1;
    allocation[4][0] = 0; allocation[4][1] = 0; allocation[4][2] = 2;


    // Initialize maximum matrix
    max[0][0] = 7; max[0][1] = 5; max[0][2] = 3;
    max[1][0] = 3; max[1][1] = 2; max[1][2] = 2;
    max[2][0] = 9; max[2][1] = 0; max[2][2] = 2;
    max[3][0] = 2; max[3][1] = 2; max[3][2] = 2;
    max[4][0] = 4; max[4][1] = 3; max[4][2] = 3;


    // Initialize available resources
    available[0] = 3;
    available[1] = 3;
    available[2] = 2;


    // Calculate the need matrix
    calculateNeed();


    // Check for safe state
    isSafeState();


    return 0;
}

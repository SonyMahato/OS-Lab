  #include <stdio.h>

// Structure to represent a process
struct Process {
    int pid;      // Process ID
    int priority; // Priority (0 for system processes, 1 for user processes)
    int burstTime; // Burst time of the process
};

// Function to execute a process
void executeProcess(struct Process p) {
    printf("Executing Process %d with burst time %d\n", p.pid, p.burstTime);
}

int main() {
    int numSystemProcesses, numUserProcesses;

    printf("Enter the number of system processes: ");
    scanf("%d", &numSystemProcesses);

    printf("Enter the number of user processes: ");
    scanf("%d", &numUserProcesses);

    struct Process systemProcesses[numSystemProcesses];
    struct Process userProcesses[numUserProcesses];

    // Input details for system processes
    printf("\nEnter details for system processes:\n");
    for (int i = 0; i < numSystemProcesses; i++) {
        printf("Enter process ID for system process %d: ", i + 1);
        scanf("%d", &systemProcesses[i].pid);

        systemProcesses[i].priority = 0;

        printf("Enter burst time for system process %d: ", i + 1);
        scanf("%d", &systemProcesses[i].burstTime);
    }

    // Input details for user processes
    printf("\nEnter details for user processes:\n");
    for (int i = 0; i < numUserProcesses; i++) {
        printf("Enter process ID for user process %d: ", i + 1);
        scanf("%d", &userProcesses[i].pid);

        userProcesses[i].priority = 1;

        printf("Enter burst time for user process %d: ", i + 1);
        scanf("%d", &userProcesses[i].burstTime);
    }

    // Execute system processes first (higher priority)
    printf("\nExecuting System Processes:\n");
    for (int i = 0; i < numSystemProcesses; i++) {
        executeProcess(systemProcesses[i]);
    }

    // Execute user processes
    printf("\nExecuting User Processes:\n");
    for (int i = 0; i < numUserProcesses; i++) {
        executeProcess(userProcesses[i]);
    }

    return 0;
}

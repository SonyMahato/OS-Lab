#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int processes, resources,choice,a,b,temp,numr,f=0;
int total_resources[MAX_RESOURCES],total[MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
bool finish[MAX_PROCESSES];

// Function to check if resources can be safely allocated to a process
bool isSafeState(int safeSequence[]) {
    int work[MAX_RESOURCES];
    bool finish_copy[MAX_PROCESSES];
    int i, j;

    // Initialize work and finish_copy arrays
    for (i = 0; i < resources; i++) {
        work[i] = total_resources[i];
    }

    for (i = 0; i < processes; i++) {
        finish_copy[i] = finish[i];
    }

    // Find an unfinished process that can be allocated resources
    bool found;
    int safeIndex = 0;
    do {
        found = false;
        for (i = 0; i < processes; i++) {
            if (!finish_copy[i]) {
                bool canBeAllocated = true;
                for (j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        canBeAllocated = false;
                        break;
                    }
                }

                if (canBeAllocated) {
                    found = true;
                    safeSequence[safeIndex++] = i; // Add the process to the safe sequence
                    for (j = 0; j < resources; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish_copy[i] = true;
                }
            }
        }
    } while (found);

    // If all processes are finished, the state is safe
    for (i = 0; i < processes; i++) {
        if (!finish_copy[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int i, j;
    int safeSequence[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &processes);

    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    printf("Enter the total resources:\n");
    for (i = 0; i < resources; i++) {
        scanf("%d", &total_resources[i]);
        total[i]=total_resources[i];
    }

    printf("Enter the maximum demand of each process:\n");
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocated resources for each process:\n");
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];// to calculate need (resources)for each process
        }
        finish[i] = false; // Initialize all processes as unfinished
    }
     // Calculate available resources by subtracting allocated resources from total resources
    for (i = 0; i < resources; i++) {
        for (j = 0; j < processes; j++) {
            total_resources[i] -= allocation[j][i];
        }
    }


    // Perform Banker's algorithm to check if it is safe to allocate resources
    bool isSafe = isSafeState(safeSequence);

    if (isSafe) {
        printf("\nSafe state: Resources can be allocated to processes without causing deadlock.\n");
        printf("Safe sequence: ");
        for (i = 0; i < processes; i++) {
            printf("P%d ", safeSequence[i]);
        }
        printf("\n");
    } else {
        printf("\nUnsafe state: Resources cannot be allocated to processes without causing deadlock.\n");
    }

   do
   {
    printf("Do any of the processes want to make any additional requests?(1/0)\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("How many requests are made?\n");
        scanf("%d",&numr);
        f=0;
        while(f<numr)
        {

            printf("\n Enter process number and resource number :\n");
        scanf("%d%d",&a,&b);
        printf("Enter how many additional %d resources %d needs",a,b);
        scanf("%d",&temp);
        allocation[a][b]+=temp;
        f++;
        }//while

        for (i = 0; i < resources; i++) {
        total_resources[i]=total[i];
    }

         // Calculate available resources by subtracting allocated resources from total resources
    for (i = 0; i < resources; i++) {
        for (j = 0; j < processes; j++) {
            total_resources[i] -= allocation[j][i];
        }
    }

        isSafe = isSafeState(safeSequence);//CALLING FUNCTIONN!!!
        if (isSafe) {
        printf("\nSafe state: Resources can be allocated to processes without causing deadlock.\n");
        printf("Safe sequence: ");
        for (i = 0; i < processes; i++) {
            printf("P%d ", safeSequence[i]);
        }
        printf("\n");
    } else {
        printf("\nUnsafe state: Resources cannot be allocated to processes without causing deadlock.\n");
    }
        break;
        case 0:exit(0);break;
    }
}while(choice!=0);

return 0;
}//main

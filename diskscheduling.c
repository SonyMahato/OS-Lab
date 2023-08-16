#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Function to implement SSTF scheduling algorithm
void sstf(int queue[], int n, int head) {
    int totalMovement = 0;
    int visited[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;  //initialise entire visited array to 0(all unvisited initially)
    }

    printf("SSTF Scheduling\n");
    printf("Sequence of movement: %d ", head);

    for (int i = 0; i < n; i++) {
        int minDistance = 9999;
        int index = -1;

       //for loop to find min dist from each point
        for (int j = 0; j < n; j++) {
            if (visited[j]==0 && abs(queue[j] - head) < minDistance) {
                minDistance = abs(queue[j] - head);
                index = j;
            }
        }

        visited[index] = 1;
        totalMovement += minDistance;
        head = queue[index];
        printf("-> %d ", head);
    }

    printf("\nTotal head movement: %d\n\n", totalMovement);
}


// Function to implement LOOK scheduling algorithm
void look(int queue[], int n, int head, int direction) {
    int totalMovement = 0; int t1=0,t2=0;
    int pos=0,pos1,pos2=0;//position of element left of head
for(int i=0;i<n;i++)
{
    if(queue[i]>head)
    {
        pos=i-1; break;  //pos=1 here
    }
}

    printf("LOOK Scheduling\n");
    printf("Sequence of movement: %d ", head);

    if (direction == 1) {
        t1=queue[n-1]-head;
        t2=queue[n-1]-queue[0];
        pos1=pos+1;
        while(pos1<=n-1)
        printf("->%d",queue[pos1++]);
        pos2=pos;
        while(pos2>=0)
        printf("->%d",queue[pos2--]);
        totalMovement=t1+t2;

    }
    else {
       t1=head-queue[0];
       t2=queue[n-1]-queue[0];
       totalMovement=t1+t2;
       pos1=pos;
       while(pos1>=0)
       printf("->%d",queue[pos1--]);
       pos2=pos+1;
       while(pos2<=n-1)
       printf("->%d",queue[pos2++]);

    }

    printf("\nTotal head movement: %d\n\n", totalMovement);
}

// Function to implement C-LOOK scheduling algorithm
void clook(int queue[], int n, int head, int direction) {
     int totalMovement = 0; int t1=0,t2=0,t3=0;
    int pos=0,pos1,pos2=0;//position of element left of head
for(int i=0;i<n;i++)
{
    if(queue[i]>head)
    {
        pos=i-1; break;  //pos=1 here
    }
}

    printf("CLOOK Scheduling\n");
    printf("Sequence of movement: %d ", head);

    if (direction == 1) {
        t1=queue[n-1]-head;
        pos1=pos;
        t2=queue[pos1]-queue[0];
        t3=(199-queue[n-1])+(queue[0]);
        pos1=pos+1;
        while(pos1<=n-1)
        printf("->%d",queue[pos1++]);
        pos2=0;
        while(pos2<=pos)
        printf("->%d",queue[pos2++]);
        totalMovement=t1+t2+t3;

    }
    else {
        pos1=pos+1;
       t1=head-queue[0];
       t2=queue[n-1]-queue[pos1];
       t3=queue[0]+199-queue[n-1];
       totalMovement=t1+t2+t3;
       pos1=pos;
       while(pos1>=0)
       printf("->%d",queue[pos1--]);
       pos1=pos+1;
       pos2=n-1;
       while(pos2>=pos1)
       printf("->%d",queue[pos2--]);

    }
    printf("\nTotal head movement: %d\n\n", totalMovement);
}

int main() {
    int n, head, direction;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

   int queue[n];
   int queue1[n];

   printf("Enter the request queue:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
        queue1[i]=queue[i];
    }
    //sort
    for (int k=0;k<n-1;k++)
    {
      for(int y=0;y<n-k-1;y++)
      {
          if(queue[y]>queue[y+1])
          {
          int temp= queue[y];
          queue[y]=queue[y+1];
          queue[y+1]=temp;
          }
      }

    }//sorted

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the direction (1 for right, -1 for left): ");
    scanf("%d", &direction);

    while (1) {
        printf("\nDisk Scheduling Algorithms:\n");

        printf("1. SSTF\n");

        printf("2. LOOK\n");
        printf("3. C-LOOK\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                sstf(queue1, n, head);
                break;

            case 2:
                look(queue, n, head, direction);
                break;
            case 3:
                clook(queue, n, head, direction);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

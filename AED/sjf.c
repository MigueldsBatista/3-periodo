#include <stdio.h>

typedef struct PCB // Process Control Block
{
    int burst;
    int processId; // process id
    int wait; // wait time
    int turnAround; // turn around time
} PCB;


int main() {
    PCB process[100], temp;
    int numProcess; // Number of Processes
    int i, j; // indexes
    int waitTotal = 0; // total wait time
    int timeTotal = 0; // total turnaround time
    float waitAverage = 0.0; // wait time average
    float turnAroundAverage = 0.0;

    printf("Shortest Job First Algorithm\n");
    printf("Enter the total number of processes: ");
    scanf("%d", &numProcess);

    // Input burst time for each process
    for (i = 0; i < numProcess; i++) {
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &process[i].burst);
        process[i].processId = i + 1;
    }

    // Sort processes by burst time using bubble sort
    for (i = 0; i < numProcess - 1; i++) {        //we can assure one element is sorted for each iteration and the last iteration is not needed
        for (j = 0; j < numProcess - i - 1; j++) {// since the rest of the list will be already sorted
            if (process[j].burst > process[j + 1].burst) {
                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }

    // Calculate wait time and turn around time for each process
    for (i = 0; i < numProcess; i++) {
        if (i == 0) {
            process[i].wait = 0; // First process has no wait time
        } else {
            (process[i].wait) = (process[i - 1].wait) + (process[i - 1].burst);
        }
        process[i].turnAround = process[i].wait + process[i].burst;
        waitTotal += process[i].wait;
        timeTotal += process[i].turnAround;
    }

    waitAverage = (float)waitTotal / numProcess;
    turnAroundAverage = (float)timeTotal / numProcess;

    // Display process order and times
    printf("\nProcess ID\tBurst Time\tWait Time\tTurnaround Time\n");
    for (i = 0; i < numProcess; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", process[i].processId, process[i].burst, process[i].wait, process[i].turnAround);
    }

    printf("\nAverage Wait Time: %.2f", waitAverage);
    printf("\nAverage Turnaround Time: %.2f", turnAroundAverage);

    return 0;
}

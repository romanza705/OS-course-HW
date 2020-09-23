////
//// Created by roman on 23.09.2020.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define PROCESSES_NUMBER 7
//void swap (int* a, int i, int j){
//    a[i]+=a[j];
//    a[j]=a[i]-a[j];
//    a[i]=a[i]-a[j];
//}
//
//void sorting (int* burst_time, int* arrival_time, int* process, int n){
//    for (int i = 0; i < n; i++){
//        for (int j = 0; j < n - 1 - i; j++){
//            if ((arrival_time[j] > arrival_time[j + 1]) ||
//            (arrival_time[j] == arrival_time[j + 1] && burst_time[j] > burst_time[j + 1])){
//                swap(burst_time, j, j + 1);
//                swap(arrival_time, j, j + 1);
//                swap(process, j, j + 1);
//            }
//
//        }
//    }
//}
//
//int main()
//{
//    printf("\nNumber of Processes:\t %d \n", PROCESSES_NUMBER);
//    int process[PROCESSES_NUMBER],
//        arrival_time[PROCESSES_NUMBER],
//        burst_time[PROCESSES_NUMBER],
//        waiting_time[PROCESSES_NUMBER],
//        turnaround_time[PROCESSES_NUMBER],
//        completion_time[PROCESSES_NUMBER];
//    float avg_waiting_time = 0, avg_turnaround_time = 0;
//
//    for(int i = 0; i < PROCESSES_NUMBER; i++){
//        arrival_time[i] = rand()%30 + 1;
//        printf("(random)Arrival Time For Process[%d]:\t%d\n", i + 1, arrival_time[i]);
//        burst_time[i] = rand()%50 + 1;
//        printf("(random)Burst Time For Process[%d]:\t%d\n", i + 1, burst_time[i]);
//        process[i] = i + 1;
//    }
//
//    sorting(burst_time, arrival_time, process, PROCESSES_NUMBER);
//
//    waiting_time[0]=0;
//    completion_time[0]=0;
//    turnaround_time[0]=burst_time[0];
//
//    for(int i=1; i < PROCESSES_NUMBER; i++) {
//        waiting_time[i]=0;
//        for(int j=0; j<i; j++)
//            waiting_time[i]+=burst_time[j];
//        waiting_time[i] -= arrival_time[i];
//        completion_time[i] = waiting_time[i] + arrival_time[i];
//        turnaround_time[i] = burst_time[i] + waiting_time[i];
//        avg_waiting_time+=waiting_time[i];
//        avg_turnaround_time+=turnaround_time[i];
//    }
//
//    printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\t Arrival Time\t Completion Time\n");
//    for(int i = 0; i < PROCESSES_NUMBER; i++)
//    {
//        printf("\nProcess[%d]\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t\t%d\t\t\t\t%d", process[i], burst_time[i],
//               waiting_time[i], turnaround_time[i], arrival_time[i], completion_time[i]);
//    }
//    printf("\n\nAverage Waiting Time: %f", avg_waiting_time / PROCESSES_NUMBER);
//    printf("\nAverage Turnaround Time: %f", avg_turnaround_time / PROCESSES_NUMBER);
//
//    return 0;
//}
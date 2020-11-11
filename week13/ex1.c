//
// Created by roman on 10.11.2020.
//

//gcc main.c -o main
//./main input_dl.txt
//./main input_ok.txt
#include <stdio.h>
#include <stdbool.h>
#define BUFFER_SIZE 50
#define PROCESS_NUMBER 5
#define RESOURCE_NUMBER 3

int main(int argc, char *argv[]) {
    char input_str[BUFFER_SIZE];
    int existingResources[RESOURCE_NUMBER];
    int availableResources[RESOURCE_NUMBER];
    int allocationMatrix[PROCESS_NUMBER][RESOURCE_NUMBER];
    int requestMatrix[PROCESS_NUMBER][RESOURCE_NUMBER];
    int deadlockProcesses[PROCESS_NUMBER];
    bool ready[PROCESS_NUMBER];
    bool executable[PROCESS_NUMBER];

    if (argc < 2) {
        printf("Provide filename %s", argv[0]);
        return 0;
    }

    FILE* input = fopen(argv[1], "r");
    fgets(input_str, BUFFER_SIZE, input);
    int position = 0;
    for (int i = 0; i < RESOURCE_NUMBER; i++) {
        existingResources[i] = (int)(input_str[position] - '0');
        position += 2;
    }

    position = 0;
    fgets(input_str, BUFFER_SIZE, input);
    fgets(input_str, BUFFER_SIZE, input);

    fgets(input_str, BUFFER_SIZE, input);
    for (int i = 0; i < RESOURCE_NUMBER; i++) {
        availableResources[i] = (int)(input_str[position] - '0');
        position += 2;
    }

    position = 0;
    fgets(input_str, BUFFER_SIZE, input);
    fgets(input_str, BUFFER_SIZE, input);

    fgets(input_str, BUFFER_SIZE, input);
    for (int i = 0; i < PROCESS_NUMBER; i++) {
        for (int j = 0; j < RESOURCE_NUMBER; j++) {
            allocationMatrix[i][j] = (int)(input_str[position] - '0');
            position += 2;
        }

        position = 0;
        fgets(input_str, BUFFER_SIZE, input);
    }

    position = 0;

    fgets(input_str, BUFFER_SIZE, input);
    for (int i = 0; i < PROCESS_NUMBER; i++) {
        for (int j = 0; j < RESOURCE_NUMBER; j++) {
            requestMatrix[i][j] = (int)(input_str[position] - '0');
            position += 2;
        }

        position = 0;
        fgets(input_str, BUFFER_SIZE, input);
    }
    fclose(input);

    for (int i = 0; i < PROCESS_NUMBER; i++) {
        deadlockProcesses[i] = 0;
        executable[i] = true;
        ready[i] = false;
    }

    bool check = true;

    while (check) {
        check = false;

        for (int i = 0; i < PROCESS_NUMBER; i++) {
            executable[i] = true;
            for (int j = 0; j < RESOURCE_NUMBER; j++) {
                if (requestMatrix[i][j] > availableResources[j]) {
                    executable[i] = false;
                    break;
                }
            }
        }


        for (int i = 0; i < PROCESS_NUMBER; i++) {
            if (!executable[i] || !ready[i]) {
                for (int j = 0; j < RESOURCE_NUMBER; j++) {
                    availableResources[j] += allocationMatrix[i][j];
                    allocationMatrix[i][j] = 0;
                    requestMatrix[i][j] = 0;
                    check = true;
                    ready[i] = true;
                }
            }
        }
    }
    bool deadlock = false;
    for (int i = 0; i < PROCESS_NUMBER; i++) {
        if (ready[i] == 0) {
            deadlockProcesses[i] = 1;
            deadlock = true;
        }
    }

    FILE* output;

    if (deadlock) {
        output = fopen("output_dl.txt", "w+");
        for (int i = 0; i < PROCESS_NUMBER; i++) {
            if (deadlockProcesses[i]) {fprintf(output, "Process num:%d is deadlocked\n", i + 1);}
        }
    } else {
        output = fopen("output_ok.txt", "w+");
        fprintf(output, "There are no deadlocks");
    }

    fclose(output);

    return 0;
}
#pragma once

class Process {
public:
    int pid;
    int burstTime;
    int arrivalTime;
    int remainingTime;
    int completionTime;

    Process(int id, int bt, int at)
        : pid(id), burstTime(bt), arrivalTime(at),
          remainingTime(bt), completionTime(0) {}
};

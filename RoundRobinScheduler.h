#pragma once
#include <vector>
#include "ProcessManager.h"

class RoundRobinScheduler {
private:
    int timeQuantum;
    ProcessManager& manager;

    struct GanttEntry {
        int pid;
        int startTime;
        int endTime;
    };

    void printGanttChart(const std::vector<GanttEntry>& chart);
    void calculateAndPrintAverages();

public:
    RoundRobinScheduler(int tq, ProcessManager& pm);
    void schedule();
};

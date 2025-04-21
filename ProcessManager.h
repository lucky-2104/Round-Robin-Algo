#pragma once
#include <vector>
#include "Process.h"

class ProcessManager {
private:
    std::vector<Process> processes;

public:
    void inputProcesses();
    std::vector<Process>& getProcesses();
    void printResults(double avgTAT, double avgWT);
};

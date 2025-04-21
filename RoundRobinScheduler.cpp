#include "RoundRobinScheduler.h"
#include <iostream>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

RoundRobinScheduler::RoundRobinScheduler(int tq, ProcessManager& pm)
    : timeQuantum(tq), manager(pm) {}

void RoundRobinScheduler::schedule() {
    auto& processes = manager.getProcesses();
    int n = processes.size();
    int time = 0;
    int completed = 0;
    queue<int> readyQueue;
    vector<bool> inQueue(n, false);
    vector<GanttEntry> ganttChart;

    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    for (int i = 0; i < n; ++i) {
        if (processes[i].arrivalTime <= time && !inQueue[i]) {
            readyQueue.push(i);
            inQueue[i] = true;
        }
    }

    while (completed < n) {
        if (readyQueue.empty()) {
            time++;
            for (int i = 0; i < n; ++i) {
                if (!inQueue[i] && processes[i].arrivalTime <= time) {
                    readyQueue.push(i);
                    inQueue[i] = true;
                }
            }
            continue;
        }

        int idx = readyQueue.front();
        readyQueue.pop();
        Process& p = processes[idx];

        int startTime = time;
        int runTime = min(timeQuantum, p.remainingTime);
        p.remainingTime -= runTime;
        time += runTime;
        int endTime = time;

        ganttChart.push_back({p.pid, startTime, endTime});

        for (int i = 0; i < n; ++i) {
            if (!inQueue[i] && processes[i].arrivalTime <= time) {
                readyQueue.push(i);
                inQueue[i] = true;
            }
        }

        if (p.remainingTime > 0) {
            readyQueue.push(idx);
        } else {
            p.completionTime = time;
            completed++;
        }
    }

    printGanttChart(ganttChart);
    calculateAndPrintAverages();
}

void RoundRobinScheduler::printGanttChart(const vector<GanttEntry>& chart) {
    cout << "\nGantt Chart:\n";

    for (const auto& entry : chart) {
        cout << " ";
        for (int i = 0; i < entry.endTime - entry.startTime; ++i) cout << "--";
    }
    cout << "\n|";

    for (const auto& entry : chart) {
        int space = entry.endTime - entry.startTime - 1;
        cout << " P" << entry.pid;
        for (int i = 0; i < space; ++i) cout << " ";
        cout << "|";
    }

    cout << "\n ";
    for (const auto& entry : chart) {
        for (int i = 0; i < entry.endTime - entry.startTime; ++i) cout << "--";
        cout << " ";
    }

    cout << "\n" << chart.front().startTime;
    for (const auto& entry : chart) {
        int spacing = (entry.endTime - entry.startTime) * 2;
        cout << setw(spacing) << entry.endTime;
    }
    cout << "\n";
}

void RoundRobinScheduler::calculateAndPrintAverages() {
    auto& processes = manager.getProcesses();
    double totalTAT = 0, totalWT = 0;

    for (const auto& p : processes) {
        int turnaround = p.completionTime - p.arrivalTime;
        int waiting = turnaround - p.burstTime;
        totalTAT += turnaround;
        totalWT += waiting;
    }

    int n = processes.size();
    double avgTAT = totalTAT / n;
    double avgWT = totalWT / n;

    manager.printResults(avgTAT, avgWT);
}

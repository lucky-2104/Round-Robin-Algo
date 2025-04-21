#include "ProcessManager.h"
#include <iostream>
#include <iomanip>

using namespace std;

void ProcessManager::inputProcesses() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int bt, at;
        cout << "\n--- Process " << (i + 1) << " ---\n";
        cout << "Burst Time   : ";
        while (!(cin >> bt)) {
            cout << "Invalid input. Enter burst time again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    
        cout << "Arrival Time : ";
        while (!(cin >> at)) {
            cout << "Invalid input. Enter arrival time again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    
        processes.emplace_back(i + 1, bt, at);
    }
    
}

vector<Process>& ProcessManager::getProcesses() {
    return processes;
}

void ProcessManager::printResults(double avgTAT, double avgWT) {
    cout << "\nProcess\tBurst\tArrival\tCompletion\tTurnaround\tWaiting\n";
    for (const auto& p : processes) {
        int turnaround = p.completionTime - p.arrivalTime;
        int waiting = turnaround - p.burstTime;
        cout << "P" << p.pid << "\t" << p.burstTime << "\t" << p.arrivalTime
             << "\t" << p.completionTime << "\t\t" << turnaround << "\t\t" << waiting << "\n";
    }
    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << avgTAT << "\n";
    cout << "Average Waiting Time   : " << avgWT << "\n";
}

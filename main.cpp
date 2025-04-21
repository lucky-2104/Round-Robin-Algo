#include<iostream> 
#include "ProcessManager.h"
#include "RoundRobinScheduler.h"
using namespace std;
int main() {
    ProcessManager pm;
    pm.inputProcesses();

    int tq;
    cout << "\nEnter time quantum: ";
    while (!(cin >> tq) || tq <= 0) {
            cout << "Please enter a valid positive number for time quantum: ";
            cin.clear();
            cin.ignore(1000, '\n');
}


    RoundRobinScheduler scheduler(tq, pm);
    scheduler.schedule();

    return 0;
}

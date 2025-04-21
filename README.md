🧠 Round Robin OS Scheduling Simulator (C++)
A console-based simulation of the Round Robin CPU Scheduling Algorithm, written in modular C++ using object-oriented programming principles.
The project includes a visual Gantt chart, turnaround/waiting time calculations, and a clean CLI experience.

📌 Features
🧮 Round Robin scheduling logic with dynamic time quantum

📊 Console Gantt Chart to visualize process execution

📈 Automatic calculation of:

Average Turnaround Time

Average Waiting Time

🔁 Supports multiple processes with custom burst and arrival times

🧱 Modular codebase split across headers and source files

💡 Input validation for a smoother user experience

📸 Sample Output

Enter number of processes: 3

--- Process 1 ---
Burst Time : 2
Arrival Time : 3

--- Process 2 ---
Burst Time : 3
Arrival Time : 1

--- Process 3 ---
Burst Time : 1
Arrival Time : 2

Enter time quantum: 2

Gantt Chart:

---

| P2 | P3 | P2 | P1 |

---

0 2 3 5 7

Process Burst Arrival Completion Turnaround Waiting
P1 2 3 7 4 2
P2 3 1 5 4 1
P3 1 2 3 1 0

Average Turnaround Time: 3.00  
Average Waiting Time : 1.00

🛠 How It Works

Processes are stored as objects with fields for burst, arrival, remaining time, and completion time.
The scheduler uses a queue to simulate CPU time-slicing.
Each step is tracked and logged in a Gantt-style visualization.
Final stats are calculated from each process’s completion and arrival time.

📂 Project Structure

RoundRobin/
├── main.cpp
├── Process.h / .cpp
├── ProcessManager.h / .cpp
├── RoundRobinScheduler.h / .cpp

🚀 How to Run

🧑‍💻 Compile:

g++ main.cpp ProcessManager.cpp RoundRobinScheduler.cpp -o RoundRobin

▶️ Run:

./RoundRobin

🧩 Technologies Used

Language: C++ (11+)

Concepts: CPU Scheduling, Queues, OOP, Modularity

Tools: CLI, Gantt-style charting, I/O formatting

📚 Learnings
Implemented a real-time CPU scheduler using object-oriented practices

Improved code maintainability through class separation and modular design

Learned to work with queues and simulate system-level behavior

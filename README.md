# CPU-Scheduler
A physical implementation of several classic CPU Scheduling algorithms. Among the algorithms implemented are: First-Come-First-Serve (FCFS), Priority Scheduling, Round-Robing (RR). The following program visually demonstrates how each CPU Scheduling algorithm works.
## How To Compile
Make sure you are in the directory that includes all of the project files.

Run the "make [insert algorithm name here]" command for each algorithm in the terminal
e.g:
make fcfs
make priority
make rr

## How To Test
Make sure you have compiled all of the algorithms in the previous step.

Run the "./[insert algorithm name here] schedule.txt" command for the algorithm you want to test in the terminal:
e.g:
./fcfs schedule.txt
./priority schedule.txt
./rr schedule.txt
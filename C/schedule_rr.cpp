/**
 * Round-robin scheduling
 */


extern "C" {
#include "task.h"
#include "list.h"
#include "cpu.h"
}

#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

static node *taskList = nullptr;

extern "C" void add(char *name, int priority, int burst) {
    Task *t = (Task*) malloc(sizeof(Task));
    t->name = strdup(name);
    t->priority = priority;
    t->burst = burst;
    insert(&taskList, t);
}

extern "C" void schedule() {
    std::vector<Task*> tasks;
    node *cur = taskList;

    // preserve original order
    while (cur) {
        tasks.push_back(cur->task);
        cur = cur->next;
    }
    std::reverse(tasks.begin(), tasks.end());

    bool any_left = true;
    while (any_left) {
        any_left = false;

        for(Task* t : tasks){
            if(t->burst > 0) {
                any_left = true;

                int burst_window; // Allows a process to run for its quantum and ends it when the quantum is over
                if (t->burst > QUANTUM) { // This means that if the CPU burst is larger than the quantum, the task can only run for that quantum
                    burst_window = QUANTUM;
                } else {
                    burst_window = t->burst;
                }

                cout << "Process " << t->name << " ran for " << burst_window << " ms. \n";
            }
        }
    }

}
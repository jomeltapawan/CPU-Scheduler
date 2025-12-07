/*
 * Priority scheduling
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
    t->name =strdup(name);
    t->priority = priority;
    t->burst = burst;

    insert(&taskList, t);
}

// Function that compares priority numbers to determine which task has a higher priority over another
bool comparePriority(Task* a, Task* b){
    if (a->priority > b->priority) { //if task a has a higher priority than task b
        return true;
    }else {
        return false;
    }
    }

extern "C" void schedule() {
    vector<Task*> tasks;
    node *curr = taskList;

    //arrival order for equal priority
    while (curr) {
        tasks.push_back(curr->task);
        curr = curr->next;
    }

    reverse(tasks.begin(), tasks.end()); //Reverses the list since it is inserted in reverse order

    stable_sort(tasks.begin(), tasks.end(), comparePriority); //Sorts

    for (Task *t : tasks) {
        cout << "Process: " << t->name << " ran for " << t->burst << " ms. \n";
    }
}
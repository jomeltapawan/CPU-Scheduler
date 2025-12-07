/**
 * FCFS scheduling
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

//head for tasks inserted by add()
static node *taskList = nullptr;

extern "C" void add(char *name, int priority, int burst) {
    //Pointer to task: initializes the task
    Task *T = (Task*) malloc(sizeof(Task));
    T->name = strdup(name);
    T->tid = 0;
    T->priority = priority;
    T->burst = burst;
    insert(&taskList, T);
}

extern "C" void schedule() {
    //Use a vector of tasks in the order that they are inserted
    vector<Task*> tasks;
    node *curr = taskList; //Pointer to the head of taskList
    while (curr){
        tasks.push_back(curr->task);
        curr = curr->next;
    }

    //Since insert() adds to the head of the list, it is inserted in reverse order
    //Therefore, we must reverse the vector to show the actual order
    reverse(tasks.begin(), tasks.end());
    for(Task *T : tasks){
        cout << "Process: " << T->name << " ran for " << T->burst << " ms. \n";
        }
    }


// To-do list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Task
{
    string description;
    bool completed;

};

vector<Task> tasks;

void displayMenu();
void addTask();
void markCompleted();
void viewTasks();

int main()
{
    int choice;
    do {
        displayMenu();
        cout << "Enter a choice" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            addTask();
            break;

        case 2:
            markCompleted();
            break;
        case 3:
            viewTasks();
            break;

        case 4:
            cout << "Exiting......" << endl;
            break;

        default:
            cout << "Invalid choice please choose again" << endl;
            break;
        }

    } while (choice != 4);
    return 0;
}

void displayMenu() {
    cout << " To-do list " << endl;
    cout << "1.Add a task" << endl;
    cout << "2.Mark completed tasks" << endl;
    cout << "3.View tasks added" << endl;
    cout << "4.Exit" << endl;
} 

void addTask() {
    Task newTask;

    cout << "Enter your task and its description" << endl;
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;

    tasks.push_back(newTask);
    cout << "Task added succefuly" << endl;
}

void markCompleted() {
    int taskIndex;
    cout << "Enter the index of the task to mark as completed" << endl;
    cin >> taskIndex;

    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks[taskIndex].completed = true;
        cout << "Task completed" << endl;
    }
    else {
        cout << "Invalid index " << endl;
    }
    
}

void viewTasks() {
    
    if (tasks.empty()) {
        cout << "No tasks found " << endl;
    }
    else {
        cout << "Task: " << endl;

        for (int i = 0; i < tasks.size(); i++) {
            cout << i << ". " << tasks[i].description << "(";

            if (tasks[i].completed) {
                cout << "completed" << endl;

            }
            else {
                cout << "Pending" << endl;
            }
            cout << ")" << endl;

           
        }
    }
}
 
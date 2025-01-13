#include <iostream>
#include <string>
using namespace std;

int DisplayMenu() {
    int choice;
    cout << "\n===== TO-DO LIST MENU =====" << endl;
    cout << "1. Add a task" << endl;
    cout << "2. Mark a task as completed" << endl;
    cout << "3. View tasks" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

void AddTask(string tasks[], int &size) { 
    if (size >= 100) {
        cout << "Task list is full!" << endl;
        return;
    }

    cout << "Type the task: ";
    getline(cin, tasks[size]);
    size++;
    cout << "Task added successfully!" << endl;
}

void ViewTask(string tasks[], int size) {
    if (size == 0) {
        cout << "No tasks to display!" << endl;
        return;
    }

    cout << "\nCurrent Tasks:" << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void MarkTask(string tasks[], int size) {
    if (size == 0) {
        cout << "No tasks available to mark as completed!" << endl;
        return;
    }

    cout << "Available tasks:" << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }

    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= size) {
        tasks[taskNumber - 1] = "[Completed] " + tasks[taskNumber - 1];
        cout << "Task " << taskNumber << " marked as completed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

int main() {
    string tasks[100];
    int choice, size = 0; 

    do {
        choice = DisplayMenu();
        switch (choice) {
            case 1:
                AddTask(tasks, size);
                break;
            case 2:
                MarkTask(tasks, size);
                break;
            case 3:
                ViewTask(tasks, size);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!" << endl;
        }
    } while (choice != 4);
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Task structure to hold task information
struct Task {
    int id;
    string description;
    bool isCompleted;

    Task(int taskId, const string& desc) 
        : id(taskId), description(desc), isCompleted(false) {}
};

class TodoManager {
private:
    vector<Task> tasks;
    int nextId;

public:
    TodoManager() : nextId(1) {}

    // Add a new task
    void addTask(const string& description) {
        tasks.push_back(Task(nextId++, description));
        cout << "Task added successfully! ID: " << (nextId - 1) << endl;
    }

    // Display all tasks
    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        cout << "=== TO-DO LIST ===" << endl;
        cout << "ID | Status    | Description" << endl;
        cout << "---|-----------|------------" << endl;

        for (const auto& task : tasks) {
            cout << task.id << "  | " 
                 << (task.isCompleted ? "Completed" : "Pending  ") 
                 << " | " << task.description << endl;
        }
        cout << endl;
    }

    // Mark task as completed
    void markTaskCompleted(int taskId) {
        auto it = find_if(tasks.begin(), tasks.end(), 
                         [taskId](const Task& task) { return task.id == taskId; });

        if (it != tasks.end()) {
            it->isCompleted = true;
            cout << "Task " << taskId << " marked as completed!" << endl;
        } else {
            cout << "Task with ID " << taskId << " not found!" << endl;
        }
    }

    // Remove task from list
    void removeTask(int taskId) {
        auto it = find_if(tasks.begin(), tasks.end(), 
                         [taskId](const Task& task) { return task.id == taskId; });

        if (it != tasks.end()) {
            cout << "Removing task: " << it->description << endl;
            tasks.erase(it);
            cout << "Task removed successfully!" << endl;
        } else {
            cout << "Task with ID " << taskId << " not found!" << endl;
        }
    }

    // Get task count
    int getTaskCount() const {
        return tasks.size();
    }
};

// Function to display menu
void displayMenu() {
    cout << "=== TODO LIST MANAGER ===" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice (1-5): ";
}

// Function to clear input buffer
void clearInputBuffer() {
    cin.clear();
    cin.ignore(10000, '\n');
}

int main() {
    TodoManager todoManager;
    int choice;
    string taskDescription;
    int taskId;

    cout << "Welcome to the Simple To-Do List Manager!" << endl;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                clearInputBuffer();
                cout << "Enter task description: ";
                getline(cin, taskDescription);

                if (!taskDescription.empty()) {
                    todoManager.addTask(taskDescription);
                } else {
                    cout << "Task description cannot be empty!" << endl;
                }
                break;
            }

            case 2: {
                todoManager.viewTasks();
                break;
            }

            case 3: {
                if (todoManager.getTaskCount() == 0) {
                    cout << "No tasks available to mark as completed." << endl;
                    break;
                }

                todoManager.viewTasks();
                cout << "Enter task ID to mark as completed: ";
                cin >> taskId;
                todoManager.markTaskCompleted(taskId);
                break;
            }

            case 4: {
                if (todoManager.getTaskCount() == 0) {
                    cout << "No tasks available to remove." << endl;
                    break;
                }

                todoManager.viewTasks();
                cout << "Enter task ID to remove: ";
                cin >> taskId;
                todoManager.removeTask(taskId);
                break;
            }

            case 5: {
                cout << "Thank you for using the To-Do List Manager. Goodbye!" << endl;
                return 0;
            }

            default: {
                cout << "Invalid choice! Please enter a number between 1 and 5." << endl;
                clearInputBuffer();
                break;
            }
        }

        
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
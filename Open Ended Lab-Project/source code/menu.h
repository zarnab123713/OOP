#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <windows.h>
#include <iomanip>

using namespace std;

#define MAX_TASKS 50

// ================= Menu =================
class Menu {
private:
    TaskManager manager;
    string filename;

    int getIntInRange(const string &prompt, int minv, int maxv) {
        int val;
        while (true) {
            cout << prompt;
            if (cin >> val) {
                if (val < minv || val > maxv) {
                    cin.clear(); cin.ignore(10000, '\n');
                    setColor(12); cout << "Value must be between " << minv << " and " << maxv << ".\n"; setColor(7);
                    continue;
                }
                cin.ignore();
                return val;
            } else {
                cin.clear(); cin.ignore(10000, '\n');
                setColor(12); cout << "Invalid input. Enter a number.\n"; setColor(7);
            }
        }
    }

    string getLineInput(const string &prompt) {
        string s;
        cout << prompt;
        getline(cin, s);
        return s;
    }

    string getPriorityInput() {
        while (true) {
            string p = getLineInput("Enter Priority (High/Medium/Low): ");
            if (p == "High" || p == "Medium" || p == "Low") return p;
            setColor(12); cout << "Invalid priority. Use High, Medium, or Low.\n"; setColor(7);
        }
    }

    Time getValidTimeForAdd() {
        while (true) {
            int h = getIntInRange("Enter Hour (0-23): ", 0, 23);
            int m = getIntInRange("Enter Minute (0-59): ", 0, 59);
            try {
                Time t(h, m);
                if (manager.timeConflictPending(t)) {
                    setColor(12); cout << "Error: A pending task already uses this time. Try another.\n"; setColor(7);
                    continue;
                }
                return t;
            } catch (...) {
                setColor(12); cout << "Invalid time entered. Try again.\n"; setColor(7);
            }
        }
    }

    Time getValidTimeForUpdate(int excludeId) {
        while (true) {
            int h = getIntInRange("Enter Hour (0-23): ", 0, 23);
            int m = getIntInRange("Enter Minute (0-59): ", 0, 59);
            try {
                Time t(h, m);
                if (manager.timeConflictPending(t, excludeId)) {
                    setColor(12); cout << "Error: A pending task (other than this) already uses this time. Try another.\n"; setColor(7);
                    continue;
                }
                return t;
            } catch (...) {
                setColor(12); cout << "Invalid time entered. Try again.\n"; setColor(7);
            }
        }
    }

public:
    Menu(const string &fname) : filename(fname) {
        manager.load(filename);
    }

    void show() {
        while (true) {
            clearScreen();
            setColor(11);
            cout << "=========================================\n";
            cout << "        SMART TASK MANAGEMENT SYSTEM     \n";
            cout << "=========================================\n";
            setColor(7);
            cout << "1. Add Task\n";
            cout << "2. View All Tasks\n";
            cout << "3. View Task Summary\n";
            cout << "4. Mark Task(s) as Completed\n";
            cout << "5. Update Task\n";
            cout << "6. Delete Task(s)\n";
            cout << "0. Exit\n";

            int choice = getIntInRange("Enter your choice: ", 0, 6);

            if (choice == 1) {
                clearScreen();
                string title = getLineInput("Enter Title: ");
                string desc  = getLineInput("Enter Description: ");
                string prio  = getPriorityInput();
                Time t = getValidTimeForAdd();

                try {
                    manager.addTask(title, desc, prio, t);
                    manager.save(filename);
                    setColor(10); cout << "Task added successfully!\n"; setColor(7);
                } catch (const exception &e) {
                    setColor(12); cout << "Error: " << e.what() << "\n"; setColor(7);
                }
                pauseScreen();
            }
            else if (choice == 2) {
                clearScreen();
                manager.viewAll();
                pauseScreen();
            }
            else if (choice == 3) {
                clearScreen();
                manager.viewSummary();
                pauseScreen();
            }
            
            else if (choice == 4) {
    clearScreen();
    manager.viewSummary();
    if (manager.getCount() == 0) { pauseScreen(); continue; }
    if (!manager.hasPending()) { setColor(12); cout << "No pending tasks available.\n"; setColor(7); pauseScreen(); continue; }

    int num = getIntInRange("How many tasks do you want to mark completed? ", 1, manager.getCount());
    int ids[50];
    cout << "Enter exactly " << num << " Task ID(s), separated by spaces: ";

    string line;
    getline(cin, line);
    int countEntered = 0;
    int current = 0;
    for (size_t i = 0; i <= line.size(); ++i) {
        if (i == line.size() || line[i] == ' ') {
            if (current > 0) {
                ids[countEntered++] = current;
                current = 0;
            }
        } else if (isdigit(line[i])) {
            current = current * 10 + (line[i] - '0');
        }
    }

    if (countEntered != num) {
        setColor(12);
        cout << "Error: Expected " << num << " IDs, but got " << countEntered << ". Operation cancelled.\n";
        setColor(7);
        pauseScreen();
        continue;
    }

    int failedIds[50], failedCount = 0;
    int succeeded = manager.markCompletedByIds(ids, num, failedIds, failedCount);
    manager.save(filename);

    if (succeeded > 0) { setColor(10); cout << succeeded << " task(s) marked completed.\n"; setColor(7); }
    if (failedCount > 0) {
        setColor(12); cout << "Invalid/Already Completed IDs: ";
        for (int i = 0; i < failedCount; ++i) cout << failedIds[i] << " ";
        cout << "\n"; setColor(7);
    }
    pauseScreen();
}


            else if (choice == 5) {
                clearScreen();
                manager.viewSummary();
                if (manager.getCount() == 0) { pauseScreen(); continue; }

                int id = getIntInRange("Enter Task ID to update: ", 1, manager.getCount());
                Task* t = manager.getTaskById(id);
                if (!t) {
                    setColor(12); cout << "Invalid ID.\n"; setColor(7);
                } else {
                    if (t->isCompleted()) {
                        setColor(12); cout << "Cannot update a completed task.\n"; setColor(7);
                    } else {
                        string title = getLineInput("Enter New Title: ");
                        string desc  = getLineInput("Enter New Description: ");
                        string prio  = getPriorityInput();
                        Time newTime = getValidTimeForUpdate(id);
                        t->update(title, desc, prio, newTime);
                        manager.save(filename);
                        setColor(10); cout << "Task updated successfully.\n"; setColor(7);
                    }
                }
                pauseScreen();
            }
            else if (choice == 6) {
    clearScreen();
    manager.viewSummary();
    if (manager.getCount() == 0) { pauseScreen(); continue; }

    int num = getIntInRange("How many tasks do you want to delete? ", 1, manager.getCount());
    int ids[50];
    cout << "Enter exactly " << num << " Task ID(s), separated by spaces: ";

    string line;
    getline(cin, line);
    int countEntered = 0;
    int current = 0;
    for (size_t i = 0; i <= line.size(); ++i) {
        if (i == line.size() || line[i] == ' ') {
            if (current > 0) {
                ids[countEntered++] = current;
                current = 0;
            }
        } else if (isdigit(line[i])) {
            current = current * 10 + (line[i] - '0');
        }
    }

    if (countEntered != num) {
        setColor(12);
        cout << "Error: Expected " << num << " IDs, but got " << countEntered << ". Operation cancelled.\n";
        setColor(7);
        pauseScreen();
        continue;
    }

    int failedIds[50], failedCount = 0;
    int deleted = manager.deleteByIds(ids, num, failedIds, failedCount);
    manager.save(filename);

    if (deleted > 0) { setColor(10); cout << deleted << " task(s) deleted.\n"; setColor(7); }
    if (failedCount > 0) {
        setColor(12); cout << "Invalid IDs (not found): ";
        for (int i = 0; i < failedCount; ++i) cout << failedIds[i] << " ";
        cout << "\n"; setColor(7);
    }
    pauseScreen();
}


            else if (choice == 0) {
                setColor(11); cout << "Exiting Smart Task Management System. Goodbye!\n"; setColor(7);
                break;
            }
        }
    }
};

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <windows.h>
#include <iomanip>

using namespace std;

#define MAX_TASKS 50

// ================= TaskManager =================
class TaskManager {
private:
    Task tasks[MAX_TASKS];
    int count;

public:
    TaskManager() : count(0) {}

    int getCount() const { return count; }

    void load(const string &filename) {
        Task::resetNextId(1);
        count = FileHandler::loadTasks(tasks, MAX_TASKS, filename);
    }

    void save(const string &filename) const {
        FileHandler::saveTasks(tasks, count, filename);
    }
    
    bool hasPending() const {
    for (int i = 0; i < count; i++) {
        if (!tasks[i].isCompleted()) return true;
    }
    return false;
}


    Task* getTaskById(int id) {
        for (int i = 0; i < count; ++i) if (tasks[i].getId() == id) return &tasks[i];
        return nullptr;
    }

    bool timeConflictPending(const Time &t, int excludeId = -1) const {
        for (int i = 0; i < count; ++i) {
            if (tasks[i].getId() == excludeId) continue;
            if (!tasks[i].isCompleted() &&
                tasks[i].getTime().getHour() == t.getHour() &&
                tasks[i].getTime().getMinute() == t.getMinute())
                return true;
        }
        return false;
    }

    void addTask(const string &title, const string &desc, const string &priority, const Time &t) {
        if (count >= MAX_TASKS) throw runtime_error("Task limit reached (50).");
        if (timeConflictPending(t)) throw runtime_error("A pending task already has this time.");
        tasks[count++] = Task(title, desc, priority, t);
    }

    void viewAll() const {
        setColor(14); cout << "\n==== All Tasks ====\n"; setColor(7);
        if (count == 0) { setColor(14); cout << "No tasks available.\n"; setColor(7); return; }
        for (int i = 0; i < count; ++i) tasks[i].displayDetail();
    }

    void viewSummary() const {
        setColor(14); cout << "\n==== Task Summary ====\n"; setColor(7);
        if (count == 0) { setColor(14); cout << "No tasks available.\n"; setColor(7); return; }
        cout << left << setw(6) << "ID" << setw(30) << "Title" << setw(10) << "Priority"
             << setw(12) << "Time" << setw(10) << "Status" << "\n";
        cout << string(70, '-') << "\n";
        for (int i = 0; i < count; ++i) tasks[i].displaySummary();
    }

    void viewPendingSummary() const {
        setColor(14); cout << "\n==== Pending Tasks ====\n"; setColor(7);
        bool any = false;
        for (int i = 0; i < count; ++i) if (!tasks[i].isCompleted()) { any = true; break; }
        if (!any) { setColor(14); cout << "No pending tasks available.\n"; setColor(7); return; }

        cout << left << setw(6) << "ID" << setw(30) << "Title" << setw(10) << "Priority"
             << setw(12) << "Time" << "\n";
        cout << string(60, '-') << "\n";
        for (int i = 0; i < count; ++i) {
            if (!tasks[i].isCompleted()) {
                string tt = tasks[i].getTitle();
                if (tt.size() > 28) tt = tt.substr(0, 27) + "...";
                cout << left << setw(6) << tasks[i].getId()
                     << setw(30) << tt
                     << setw(10) << tasks[i].getPriority()
                     << setw(12) << tasks[i].getTime().getFormatted() << "\n";
            }
        }
    }

    int deleteByIds(const int ids[], int n, int failedIds[], int &failedCount) {
        failedCount = 0;
        int deleted = 0;
        for (int k = 0; k < n; ++k) {
            int id = ids[k];
            bool found = false;
            for (int i = 0; i < count; ++i) {
                if (tasks[i].getId() == id) {
                    for (int j = i; j < count - 1; ++j) tasks[j] = tasks[j + 1];
                    --count;
                    ++deleted;
                    found = true;
                    break;
                }
            }
            if (!found) failedIds[failedCount++] = id;
        }
        for (int i = 0; i < count; ++i) tasks[i].setId(i + 1);
        Task::resetNextId(count + 1);
        return deleted;
    }

    int markCompletedByIds(const int ids[], int n, int failedIds[], int &failedCount) {
    int done = 0;
    failedCount = 0;

    for (int i = 0; i < n; i++) {
        Task* task = getTaskById(ids[i]);
        if (task == nullptr) {
            failedIds[failedCount++] = ids[i]; // invalid ID
        } else if (task->isCompleted()) {
            failedIds[failedCount++] = ids[i]; // already completed
        } else {
            task->markComplete();
            done++;
        }
    }
    return done;
}

};

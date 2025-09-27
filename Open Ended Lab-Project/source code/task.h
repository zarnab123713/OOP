#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <windows.h>
#include <iomanip>

using namespace std;

#define MAX_TASKS 50


// ================= Task =================
class FileHandler; // forward
class Task {
private:
    int id;
    string title;
    string description;
    string priority;      // "High", "Medium", "Low"
    Time time;
    bool completed;

public:
    static int nextId;

    Task() : id(0), title(""), description(""), priority("Low"), time(), completed(false) {}
    Task(const string &t, const string &d, const string &p, const Time &tm)
        : id(nextId++), title(t), description(d), priority(p), time(tm), completed(false) {}

    Task(const Task &other)
        : id(other.id), title(other.title), description(other.description),
          priority(other.priority), time(other.time), completed(other.completed) {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getDescription() const { return description; }
    string getPriority() const { return priority; }
    Time getTime() const { return time; }
    bool isCompleted() const { return completed; }

    void setId(int newId) { id = newId; }
    static void resetNextId(int v) { nextId = v; }

    void markComplete() {
        if (completed) throw runtime_error("Task already completed.");
        completed = true;
    }

    void update(const string &t, const string &d, const string &p, const Time &tm) {
        title = t; description = d; priority = p; time = tm;
    }

    void displaySummary() const {
        if (completed) setColor(11);
        else if (priority == "High") setColor(12);
        else if (priority == "Medium") setColor(14);
        else setColor(10);

        string titleShort = title;
        if (titleShort.size() > 28) titleShort = titleShort.substr(0, 27) + "...";
        cout << left << setw(6) << id
             << setw(30) << titleShort
             << setw(10) << priority
             << setw(12) << time.getFormatted()
             << setw(10) << (completed ? "Completed" : "Pending") << "\n";

        setColor(7);
    }

    void displayDetail() const {
        if (completed) setColor(11);
        else if (priority == "High") setColor(12);
        else if (priority == "Medium") setColor(14);
        else setColor(10);

        cout << "-------------------------------------------\n";
        setColor(11); cout << "Task ID:    "; setColor(7); cout << id << "\n";
        setColor(11); cout << "Title:      "; setColor(7); cout << title << "\n";
        setColor(11); cout << "Description:"; setColor(7); cout << description << "\n";
        setColor(11); cout << "Priority:   "; setColor(7); cout << priority << "\n";
        setColor(11); cout << "Time:       "; setColor(7); cout << time.getFormatted() << "\n";
        setColor(11); cout << "Status:     "; setColor(7); cout << (completed ? "Completed" : "Pending") << "\n";
        cout << "-------------------------------------------\n";

        setColor(7);
    }

    friend class FileHandler;
};

int Task::nextId = 1;


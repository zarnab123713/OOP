#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <windows.h>
#include <iomanip>
using namespace std;

#define MAX_TASKS 50

// ================= FileHandler =================
class FileHandler {
public:
    static void saveTasks(const Task tasks[], int count, const string &filename) {
        ofstream fout(filename.c_str());
        if (!fout) return;
        fout << count << "\n";
        for (int i = 0; i < count; ++i) {
            fout << tasks[i].title << "|"
                 << tasks[i].description << "|"
                 << tasks[i].priority << "|"
                 << tasks[i].time.getHour() << "|"
                 << tasks[i].time.getMinute() << "|"
                 << (tasks[i].completed ? 1 : 0) << "\n";
        }
        fout.close();
    }

    static int loadTasks(Task tasks[], int maxCount, const string &filename) {
        ifstream fin(filename.c_str());
        if (!fin) return 0;

        int c = 0;
        if (!(fin >> c)) return 0;
        fin.ignore();

        if (c < 0) c = 0;
        if (c > maxCount) c = maxCount;

        for (int i = 0; i < c; ++i) {
            string line;
            if (!getline(fin, line)) break;

            size_t pos = 0, next;
            next = line.find('|', pos); string title = line.substr(pos, next - pos); pos = next + 1;
            next = line.find('|', pos); string desc = line.substr(pos, next - pos); pos = next + 1;
            next = line.find('|', pos); string priority = line.substr(pos, next - pos); pos = next + 1;
            next = line.find('|', pos); string hourStr = line.substr(pos, next - pos); pos = next + 1;
            next = line.find('|', pos); string minuteStr = line.substr(pos, next - pos); pos = next + 1;
            string compStr = line.substr(pos);

            int hour = 0, minute = 0, comp = 0;
            try { hour = stoi(hourStr); minute = stoi(minuteStr); comp = stoi(compStr); } catch (...) {}

            try {
                Time tm(hour, minute);
                tasks[i] = Task(title, desc, priority, tm);
                if (comp != 0) tasks[i].completed = true;
            } catch (...) {
                Time tm(0,0);
                tasks[i] = Task(title, desc, priority, tm);
                if (comp != 0) tasks[i].completed = true;
            }
        }

        int actual = c;
        for (int i = 0; i < actual; ++i) tasks[i].setId(i + 1);
        Task::resetNextId(actual + 1);
        return actual;
    }
};

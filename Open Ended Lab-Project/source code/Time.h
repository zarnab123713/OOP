#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <windows.h>
#include <iomanip>
using namespace std;

#define MAX_TASKS 50


// ================= Time =================
class Time {
private:
    int hour;
    int minute;
public:
    Time() : hour(0), minute(0) {}
    Time(int h, int m) { setTime(h, m); }

    void setTime(int h, int m) {
        if (h < 0 || h > 23 || m < 0 || m > 59) throw invalid_argument("Hour must be 0-23 and minute 0-59.");
        hour = h; minute = m;
    }

    int getHour() const { return hour; }
    int getMinute() const { return minute; }

    string getFormatted() const {
        int displayHour = hour;
        string meridian = "AM";
        if (hour >= 12) { meridian = "PM"; if (hour > 12) displayHour = hour - 12; }
        if (hour == 0) displayHour = 12;

        char buf[10];
        sprintf(buf, "%02d:%02d", displayHour, minute);
        string formatted(buf);
        formatted += " " + meridian;
        return formatted;
    }
};

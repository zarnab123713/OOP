#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <windows.h>
#include <iomanip>

using namespace std;

#define MAX_TASKS 50

// ---------- Console utilities ----------
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void pauseScreen() {
    cout << "\n";
    system("pause");
}

void clearScreen() {
    system("cls");
}

#include"Time.h"
#include"task.h"
#include"filehandler.h"
#include"taskmanager.h"
#include"menu.h"


// ================= main =================
int main() {
    Menu menu("tasks.txt");
    menu.show();
    return 0;
}


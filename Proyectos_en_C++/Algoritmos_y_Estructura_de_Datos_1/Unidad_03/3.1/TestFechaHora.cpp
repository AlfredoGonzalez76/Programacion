#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
using namespace std;

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss

string currentDateTime();

int main() {
    cout << "Fecha y Hora: " << currentDateTime() << endl;
}

string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%d-%m-%Y.%X", &tstruct);

    return buf;
}
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

// Function to convert 12-hour format to 24-hour format
string convertTo24Hour(string time12) {
    stringstream ss(time12);
    string time, ampm;
    int hours, minutes;

    ss >> hours;
    char colon;
    ss >> colon;
    ss >> minutes;
    ss >> ampm;

    if (ampm == "PM" && hours != 12) {
        hours += 12;
    } else if (ampm == "AM" && hours == 12) {
        hours = 0;
    }

    stringstream result;
    result << setfill('0') << setw(2) << hours << ':' << setw(2) << minutes;
    return result.str();
}

// Function to convert 24-hour format to 12-hour format
string convertTo12Hour(string time24) {
    stringstream ss(time24);
    int hours, minutes;
    char colon;

    ss >> hours;
    ss >> colon;
    ss >> minutes;

    stringstream result;
    string ampm = "AM";

    if (hours >= 12) {
        if (hours > 12) {
            hours -= 12;
        }
        ampm = "PM";
    } else if (hours == 0) {
        hours = 12;
    }

    result << setfill('0') << setw(2) << hours << ':' << setw(2) << minutes << ' ' << ampm;
    return result.str();
}

// Function to convert time from EST to GMT
string estToGmt(string time24) {
    stringstream ss(time24);
    int hours, minutes;
    char colon;

    ss >> hours;
    ss >> colon;
    ss >> minutes;

    hours += 5; // EST to GMT is +5 hours

    if (hours >= 24) {
        hours -= 24; // Handle overflow
    }

    stringstream result;
    result << setfill('0') << setw(2) << hours << ':' << setw(2) << minutes;
    return result.str();
}

// Function to convert time from GMT to EST
string gmtToEst(string time24) {
    stringstream ss(time24);
    int hours, minutes;
    char colon;

    ss >> hours;
    ss >> colon;
    ss >> minutes;

    hours -= 5; // GMT to EST is -5 hours

    if (hours < 0) {
        hours += 24; // Handle underflow
    }

    stringstream result;
    result << setfill('0') << setw(2) << hours << ':' << setw(2) << minutes;
    return result.str();
}

// Function to convert time from PST to GMT
string pstToGmt(string time24) {
    stringstream ss(time24);
    int hours, minutes;
    char colon;

    ss >> hours;
    ss >> colon;
    ss >> minutes;

    hours += 8; // PST to GMT is +8 hours

    if (hours >= 24) {
        hours -= 24; // Handle overflow
    }

    stringstream result;
    result << setfill('0') << setw(2) << hours << ':' << setw(2) << minutes;
    return result.str();
}

// Function to convert time from GMT to PST
string gmtToPst(string time24) {
    stringstream ss(time24);
    int hours, minutes;
    char colon;

    ss >> hours;
    ss >> colon;
    ss >> minutes;

    hours -= 8; // GMT to PST is -8 hours

    if (hours < 0) {
        hours += 24; // Handle underflow
    }

    stringstream result;
    result << setfill('0') << setw(2) << hours << ':' << setw(2) << minutes;
    return result.str();
}

// Function to add hours and minutes to a given time
string addTime(string time24, int addHours, int addMinutes) {
    stringstream ss(time24);
    int hours, minutes;
    char colon;

    ss >> hours;
    ss >> colon;
    ss >> minutes;

    minutes += addMinutes;
    hours += addHours + (minutes / 60);
    minutes %= 60;
    hours %= 24;

    stringstream result;
    result << setfill('0') << setw(2) << hours << ':' << setw(2) << minutes;
    return result.str();
}

int main() {
    string time;
    int choice;

    cout << "Time Converter\n";
    cout << "1. Convert 12-hour format to 24-hour format\n";
    cout << "2. Convert 24-hour format to 12-hour format\n";
    cout << "3. Convert EST to GMT\n";
    cout << "4. Convert GMT to EST\n";
    cout << "5. Convert PST to GMT\n";
    cout << "6. Convert GMT to PST\n";
    cout << "7. Add Time\n";
    cout << "Enter your choice (1-7): ";
    cin >> choice;

    cin.ignore(); // Ignore newline character left in the buffer

    if (choice == 1) {
        cout << "Enter time in 12-hour format (e.g., 02:30 PM): ";
        getline(cin, time);
        cout << "Time in 24-hour format: " << convertTo24Hour(time) << endl;
    } else if (choice == 2) {
        cout << "Enter time in 24-hour format (e.g., 14:30): ";
        getline(cin, time);
        cout << "Time in 12-hour format: " << convertTo12Hour(time) << endl;
    } else if (choice == 3) {
        cout << "Enter time in 24-hour format (EST) (e.g., 14:30): ";
        getline(cin, time);
        cout << "Time in GMT: " << estToGmt(time) << endl;
    } else if (choice == 4) {
        cout << "Enter time in 24-hour format (GMT) (e.g., 14:30): ";
        getline(cin, time);
        cout << "Time in EST: " << gmtToEst(time) << endl;
    } else if (choice == 5) {
        cout << "Enter time in 24-hour format (PST) (e.g., 14:30): ";
        getline(cin, time);
        cout << "Time in GMT: " << pstToGmt(time) << endl;
    } else if (choice == 6) {
        cout << "Enter time in 24-hour format (GMT) (e.g., 14:30): ";
        getline(cin, time);
        cout << "Time in PST: " << gmtToPst(time) << endl;
    } else if (choice == 7) {
        int addHours, addMinutes;
        cout << "Enter time in 24-hour format (e.g., 14:30): ";
        getline(cin, time);
        cout << "Enter hours to add: ";
        cin >> addHours;
        cout << "Enter minutes to add: ";
        cin >> addMinutes;
        cout << "New time: " << addTime(time, addHours, addMinutes) << endl;
    } else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}

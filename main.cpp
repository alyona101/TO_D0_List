#include <iostream> 
#include <string> 
#include <vector> 
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Time {
    int second;
    int minute;
    int hour;
};

struct Spisok {
    string title;
    string description;
    string priority;
    Date NewDate;
    Time NewTime;
};

vector<Spisok> to_do_list;

void displayToDoList(Date date) {
    bool found = false;
    cout << "To-Do List for " << date.day << "/" << date.month << "/" << date.year << ":\n";
    for (const auto& task : to_do_list) {
        if (task.NewDate.day == date.day &&
            task.NewDate.month == date.month &&
            task.NewDate.year == date.year) {
            cout << "Title: " << task.title << "\n"
                << "Description: " << task.description << "\n"
                << "Priority: " << task.priority << "\n"
                << "Time: " << task.NewTime.hour << ":"
                << task.NewTime.minute << ":"
                << task.NewTime.second << "\n\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No tasks found for this date.\n";
    }
}

void case_search(Date b) {
    int year1, day1, month1;
    cout << "Enter year, day, and month to search: ";
    cin >> year1 >> day1 >> month1;

    if (year1 == b.year && day1 == b.day && month1 == b.month) {
        cout << "Date found: " << year1 << "-" << month1 << "-" << day1 << endl;
    }
    else {
        cout << "Date not found!" << endl;
    }
}

int main() {
    to_do_list.push_back({ "Buy ", "Milk, Bread, Eggs", "High", {15, 3, 2023}, {14, 30, 0} });
    to_do_list.push_back({ "Doctor appointment", "Check-up", "Medium", {15, 3, 2023}, {10, 0, 0} });
    to_do_list.push_back({ "Meeting", "Project discussion", "Low", {16, 3, 2023}, {9, 0, 0} });

    Date searchDate = { 15, 3, 2023 };
    displayToDoList(searchDate);

}
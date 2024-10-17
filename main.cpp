#include <iostream>
#include <cmath>
#include <vector>
#include <string>
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
    string title; //название 
    string description; //описание 
    string priority; //приоритет
    Date NewSate;
    Time NewTime;
};

vector <Spisok> to_do_list;

void print_Spisok(Spisok& sp)
{
    cout << sp.description << endl;
    cout << sp.title << endl;
    cout << sp.priority << endl;
    cout << sp.NewSate.day << "." << sp.NewSate.month << "." << sp.NewSate.year << endl;
    cout << sp.NewTime.hour << ":" << sp.NewTime.minute << ":" << sp.NewTime.second << endl;
}

void SearchInTheToDoList(string& TheName) {
    int c = 0;

    for (int i = 0; i < to_do_list.size(); i++) {
        if (TheName == to_do_list[i].title) {
            print_Spisok(to_do_list[i]);
            c++;
        }
    }
    if (c == 0)
        cout << "No such to-do list was found" << endl;
}
void case_search(Date b) {
    bool t = false;
    int year1;
    cin >> year1;
    int day1;
    cin >> day1;
    int mounth1;
    cin >> mounth1;
    if (year1 == b.year || day1 == b.day || mounth1 == b.mounth) {
        cout << "Year" << year1 << endl;
        cout << "Day" << day1 << endl;
        cout << "Mounth" << mounth1 << endl;
        t = true;
    }
    else {
        cout << "Date foundn't!!!!!!" << endl;
        t = false;
    }
}

void searchdesc(string descriptionn) {
    int hmf = 0;
    cout << "Найденые дела: " << endl;
    cout << endl;
    for (int i = 0; i < to_do_list.size(); i++) {
        if (descriptionn == to_do_list[i].description) {
            print_Spisok(to_do_list[i]);
            hmf++;
        }
    }
    if (hmf == 0) {
        cout << "Не найдено дел с таким описанием" << endl;
    }
}

void AddingAcase(Spisok& name) {
    cout << "Enter title name:";
    cin >> name.title;
    cout << "Enter title description:";
    cin >> name.description;
    cout << "Enter a description of the title:";
    cin >> name.priority;
    cout << " ";
    to_do_list.push_back(name);
}

void searchInSpisok(Date when) {
    int c = 0;
    string buf = "";
    tm date{};
    date.tm_mday = when.day;
    date.tm_mon = when.month - 1;
    date.tm_year = when.year - 1900;
    time_t timeDate = mktime(&date);
    time_t next = timeDate + 86400;
    char ch[100];
    while (c != 7) {
        for (int i = 0; i < to_do_list.size(); i++) {
            if (to_do_list[i].NewSate.day == when.day && to_do_list[i].NewSate.month == when.month && to_do_list[i].NewSate.year == when.year) {
                //print_Spisok(to_do_list[i]);
                cout << to_do_list[i].title << endl;
            }
        }
        if (strftime(ch, sizeof(ch), "%y %m %d", localtime(&next))) {
            buf += ch[0];
            buf += ch[1];
            when.year = stoi("20" + buf);
            buf = "";
            buf += ch[3];
            buf += ch[4];
            when.month = stoi(buf);
            buf = "";
            buf += ch[6];
            buf += ch[7];
            when.day = stoi(buf);
            buf = "";
        }
        next += 86400;
        c++;
    }
}

void sortByMonth(Date when) {
    vector <Spisok> to_do_listBuf;
    bool flag = 0;
    while (flag == 0) {
        for (int i = 1; i < to_do_list.size(); i++) {
            if (to_do_list[i].NewSate.month == when.month && to_do_list[i].NewSate.year == when.year && to_do_list[i].NewSate.day < to_do_list[i - 1].NewSate.day) {
                for (int j = 0; j < to_do_list.size(); j++) {
                    if (j < i - 1) {
                        to_do_listBuf.push_back(to_do_list[j]);
                    }
                    else if (j == i - 1) {
                        to_do_listBuf.push_back(to_do_list[i]);
                        to_do_listBuf.push_back(to_do_list[j]);
                        j++;
                    }
                    else if (j > i - 1) {
                        to_do_listBuf.push_back(to_do_list[j]);
                    }
                }
                flag = 1;
                to_do_list.clear();
                to_do_list = to_do_listBuf;
                to_do_listBuf.clear();
            }
        }
        if (flag == 1)
            flag = 0;
        else
            flag = 1;
    }
}

void changeNote(Spisok& newNote) {
    string request, newStr;
    cout << "Enter what to change(title, description, priority, date, time)" << endl;
    cin >> request;
    if (request == "title") {
        cout << "Enter new title:" << endl;
        cin >> newStr;
        newNote.title = newStr;
    }
    else if (request == "description:") {
        cout << "Enter new description" << endl;
        cin >> newStr;
        newNote.description = newStr;
    }
    else if (request == "priority") {
        cout << "Enter new priority:" << endl;
        cin >> newStr;
        newNote.priority = newStr;
    }
    else if (request == "date") {
        cout << "Enter new date(at first day, when month and year):" << endl;
        int day, month, year;
        cin >> day;
        cin >> month;
        cin >> year;
        newNote.NewDate.day = day;
        newNote.NewDate.month = month;
        newNote.NewDate.year = year;
    }
    else if (request == "time") {
        cout << "Enter new time(at first seconds, when minutes and hours)" << endl;
        int seconds, minutes, hours;
        cin >> seconds;
        cin >> minutes;
        cin >> hours;
        newNote.NewTime.second = seconds;
        newNote.NewTime.minute = minutes;
        newNote.NewTime.hour = hours;
    }
    else {
        cout << "File did not open(";
    }
}

int main(){
    cout << "Enter the name of the to-do list: ";
    string popa;
    cin >> popa;
    SearchInTheToDoList(popa);
}
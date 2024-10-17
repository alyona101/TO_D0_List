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

int main(){
    cout << "Enter the name of the to-do list: ";
    string popa;
    cin >> popa;
    SearchInTheToDoList(popa);
}
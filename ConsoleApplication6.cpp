#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Date {
	int day;
	int mounth;
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
	Date NewSate;
	Time NewTime;
};
vector <Spisok> to_do_list;
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
void changeNote(Spisok& newNote); //Антон
void searchInSpisok(Date when); //Иван
void SearchInTheToDoList(string TheName); //Ксюша
void AddingACase(Spisok a); //Соня
void print_Spisok(Spisok sp) {

}
int main() {
	Spisok x = { "jsdb", "bd", ";kj",{ 14,12,2024 }, { 15,24,8 } };
	to_do_list.push_back(x);
	Date y = { 14,12,2024 };
	case_search(y);

}
/*#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <Windows.h>
#include <conio.h>
#include <bitset>
using namespace std;
/*vector <string> Split_line(string line)
{
	vector <string> word_mass;
	string word;

	for (const char& i : line) {
		if (i != ' ')
			word += i;
		else
		{
			word_mass.push_back(word);
			word = "";
		}
	}
	word_mass.push_back(word);
	return word_mass;
}
int Help_Relevance(const vector <string>& answ, const vector<string>& s_b_1, vector <string>& lzsjkxlj) {
	int relev = 0;
	for (const string& i : answ) {
		if (find(s_b_1.begin(), s_b_1.end(), i) != s_b_1.end()) {
			++relev;
		}
	}
	return relev;
}
map <int, string> Relevance(string line, const vector <string>& answ, const vector<string>& s_b) {
	map <int, string> resalt;
	for (const string& i : s_b) {
		ifstream in(i);
		string line;
		while (getline(in, line)) {}
		vector <string> lzsjkxlj = Split_line(line);
		int relevance = Help_Relevance(answ, s_b, lzsjkxlj);
		resalt.insert({ relevance, i });
	}
}*/
/*vector <string> Split_line(string line) {
	string num;
	vector <string> num_mass;
	vector <int> primer;
	for (char i : line) {
		if (i != '+' && i != '-' && i != '*' && i != '/') {
			num += i;
		}
		else {
			num_mass.push_back(num);
			num.clear();
			num_mass.push_back(to_string(i));
		}
	}
	return num_mass;
}
vector <string> Calculiator(vector <string> num_mass) {
	vector <string> primer;
	if (find(num_mass.begin(),num_mass.end(), "*") != num_mass.end() || find(num_mass.begin(), num_mass.end(), "/") != num_mass.end()) {
		for (int i = 0; i < num_mass.size(); i++) {
			if (num_mass[i] != "*" && num_mass[i] != "/") {
				primer.push_back(num_mass[i]);
			}
			else {
				if (num_mass[i] == "*") {
					primer.pop_back();
					primer.push_back(to_string(stod(num_mass[i-1]) * stod(num_mass[i + 1])));
					i++;

				}
				else {
					primer.pop_back();
					primer.push_back(to_string(stod(num_mass[i - 1]) / stod(num_mass[i + 1])));
					i++;
				}
			}
		}
	}
	else {
		for (int i = 0; i < num_mass.size(); i++) {
			if (num_mass[i] != "+" && num_mass[i] != "-") {
				primer.push_back(num_mass[i]);
			}
			else {
				if (num_mass[i] == "+") {
					primer.pop_back();
					primer.push_back(to_string(stod(num_mass[i - 1]) + stod(num_mass[i + 1])));
					i++;

				}
				else {
					primer.pop_back();
					primer.push_back(to_string(stod(num_mass[i - 1]) - stod(num_mass[i + 1])));
					i++;
				}
			}
		}
	}
	return primer;
}*/
/*struct figure {
	int x;
	int y;
	int length;
	int height;
};
struct drob {
	int celaia_chast;
	int chisletel;
	int delitel;                                                         
};
int min_delitel(int x, int y) {
	bool nashilos = true;
	while (1) {
		int resalt = max(x, y);
		if (resalt % x == 0 && resalt % y == 0) {
			return resalt;
		}
		else {
			resalt++;
		}
	}
}
drob sum(drob a, drob b) {
	drob sums;
	drob cel;
	if (a.celaia_chast != 0) {
		a.chisletel += (a.celaia_chast * a.delitel);
	}
	if (b.celaia_chast != 0) {
		b.chisletel += (b.celaia_chast * b.delitel);
	}
	if (a.delitel != b.delitel) {
		sums.delitel = min_delitel( a.delitel,b.delitel);
		a.chisletel *= sums.delitel / a.delitel;
		b.chisletel *= sums.delitel / b.delitel;
		sums.chisletel = (a.chisletel + b.chisletel);
	}
	else {
		sums.chisletel = (a.chisletel + b.chisletel);
	}
	if (a.chisletel > a.delitel) {
		cel.celaia_chast = a.chisletel > a.delitel;
	}
	if (b.chisletel > b.delitel) {
		cel.celaia_chast = b.chisletel > b.delitel;
	}
	return sums;
}
void print_Drob(drob a) {
	cout << " " << a.chisletel << endl;
	if (a.celaia_chast != 0) {
		cout << " " << a.celaia_chast << "—" << endl;
	}
	else {
		cout << " " << "—" << endl;
	}
	cout << " " << a.delitel << endl;
}
int main() {
	drob f1 = { 1,5,6 };
	drob f2 = { 2,3,12 };
	drob res = sum(f1, f2);
	print_Drob(res);
}*/
	/*figure Prymoygolnik{15,5,5,5};
	cout << Prymoygolnik.length << endl;
	for (int i = 0; i < Prymoygolnik.y; i++) {
		cout << endl;
	}
	for (int i = 0; i < Prymoygolnik.x; i++) {
		cout << ' ';
	}
	cout << ' ';
	for (int i = 0; i < Prymoygolnik.length; i++) {
		cout << "-";
	}
	cout << endl;
	for (int j = 0; j < Prymoygolnik.x; j++) {
		cout << " ";
	}
	for (int i = 0; i < Prymoygolnik.height; i++) {
		cout << '|';
		for (int j = 0; j < Prymoygolnik.length; j++) {
			cout << ' ';
		}
		cout << '|' << endl;
		for (int i = 0; i < Prymoygolnik.x; i++) {
			cout << ' ';
		}
	}
	for (int i = 0; i < Prymoygolnik.height; i++) {
		cout << "-";
	}
	cout << endl;
}
	/*cout << "Enter length";
	cin >> ABCD.length;
	cout << "Enter height";
	cin >> ABCD.height;*/
	/*string line;
	getline(cin, line);
	vector <string> resalt = Split_line(line);
	vector <string> search_database = { "second_answer.txt", "first_answer.txt" };*/
	/*string line;
	getline(cin, line);
	vector <string> num_mass = Split_line(line);
	while (num_mass.size() > 1) {
		Calculiator(num_mass);
		vector <string> num_mass = Calculiator(num_mass);
	}
	for (int i = 0; i < num_mass.size(); i++) {
		cout << num_mass[i] << endl;
	}*/
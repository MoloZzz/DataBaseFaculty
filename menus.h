#pragma once
#include<iostream>
#include<fstream>
using namespace std;

fstream Ffile;
ofstream OFfile;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); 


void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}



void menu_disciplines() {
	
	system("cls");
	cout << "Disciplines`s actions(enter number):" << endl;
	cout << "1) print" << endl;
	cout << "2) add" << endl;
	cout << "0) back" << endl;
	ifstream IFfile;

	int a = 0;
	cin >> a;
	if (a == 0) {
		return;
	}

	if (a == 1) {
		IFfile.open("c:\\Users\\medoc\\source\\repos\\DataBaseFaculty\\txt_documents\\Disciplines.txt");
		
		string s;
		getline(IFfile, s);
		int count = atoi(s.c_str());
		cout << "This list has entries: " << count << endl;
		Sleep(500);
	}
}

void menu_groups() {
	system("cls");
	cout << "Groups`s actions(enter number):" << endl;
	cout << "1) print" << endl;
	cout << "2) add" << endl;
	cout << "0) back" << endl;

	int a = 0;
	cin >> a;
	if (a == 0) {
		return;
	}
	ifstream IFfile;
	if (a == 1) {
		IFfile.open("c:\\Users\\medoc\\source\\repos\\DataBaseFaculty\\txt_documents\\Groups.txt");
		string s;
		getline(IFfile, s);
		int count = atoi(s.c_str());
		cout << "This list has entries: " << count << endl;

		Sleep(500);
	}

}

void menu_works() {
	system("cls");
	cout << "Works`s actions(enter number):" << endl;
	cout << "1) print" << endl;
	cout << "2) add" << endl;
	cout << "0) back" << endl;

	int a = 0;
	cin >> a;
	if (a == 0) {
		return;
	}
	ifstream IFfile;
	if (a == 1) {
		IFfile.open("c:\\Users\\medoc\\source\\repos\\DataBaseFaculty\\txt_documents\\Works.txt");

		string s;
		getline(IFfile, s);
		int count = atoi(s.c_str());
		cout << "This list has entries: " << count << endl;

		Sleep(500);
	}

}


void menu_students() {
	system("cls");
	cout << "Students`s actions(enter number):" << endl;
	cout << "1) print" << endl;
	cout << "2) add" << endl;
	cout << "3) print by index" << endl;
	cout << "0) back" << endl;

	int a = 0;
	cin >> a;
	if (a == 0) {
		return;
	}

	ifstream IFfile;
	IFfile.open("c:\\Users\\medoc\\source\\repos\\DataBaseFaculty\\txt_documents\\Students.txt");

	string s;
	getline(IFfile, s);
	const int a1 = 30;
	const int count = atoi(s.c_str());
	student newStudent[a1];
	for (int i = 0; i < count; i++) {
		getline(IFfile, s);
		newStudent[i].ID_Student = atoi(s.c_str());
		getline(IFfile, s);
		newStudent[i].name = s;
		getline(IFfile, s);
		newStudent[i].contract_number = atoi(s.c_str());
		getline(IFfile, s);
		newStudent[i].studing_type = s;
		getline(IFfile, s);
		newStudent[i].place_raiting = atoi(s.c_str());
		getline(IFfile, s);
		newStudent[i].ID_Group = atoi(s.c_str());
	}

	if (a == 1) {
		
		cout << "This list has entries: " << count << endl;

		student newStudent[a1];
		for (int i = 0; i < count; i++) {
			newStudent[i].print();
		}
		int b = _getch();
		
		if (a == 2) {
			


        }
		if (a == 3) {
			cout << "enter index: " << endl;
			int index;
			cin >> index;
			if (index < count) {
				newStudent[index].print();

			}
			else {
				cout << "index more then all students count" << endl;
			}


		}
		menu_students();
	}
}

void menu_teachers() {
	
	system("cls");
	cout << "Teachers`s actions(enter number):" << endl;
	cout << "1) print all" << endl;
	cout << "2) add" << endl;
	cout << "3) print by index" << endl;
	cout << "0) back" << endl;

	int a = 0;
	cin >> a;
	if (a == 0) {
		return;
	}
	ifstream IFfile;
	if (a == 1) {
		IFfile.open("c:\\Users\\medoc\\source\\repos\\DataBaseFaculty\\txt_documents\\Teachers.txt");

		string s;
		getline(IFfile, s);
		int count = atoi(s.c_str());
		cout << "This list has entries: " << count << endl;
		Sleep(500);
	}
}
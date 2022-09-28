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
	IFfile.open("c:\\Users\\rsngn\\Source\\Repos\\DataBaseFaculty\\txt_documents\\Students.txt");

	string s;
	int wait;
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
		for (int i = 0; i < count; i++) {
			newStudent[i].print();
			
		}
		wait = _getch();
	}
		if (a == 2) {
			fstream Ffile;
			Ffile.open("c:\\Users\\rsngn\\Source\\Repos\\DataBaseFaculty\\txt_documents\\Students.txt",ios_base::app);
			
			cout << "Enter Student ID" << endl;
			int student_ID;
			tryAgain:
			cin>> student_ID;
			if (student_ID > 0 && student_ID < 9999) {
				Ffile << student_ID;
				Ffile << "\n";
			}
			else {
				cout << "wrong ID, try again" << endl;
				goto tryAgain;
			}

			cout << "Enter Student name(only name, without surname) " << endl;
			string student_name;
			tryAgain1:
			cin >> student_name;
			if (student_name.size() < 3) {
				cout << "name so short,try again" << endl;
				goto tryAgain1;
			}
			else {
				Ffile << student_name;
				Ffile << " ";
			}

			cout << "Enter Student surname(only surname , without name) " << endl;
			string student_surname;
			tryAgain2:
			cin >> student_surname;
			if (student_surname.size() < 3) {
				cout << "surname so short,try again" << endl;
				goto tryAgain2;
			}
			else {
				Ffile << student_surname;
				Ffile << "\n";
			}

			cout << "Enter contract(between 0 and 9999) " << endl;
			int contract_number;
			tryAgain3:
			cin >> contract_number;
			if (contract_number < 0 || contract_number > 9999) {
				cout << "wrong contract number" << endl;
				goto tryAgain3;
			}
			else {
				Ffile << contract_number;
				Ffile << "\n";
			}

			cout << "Enter type studing_type" << endl;
			string studing_type;	
			Ffile << studing_type;
			Ffile << "\n";

			cout << "Enter place raiting(between 1 and 1_000) " << endl;
			int place_raiting;
			tryAgain4:
			cin >> place_raiting;
			if (place_raiting < 1 || place_raiting > 1000) {
				cout << "wrong contract number" << endl;
				goto tryAgain4;
			}
			else {
				Ffile << place_raiting;
				Ffile << "\n";
			}

			cout << "Enter group ID(between 0 and 10_000) " << endl;
			int ID_Group;
			tryAgain5:
			cin >> ID_Group;
			if (ID_Group < 0 || ID_Group > 10000) {
				cout << "wrong group ID" << endl;
				goto tryAgain5;
			}
			else {
				Ffile << ID_Group;
				Ffile << "\n";
			}

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
			wait = _getch();
			
		}
		menu_students();
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
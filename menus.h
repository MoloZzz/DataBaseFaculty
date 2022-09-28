#pragma once
#include<iostream>

using namespace std;


void menu_disciplines() {
	cout << "\n1) print" << endl;
	cout << "2) add" << endl;
	cout << "0) back" << endl;

	int di = 0;
	cin >> di;
}

void menu_groups() {
	cout << "\n1) print" << endl;
	cout << "2) add" << endl;
	cout << "0) back" << endl;

	int gr = 0;
	cin >> gr;

}

void menu_works() {
	cout << "\n1) print" << endl;
	cout << "2) add" << endl;
	cout << "0) back" << endl;

	int wo = 0;
	cin >> wo;

}

void menu_students() {
	cout << "\n1) print" << endl;
	cout << "2) add" << endl;
	cout << "0) back" << endl;

	int st = 0;
	cin >> st;

}

void menu_teachers() {

	cout << "\n1) print" << endl;
	cout << "2) add" << endl;
	cout << "0) back" << endl;

	int te = 0;
	cin >> te;
	if (te == 0) {
		return;
	}
}
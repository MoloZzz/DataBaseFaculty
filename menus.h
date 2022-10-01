#pragma once

#include<iostream>
#include<fstream>

using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	string file_way = "c:\\Users\\medoc\\source\\repos\\DataBaseFaculty\\txt_documents\\";
	string file_way_students = file_way + "Students.txt";
	string file_way_teachers = file_way + "Teachers.txt";
	string file_way_groups = file_way + "Groups.txt";
	string file_way_disciplines = file_way + "Disciplines.txt";
	string file_way_works = file_way + "Works.txt";



void menu_disciplines() {

	system("cls");
	cout << "\t\tDisciplines`s actions(enter number):" << endl;
	cout << "(1) print" << endl;
	cout << "(2) add" << endl;
	cout << "(0) back" << endl;
	ifstream IFfile;

	int wait = 0;
	int a = 0;
	cin >> a;
	if (a == 0) {
		return;
	}

	if (a == 1) {
		IFfile.open(file_way_disciplines);
		if (IFfile.is_open() != 1) {
			cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
			wait = _getch();
			a == 0;
			return;
		}

		string s;
		getline(IFfile, s);
		int count = atoi(s.c_str());
		cout << "This list has entries: " << count << endl;
		Sleep(500);
	}

	menu_disciplines();
}

void menu_groups() {
	system("cls");
	cout << "\t\tGroups`s actions(enter number):" << endl;
	cout << "(1) Print" << endl;
	cout << "(2) Add" << endl;
	cout << "(3) Print by ID" << endl;
	cout << "(4) Print students of group by ID" << endl;
	cout << "(0) Back" << endl;

	int wait = 0;

	int a = 0;
	cin >> a;
	if (a == 0) {
		return;
	}



	ifstream IFfile;
	IFfile.open(file_way_groups);

	if (IFfile.is_open() != 1) {
		cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
		wait = _getch();
		a == 0;
		return;
	}

	string s;
	group groups[10];

	getline(IFfile, s);
	int count = atoi(s.c_str());

	for (int i = 0; i < count; i++) {
		getline(IFfile, s);
		groups[i].ID_Group = atoi(s.c_str());
		getline(IFfile, s);
		groups[i].name = s;
		getline(IFfile, s);
		groups[i].head_student = s;
		getline(IFfile, s);
		groups[i].students_amount = atoi(s.c_str());
	}

	if (a == 1) {
		cout << "This list has entries: " << count << endl;
		for (int i = 0; i < count; i++) {
			groups[i].print();
			cout << endl;
		}

		wait = _getch();
	}

	if (a == 2) {

		fstream Ffile;
		Ffile.open(file_way_groups, ios_base::app);

		if (Ffile.is_open() != 1) {
			cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
			wait = _getch();
			a == 0;
			return;
		}


		int id_group = 2001;
		if (count != 0) {
			id_group = groups[count - 1].ID_Group + 1;
		}



		string group_name;
		cout << "Enter name of new group(without number,example: PI) " << endl;
		cin >> group_name;

		cout << "Enter number of new group(without name,example: 12) " << endl;
		int numb;
		cin >> numb;

		string snumb = to_string(numb);
		string group_name_numb = group_name + "-" + snumb;


		ifstream IFfileStudents;


		cout << "Choose ID of head student of this group(1,2,3....)" << endl;

		IFfileStudents.open(file_way_students);
		if (IFfile.is_open() != 1) {
			cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
			wait = _getch();
			a == 0;
			return;
		}
		getline(IFfileStudents, s);

		int count_students = atoi(s.c_str());

		student newStudent[300];
		int stud_ids[300] = {};
		int y = 0;

		for (int i = 0; i < count_students; i++) {
			getline(IFfileStudents, s);
			newStudent[i].ID_Student = atoi(s.c_str());
			getline(IFfileStudents, s);
			newStudent[i].name = s;
			getline(IFfileStudents, s);
			newStudent[i].contract_number = atoi(s.c_str());
			getline(IFfileStudents, s);
			newStudent[i].studing_type = s;
			getline(IFfileStudents, s);
			newStudent[i].place_raiting = atoi(s.c_str());
			getline(IFfileStudents, s);
			newStudent[i].ID_Group = atoi(s.c_str());

			if (newStudent[i].ID_Group == id_group) {
				cout << y+1 << ") Student of this group name: " << newStudent[i].name << endl;
				cout << "His ID: " << newStudent[i].ID_Student << endl;
				stud_ids[y] = newStudent[i].ID_Student;
				y++;
			}
		}
		string name_head;
		cout << "Enter ID head student of this group" << endl;
		int entered_id = 0;
		bool check8 = false;
		while (!check8) {
			cin >> entered_id;
			for (int i = 0; i < y; i++) {
				if (stud_ids[i] == entered_id) {
					cout << "Head student succsesfully added" << endl;
					check8 = true;
				}
			}
			cout << "Error,you entered wrong ID,try again" << endl;
		}

		for (int i = 0; i < count_students; i++) {
			if (newStudent[i].ID_Student == entered_id) {
				name_head = newStudent[i].name;
			}
		}

			
		

	
		cout << "enter students amount of this group: " << std::endl;
		int group_amount;
		cin >> group_amount;


		Ffile << id_group << endl;

		Ffile << group_name_numb << endl;

		Ffile << name_head << endl;
		Ffile << group_amount<< endl;
		Ffile.close();
		Ffile.open(file_way_groups);
		Ffile << count +1;
	}

	menu_groups();
}

void menu_students() {
	system("cls");
	cout << "\t\tStudents`s actions(enter number):" << endl;
	cout << "(1) Print all" << endl;
	cout << "(2) Add" << endl;
	cout << "(3) Print by index(list number)" << endl;
	cout << "(4) Print by ID" << endl;
	cout << "(0) Back" << endl;

	int wait = 0;

	int a = 0;
	cin >> a;

	if (a == 0) {
		return;
	}

	ifstream IFfile;
	IFfile.open(file_way_students);

	if (IFfile.is_open() != 1) {
		cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
		wait = _getch();
		a == 0;
		return;
	}

	string s; // елемент для считки з файлу

	getline(IFfile, s);


	int count = atoi(s.c_str());
	student newStudent[300];

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
		Ffile.open(file_way_students, ios_base::app);

		if (Ffile.is_open() != 1) {
			cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
			wait = _getch();
			a == 0;
			return;
		}

		int student_ID = 0;
		string student_name = "";
		string student_surname = "";
		int contract_number = 0;
		string studing_type = "";
		int place_raiting;
		int ID_Group = 0;

		student_ID = newStudent[count - 1].ID_Student;

		cout << "Enter Student name(only name,without surname) " << endl;
		bool check1 = false;
		while (!check1) {
			cin >> student_name;
			if (student_name.size() < 2 || student_name.size() > 10) {
				cout << "Incorrect name, try again" << endl;
				student_name = "";
			}
			else {
				check1 = true;
			}
		}

		cout << "Enter Student surname(only name,without name) " << endl;
		bool check2 = false;
		while (!check2) {
			cin >> student_surname;
			if (student_surname.size() < 2) {
				cout << "surname so short,try again" << endl;
			}
			else {
				check2 = true;
			}
		}


		cout << "Enter contract " << endl;
		bool check3 = false;
		while (!check3) {
			cin >> contract_number;
			if (contract_number < 4200 || contract_number > 4999) {
				cout << "Wrong contract number, try again! contract number is 4200-4999" << endl;
			}
			else {
				check3 = true;
			}
		}


		cout << "Enter type of studing " << endl;
		bool check4 = false;
		while (!check4) {
			cin >> studing_type;
			if (studing_type == "Full" || studing_type == "Half") {
				check4 = true;
			}
			else {
				cout << "Wrong type of studing, there are 2 types: Full and Half,try again" << endl;
			}
		}

		cout << "Enter place raiting" << endl;

		bool check5 = false;
		while (!check5) {
			cin >> place_raiting;
			if (place_raiting < 1 || place_raiting > 999) {
				cout << "Wrong place rating,try again, place can be from 1 to 999" << endl;
			}
			else {
				check5 = true;
			}
		}
	

		cout << "Enter group ID " << endl;
		bool check6 = false;
		while (!check6) {
			cin >> ID_Group;
			if (ID_Group < 2000 || ID_Group > 2100) {
				cout << "Wrong group ID! Group ID is only from 2000 to 2100" << endl;
			}
			else {
				check6 = true;
			}
		}


		Ffile << student_ID + 1 << endl;
		Ffile << student_name << " " << student_surname << endl;
		Ffile << contract_number << endl;
		Ffile << studing_type << endl;
		Ffile << place_raiting << endl;
		Ffile << ID_Group << endl;

		Ffile.close();

		Ffile.open(file_way_students);
		Ffile << count + 1;

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

	if (a == 4) {
		cout << "Enter ID of student that u want to find" << endl;
		string stud_id;
		bool check7 = false;
		if (!check7) {
			cin >> stud_id;
			for (int i = 0; i < count; i++) {
				if (newStudent[i].ID_Student == atoi(stud_id.c_str())) {
					newStudent[i].print();
					wait = _getch();
					check7 = true;
				}
			}
			cout << "There are not student with this ID" << endl;
		}
	}

	menu_students();
}

void menu_teachers() {

	system("cls");
	cout << "\t\tTeachers`s actions(enter number):" << endl;
	cout << "(1) print all" << endl;
	cout << "(2) add" << endl;
	cout << "(3) print by ID" << endl;
	cout << "(0) back" << endl;


	int wait = 0;

	int a = 0;
	cin >> a;
	if (a == 0) {
		return;
	}
	ifstream IFfile;
    IFfile.open(file_way_teachers);

	if (IFfile.is_open() != 1) {
		cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
		wait = _getch();
		a == 0;
		return;
	}


    string s;
	getline(IFfile, s);
    int count = atoi(s.c_str());

    


	if (a == 1) {
		


		cout << "This list has entries: " << count << endl;
		Sleep(1000);
	}
	menu_teachers();
}

void menu_works() {
	system("cls");
	cout << "\t\tWorks`s actions(enter number):" << endl;
	cout << "(1) print" << endl;
	cout << "(2) add" << endl;
	cout << "(0) back" << endl;
	int wait = 0;

	int a = 0;
	cin >> a;

	if (a == 0) {
		return;
	}

	ifstream IFfile;
    IFfile.open(file_way_works);

	if (IFfile.is_open() != 1) {
		cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
		wait = _getch();
		a == 0;
		return;
	}

    string s;
	getline(IFfile, s);
	int count = atoi(s.c_str());

	if (a == 1) {

		cout << "This list has entries: " << count << endl;

		Sleep(500);
	}
	menu_works();
}

void menu_errors() {
	system("cls");
	cout <<" \t Base files : " << endl;
	fstream file;

	file.open(file_way_disciplines);
	if (file.is_open() == 1) {
		cout << "Disciplines.txt" << endl;
	}
	else {
		cout << "Error with list - Disciplines.txt / is not connected" << endl;
	}
	file.close();
	file.open(file_way_groups);
	if (file.is_open() == 1) {
		cout << "Groups.txt" << endl;
	}
	else {
		cout << "Error with list - Groups.txt / is not connected" << endl;
	}
	file.close();
	file.open(file_way_students);
	if (file.is_open() == 1) {
		cout << "Students.txt" << endl;
	}
	else {
		cout << "Error with list - Students.txt / is not connected" << endl;
	}
	file.close();
	file.open(file_way_teachers);
	if (file.is_open() == 1) {
		cout << "Teachers.txt" << endl;
	}
	else {
		cout << "Error with list - Teachers.txt / is not connected" << endl;
	}
	file.close();
	file.open(file_way_works);
	if (file.is_open() == 1) {
		cout << "Disciplines.txt" << endl;
	}
	else {
		cout << "Error with list - Works.txt / is not connected" << endl;
	}
	file.close();
	cout << "\nPress any key to back main menu";


	int wait = 0;
	wait = _getch();


}
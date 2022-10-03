#pragma once

#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void d(short x, short y)
{
	SetConsoleCursorPosition(h, { x,y });
}

	string file_way = "c:\\Users\\Yura\\source\\repos\\DataBaseFaculty\\txt_documents\\";
	string file_way_students = file_way + "Students.txt";
	string file_way_teachers = file_way + "Teachers.txt";
	string file_way_groups = file_way + "Groups.txt";
	string file_way_disciplines = file_way + "Disciplines.txt";
	string file_way_works = file_way + "Works.txt";

	

void get_file_students(student newStudent[300],int &count_students) {
	ifstream IFfile_students;
	IFfile_students.open(file_way_students);
	if (!IFfile_students.is_open()) {
		cout << "Error with file Students.txt" << endl;
		return;
	}
	string s;
	getline(IFfile_students, s);
	count_students = atoi(s.c_str());  

	for (int i = 0; i < count_students; i++) {
		getline(IFfile_students, s);
		newStudent[i].ID_Student = atoi(s.c_str());
		getline(IFfile_students, s);
		newStudent[i].name = s;
		getline(IFfile_students, s);
		newStudent[i].contract_number = atoi(s.c_str());
		getline(IFfile_students, s);
		newStudent[i].studing_type = s;
		getline(IFfile_students, s);
		newStudent[i].place_raiting = atoi(s.c_str());
		getline(IFfile_students, s);
		newStudent[i].ID_Group = atoi(s.c_str());
	}

}

void get_file_works(work works[300], int& count_works) {
	ifstream IFfile_works;
	IFfile_works.open(file_way_works);
	if (!IFfile_works.is_open()) {
		cout << "Error with file Works.txt" << endl;
		return;
	}
	string s;
	getline(IFfile_works, s);
	count_works = atoi(s.c_str());

	for (int i = 0; i < count_works; i++) {
		getline(IFfile_works, s);
		works[i].ID_Work = atoi(s.c_str());
		getline(IFfile_works, s);
		works[i].ID_Student = atoi(s.c_str());
		getline(IFfile_works, s);
		works[i].ID_Teacher = atoi(s.c_str());
		getline(IFfile_works, s);
		works[i].ID_Discipline = atoi(s.c_str());
		getline(IFfile_works, s);
		works[i].work_type = s;
		getline(IFfile_works, s);
		works[i].date_def = s;
		getline(IFfile_works, s);
		works[i].topic = s;
	}

}

void get_file_disciplines(discipline disciplines[300], int& count_disciplines) {
	ifstream IFfile_disciplines;
	IFfile_disciplines.open(file_way_disciplines);
	if (!IFfile_disciplines.is_open()) {
		cout << "Error with file Disciplines.txt" << endl;
		return;
	}
	string s;
	getline(IFfile_disciplines, s);
	count_disciplines = atoi(s.c_str());

	for (int i = 0; i < count_disciplines; i++) {
		getline(IFfile_disciplines, s);
		disciplines[i].ID_Discipline = atoi(s.c_str());
		getline(IFfile_disciplines, s);
		disciplines[i].name = s;
		getline(IFfile_disciplines, s);
		disciplines[i].ID_teacher = atoi(s.c_str());
		getline(IFfile_disciplines, s);
		disciplines[i].date_exam = s;
		getline(IFfile_disciplines, s);
		disciplines[i].mark = atoi(s.c_str());
		getline(IFfile_disciplines, s);
		disciplines[i].obligation = s;

	}
}

void get_file_teachers(teacher teachers[300],int &count_teachers) {
	ifstream IFfile_teachers;
	IFfile_teachers.open(file_way_teachers);
	if (!IFfile_teachers.is_open()) {
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		cout << "Error with file Teachers.txt" << endl;
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
		return;
	}
	string s;
	getline(IFfile_teachers, s);
	count_teachers = atoi(s.c_str());

	for (int i = 0; i < count_teachers; i++) {
		getline(IFfile_teachers, s);
		teachers[i].ID_teacher = atoi(s.c_str());
		getline(IFfile_teachers, s);
		teachers[i].name = s;
		getline(IFfile_teachers, s);
		teachers[i].ID_discipline = atoi(s.c_str());
		getline(IFfile_teachers, s);
		teachers[i].graduation = s;
	}
}

void get_file_groups(group groups[300],int &count_groups) {
	ifstream IFfile_groups;
	IFfile_groups.open(file_way_groups);
	if (!IFfile_groups.is_open()) {
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		cout << "Error with file Groups.txt" << endl;
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
		return;
	}
	string s;
	getline(IFfile_groups, s);
	count_groups = atoi(s.c_str());

	for (int i = 0; i < count_groups; i++) {
		getline(IFfile_groups, s);
		groups[i].ID_Group = atoi(s.c_str());
		getline(IFfile_groups, s);
		groups[i].name = s;
		getline(IFfile_groups, s);
		groups[i].head_student = s;
		getline(IFfile_groups, s);
		groups[i].students_amount = atoi(s.c_str());
	}
}

bool check_numbers(string s) {
	int k = 0, i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9') {
			k++;
			return 1; 
		}
		i++;
	}

	if (k == 0) return 0;
}



void menu_disciplines() {

	system("cls");
	cout << "\t\tDisciplines`s actions(enter number):" << endl;
	cout << "(1) print" << endl;
	cout << "(2) add" << endl;
	cout << "(0) back" << endl;
	ifstream IFfile;
	IFfile.open(file_way_disciplines);
	string s;
	getline(IFfile, s);
	int count_disciplines = atoi(s.c_str());
	int wait = 0;
	int a = 0;
	cin >> a;

	if (a == 0) {
		return;
	}

	discipline disciplines[300];
	get_file_disciplines(disciplines, count_disciplines);

	if (a == 1) {
		IFfile.open(file_way_disciplines);

		if (IFfile.is_open() != 1) {
			cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
			wait = _getch();
			a = 0;
			return;
		}
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);
		cout << "This list has entries: " << count_disciplines << endl;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		for (int i = 0; i < count_disciplines; i++) {
			disciplines[i].print();
		}
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		wait = _getch();
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
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
		wait = _getch();
		a = 0;
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		return;
	}

	string s;
	group groups[300];

	getline(IFfile, s);
	int count = atoi(s.c_str());
	get_file_groups(groups,count);
	

	ifstream IFfileStudents;

	IFfileStudents.open(file_way_students);
	if (IFfile.is_open() != 1) {
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
		wait = _getch();
		a = 0;

		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		return;
	}
	getline(IFfileStudents, s);

	int count_students = atoi(s.c_str());

	student newStudent[300];
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
	}

	if (a == 1) {
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);
		cout << "This list has entries: " << count << endl;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		for (int i = 0; i < count; i++) {
			groups[i].print();
			cout << endl;
		}
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		wait = _getch();
	}

	if (a == 2) {
		
		int id_group = 2001;
		string group_name;
        int numb = 0;
		string name_head;
		int group_amount;


		fstream Ffile;
		Ffile.open(file_way_groups, ios_base::app);

		if (Ffile.is_open() != 1) {
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
			wait = _getch();
			a = 0;
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			return;
		}

		if (count != 0) {
			id_group = groups[count - 1].ID_Group + 1;
		}

		SetConsoleTextAttribute(h, 5);
		cout << "Are u sure? U should enter name,group number and choose head student(only from students in our base!!!)" << endl;
		cout << " This will be group with ID: " << id_group << endl;
		SetConsoleTextAttribute(h, FOREGROUND_RED|FOREGROUND_INTENSITY);
		cout << " WARNING! " << endl;
		SetConsoleTextAttribute(h, 6);
		cout << "Press BACKSPACE to back menu" << endl;
		SetConsoleTextAttribute(h, 3);
		cout << "Or other bottom to continue" << endl;
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		wait = _getch();
		if (wait == 8) {
			return;
		}






		cout << "Enter name of new group(without number,example: PI) " << endl;


			cin >> group_name;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << "Succsesfully added name :" << group_name << endl;
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		cout << "Enter number of new group(without name,example: 12) " << endl;
		cin >> numb;
			
		string snumb = to_string(numb);
		string group_name_numb = group_name + "-" + snumb;

        cout << "\tChoose head student of this group: " << endl;

		int stud_ids[300] = {};
		int y = 0;

		for (int i = 0; i < count_students; i++) {
			if (newStudent[i].ID_Group == id_group) {
				cout << y+1 << ") Student of this group name: " << newStudent[i].name << endl;
				cout << " His ID: " << newStudent[i].ID_Student << endl;
				stud_ids[y] = newStudent[i].ID_Student;
				y++;
			}
		}

		cout << "Enter ID head student of this group" << endl;
		int entered_id = 0;
		bool check8 = false;
		int checker = 0;
		while (check8 == false) {
			cin >> entered_id;
			for (int i = 0; i < y; i++) {
				if (stud_ids[i] == entered_id) {
					SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					cout << "Head student succsesfully added" << endl;
					check8 = true;
					checker = 1;
					SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
			}
			if (checker != 1) {
				SetConsoleTextAttribute(h, FOREGROUND_RED);
				cout << "Error,you entered wrong ID,try again" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
		}

		for (int i = 0; i < count_students; i++) {
			if (newStudent[i].ID_Student == entered_id) {
				name_head = newStudent[i].name;
			}
		}

			
		
		cout << "Enter students amount of this group(3-50): " << std::endl;
		bool check2 = false;
		while (!check2) {
			cin >> group_amount;
			if (group_amount > 3 || group_amount < 50) {
				check2 = true;
			}
			else {
				SetConsoleTextAttribute(h, FOREGROUND_RED);
				cout << "Wrong enter, amount can be from 3 to 50,try again!" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
		}

		Ffile << id_group << endl;
		Ffile << group_name_numb << endl;
		Ffile << name_head << endl;
		Ffile << group_amount<< endl;

		Ffile.close();
		Ffile.open(file_way_groups);
		Ffile << count +1;
	}
	
	if (a == 4) {
		cout << "Enter id of group that u finding"<< endl;
		int entered_id = 0;
		cin >> entered_id;
		cout << "This group students: " << endl;
		for (int i = 0; i < count_students; i++) {
			if (newStudent[i].ID_Group == entered_id) {
				newStudent[i].print();
			}
		}
		wait = _getch();
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
	cout << "(5) Delete by ID" << endl;
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
		a = 0;
		return;
	}

	string s; // ������� ��� ������ � �����

	getline(IFfile, s);


	int count_students = atoi(s.c_str());
	student newStudent[300];

	//for (int i = 0; i < count; i++) {
	//	getline(IFfile, s);
	//	newStudent[i].ID_Student = atoi(s.c_str());
	//	getline(IFfile, s);
	//	newStudent[i].name = s;
	//	getline(IFfile, s);
	//	newStudent[i].contract_number = atoi(s.c_str());
	//	getline(IFfile, s);
	//	newStudent[i].studing_type = s;
	//	getline(IFfile, s);
	//	newStudent[i].place_raiting = atoi(s.c_str());
	//	getline(IFfile, s);
	//	newStudent[i].ID_Group = atoi(s.c_str());
	//}

	get_file_students(newStudent, count_students);


	if (a == 1) {
		SetConsoleTextAttribute(h, FOREGROUND_BLUE );
		cout << "This list has entries: " << count_students<< endl;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		for (int i = 0; i < count_students; i++) {
			newStudent[i].print();

		}
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		wait = _getch();
	}

	if (a == 2) {

		SetConsoleTextAttribute(h, 5);
		cout << "Are u sure? U should enter name,contract number,styding type,place raiting,ID group" << endl;
		SetConsoleTextAttribute(h, 6);
		cout << "Press BACKSPACE to back menu" << endl;
		SetConsoleTextAttribute(h, 3);
		cout << "Or other bottom to continue" << endl;
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		wait = _getch();
		if (wait == 8) {
			return;
		}

		fstream Ffile;
		Ffile.open(file_way_students, ios_base::app);

		if (Ffile.is_open() != 1) {
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			wait = _getch();
			a = 0;
			return;
		}

		int student_ID = 0;
		string student_name = "";
		string student_surname = "";
		int contract_number = 0;
		string studing_type = "";
		int place_raiting;
		int ID_Group = 0;

		student_ID = newStudent[count_students - 1].ID_Student;

		cout << "Enter student name(ONLY NAME,without surname): " << endl;
		bool check1 = false;
		while (!check1) {
			cin >> student_name;
			if (( student_name.size() < 2 || student_name.size() > 10)) {
				SetConsoleTextAttribute(h, FOREGROUND_RED);
				cout << "Incorrect name, try again" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				student_name = "";
			}
			else {
				check1 = true;
			}
		}

		cout << "Enter student surname(ONLY SURNAME,without name): " << endl;
		bool check2 = false;
		while (!check2) {
			cin >> student_surname;
			if (student_surname.size() < 2) {
				SetConsoleTextAttribute(h, FOREGROUND_RED);
				cout << "Entered surname so short,try again" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else {
				check2 = true;
			}
		}


		cout << "Enter contract(4200-4999): " << endl;
		bool check3 = false;
		bool check_contrack_number = false;
		while (!check3) {
			check_contrack_number = false;
			cin >> contract_number;
			if (contract_number < 4200 || contract_number > 4999) {
				SetConsoleTextAttribute(h, FOREGROUND_RED);
				cout << "Wrong contract number, try again! contract number is 4200-4999" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else {
				for (int i = 0; i < count_students; i++) {
					if (newStudent[i].contract_number == contract_number)
						check_contrack_number = true;
				}
				if (!check_contrack_number) {
					check3 = true;
				}
				else {
					SetConsoleTextAttribute(h, 3);
					cout << "A student with this contract number already exists, check the data and try again." << endl;
					SetConsoleTextAttribute(h, FOREGROUND_GREEN);
				}
			}
		}


		cout << "Enter type of studing(Half or Full) " << endl;
		bool check4 = false;
		while (!check4) {
			cin >> studing_type;
			if (studing_type == "Full" || studing_type == "Half" || studing_type == "full" || studing_type == "half") {
				if (studing_type == "full")
					studing_type = "Full";
				if (studing_type == "half")
					studing_type = "Half";

				check4 = true;
				
			}
			else {
				SetConsoleTextAttribute(h, FOREGROUND_RED);
				cout << "Wrong type of studing, there are 2 types: Full and Half,try again" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
		}

		cout << "Enter place raiting(1-999)" << endl;

		bool check_place_raiting1 = false;
		bool check_place_raiting = false;
		while (!check_place_raiting1) {
			check_place_raiting = false;
			cin >> place_raiting;
			if (place_raiting < 1 || place_raiting > 999) {
				SetConsoleTextAttribute(h, 3);
				cout << "Wrong place rating,try again, place can be from 1 to 999" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN);
			}
			else {
				for (int i = 0; i < count_students; i++) {
					if (newStudent[i].place_raiting == place_raiting) {
						SetConsoleTextAttribute(h, 3);
						cout << "There is already a student with this place in the rating, check the data and try again." << endl;
						check_place_raiting = true;
						SetConsoleTextAttribute(h, FOREGROUND_GREEN);
					}
				}
				if(!check_place_raiting)
					check_place_raiting1 = true;
			}
		}
	

		cout << "Enter group ID(2001-2099) " << endl;
		bool check6 = false;
		while (!check6) {
			cin >> ID_Group;
			if (ID_Group < 2000 || ID_Group > 2099) {
				SetConsoleTextAttribute(h, 3);
				cout << "Wrong group ID! Group ID is only from 2000 to 2100" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN);
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
		Ffile << count_students + 1;

	}

	if (a == 3) {
		cout << "enter index: " << endl;
		int index;
		cin >> index;
		if (index < count_students) {
			newStudent[index].print();

		}
		else {
			SetConsoleTextAttribute(h,3);
			cout << "index more then all students count" << endl;
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		wait = _getch();

	}

	if (a == 4) {
		cout << "Enter ID of student that u want to find" << endl;
		string stud_id;
		bool check7 = false;
		if (!check7) {
			cin >> stud_id;
			for (int i = 0; i < count_students; i++) {
				if (newStudent[i].ID_Student == atoi(stud_id.c_str())) {
					newStudent[i].print();
					wait = _getch();
					check7 = true;
				}
			}
			SetConsoleTextAttribute(h, FOREGROUND_BLUE);
			cout << "There are not student with this ID" << endl;
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
	}

	if (a == 5) {
		int index_del = 0;
		fstream Ffile_test;
		ifstream file;
		Ffile_test.open("c:\\Users\\Yura\\source\\repos\\DataBaseFaculty\\txt_documents\\TEST.txt");
		file.open("c:\\Users\\Yura\\source\\repos\\DataBaseFaculty\\txt_documents\\TEST.txt");

		

			file.seekg(0, ios_base::end);
		    cout << "������ ����� (� ������): " << file.tellg();
			Sleep(1000);
			system("cls");
			d(50, 12);
			cout << "������� � �������I" << endl;

		Sleep(2000);

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
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
		wait = _getch();
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
		a = 0;
		return;
	}

	string s;
	teacher teachers[300];

	
	getline(IFfile, s);
	int count_teachers = atoi(s.c_str());

	get_file_teachers(teachers, count_teachers);

	if (a == 1) {
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);
		cout << "There are " << count_teachers << " teachers" <<endl;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		for (int i = 0; i < count_teachers; i++) {
			teachers[i].print();
		}
		wait = _getch();
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}

	if (a == 2) {
		SetConsoleTextAttribute(h, 5);
		cout << "Are u sure? U should enter name,ID discipline,graduation" << endl;
		SetConsoleTextAttribute(h, 6);
		cout << "Press BACKSPACE to back menu" << endl;
		SetConsoleTextAttribute(h, 3);
		cout << "Or other bottom to continue" << endl;
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		wait = _getch();
		if (wait == 8) {
			return;
		}
		ID ID_teacher = 0;
		string name = "void";
		ID ID_discipline = 0;
		string graduation;

		string check_ID_teacher;
		string check_ID_discipline;

		string first_name = "";
		string last_name = "";

		if (count_teachers == 0) {
			ID_teacher = 4001;
		}else {
			ID_teacher = teachers[count_teachers - 1].ID_teacher + 1;
		}

		cout << "Enter teacher NAME(without surname): " << endl;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

		bool check_name = false;
		while (!check_name) {

			cin >> first_name;

			if (( first_name.size() > 3 && first_name.size() < 15 ) && !check_numbers(first_name)) {
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "Successfull added name" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				check_name = true;
			}else if (check_numbers(first_name)) {
				SetConsoleTextAttribute(h, FOREGROUND_RED);
				cout << "Name cant have numbers,try again" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}else {
				SetConsoleTextAttribute(h, FOREGROUND_RED);
				cout << "Wrong enter,try again" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		    }
		}

		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
		cout << "Enter teacher SURNAME(without name): " << endl;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		bool check_name2 = false;
		while (!check_name2) {

			cin >> last_name;

			if ((last_name.size() > 3 && last_name.size() < 15) && !check_numbers(last_name)) {
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "Successfull added surname" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				check_name2 = true;
			}
			else if (check_numbers(last_name)) {
				SetConsoleTextAttribute(h, FOREGROUND_RED);
				cout << "Surname cant have numbers,try again" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else {
				SetConsoleTextAttribute(h, FOREGROUND_RED);
				cout << "Wrong enter,try again" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
		}

		bool check_disc_id = false;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);
		cout << "Enter discipline Id(1001-1999): " << endl;
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		while (!check_disc_id) {
			cin >> ID_discipline;
			if (ID_discipline < 1001 || ID_discipline > 1999) {
				SetConsoleTextAttribute(h, FOREGROUND_RED);
				cout << "Wrong enter, ID should be from 1001 to 1999,be attantive and try again" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			else {
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "Successfull added discipline ID" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				check_disc_id = true;
			}

		}
		bool check_graduation = false;
		cout << "Choose graduation: " << endl;
		cout << "1) dosent" << endl;
		cout << "2) proffesor" << endl;
		cout << "3) assistent" << endl;
		cout << "4) aspirant" << endl;

		string check_enter;
		int grad = 0;

		grad1:
		cin >> check_enter;
		
		grad = atoi(check_enter.c_str());
		if (grad > 0 && grad < 5) {

			if(grad == 1)
				graduation = "dosent";
			if (grad == 2)
				graduation = "proffesor";
			if (grad == 3)
				graduation = "assistent";
			if (grad == 3)
				graduation = "asspirant";
		}
		else {
			SetConsoleTextAttribute(h, FOREGROUND_RED);
			cout << "Wrong enter,try again." << endl;
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			goto grad1;
		}
		

		name = first_name + " " + last_name;


		fstream Ffile_teachers;
		Ffile_teachers.open(file_way_teachers,ios_base::app);

		Ffile_teachers << ID_teacher << endl;
		Ffile_teachers << name << endl;
		Ffile_teachers << ID_discipline << endl;
		Ffile_teachers << graduation << endl;

		Ffile_teachers.close();
		Ffile_teachers.open(file_way_teachers);
		Ffile_teachers << count_teachers + 1;
		SetConsoleTextAttribute(h, 14);
		cout << "Succsefully added teacher" << endl;
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		Sleep(2000);
	}
	
	menu_teachers();
}

void menu_works() {
	system("cls");
	cout << "\t\tWorks`s actions(enter number):" << endl;
	cout << "(1) Print all" << endl;
	cout << "(2) Add" << endl;
	cout << "(0) Back" << endl;
	int wait = 0;

	int a = 0;
	cin >> a;

	if (a == 0) {
		return;
	}

	ifstream IFfile_works;
    IFfile_works.open(file_way_works);

	if (IFfile_works.is_open() != 1) {
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
		wait = _getch();
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		a = 0;
		return;
	}

    string s;
	getline(IFfile_works, s);
	int count_works = atoi(s.c_str());
	work works[300] = {};
	get_file_works(works, count_works);
	

	student students[300];
	int count_students = 0;
	get_file_students(students,count_students);

	if (a == 1) {
		SetConsoleTextAttribute(h, 1);
		cout << "This list has entries: " << count_works << endl;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		for (int i = 0; i < count_works; i++) {
			works[i].print();
		}
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		wait = _getch();
	}

	if (a == 2) {
		int student_id = 0;
		int work_id = 0;
		int teacher_id = 0;
		int discipline_id = 0;
		work_types work_type;
		string topic;
		date date_def;

		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Are u sure?" << endl;
		SetConsoleTextAttribute(h, 5 | FOREGROUND_INTENSITY);
		cout << "\nU should enter: Student ID, Teacher ID, Discipline ID, type of work, topic of work and date of defending." << endl;
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		cout << "\nU will not have opportunity to come back,be attentive!" << endl;
		SetConsoleTextAttribute(h, 5 | FOREGROUND_INTENSITY);
		cout << "\nIf yes - enter any key, or press BACKSPACE to come back" << endl;
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		int y_back = _getch();
		if (y_back == 8) {
			a = 0;
			return;
		}

		if (count_works != 0) {
			work_id = works[count_works - 1].ID_Work + 1;
		}
		else {
			work_id = 5001;
		}
		system("cls");
		bool check_id = false;
		cout << "Enter Student ID(3001-3999): " << endl;
		string stud_id = "";
		int checker2 = 0;


		while (check_id == false) {
			cin >> stud_id;
			if (atoi(stud_id.c_str()) == NULL) {
				SetConsoleTextAttribute(h, FOREGROUND_RED);
				cout << "Wrong enter! try again" << endl;;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}else {
				if (atoi(stud_id.c_str()) < 3999 && atoi(stud_id.c_str()) > 3000) {
					for (int i = 0; i < count_students; i++) {
						if (students[i].ID_Student == atoi(stud_id.c_str())) {
							
							SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
							cout << "Succsess!" << endl;
							cout << "Name of this student is " << students[i].name << endl;
							SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
							check_id = true;
							student_id = atoi(stud_id.c_str());
							checker2 = 1;
						}
					}
					if (checker2 == 0) {
						cout << "Entered ID is correct, but no one student have it,try again!" << endl;
					}
				}
				else {
					SetConsoleTextAttribute(h, FOREGROUND_RED);
					cout << "Wrong enter! It is not student ID!" << endl;
					cout << "\nU can enter only real student ID(3001-3999)" << endl;
					cout << "Try again!" << endl;
					SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}

			}
		}

		bool check_discipline_id = false;
		string disc_id = "";







		Sleep(5000);


		
	}
	menu_works();
}

void menu_errors() {
	system("cls");
	SetConsoleTextAttribute(h, 14);
	cout <<" \t Base files : " << endl;
	SetConsoleTextAttribute(h, 11);
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
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\nPress any key to back main menu";


	int wait = 0;
	wait = _getch();


}
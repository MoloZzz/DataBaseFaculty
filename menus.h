#pragma once

#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

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
		teachers[i].ID_Discipline = atoi(s.c_str());
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
			a = 0;
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
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
		wait = _getch();
		a = 0;
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
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
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
		wait = _getch();
		a = 0;

		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
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
		cout << "This list has entries: " << count << endl;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		for (int i = 0; i < count; i++) {
			groups[i].print();
			cout << endl;
		}
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
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
			SetConsoleTextAttribute(h, FOREGROUND_RED);
			cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
			wait = _getch();
			a = 0;
			SetConsoleTextAttribute(h, FOREGROUND_GREEN);
			return;
		}

		if (count != 0) {
			id_group = groups[count - 1].ID_Group + 1;
		}

		cout << "Enter name of new group(without number,example: PI) " << endl;


			cin >> group_name;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << "Succsesfully added name :" << group_name << endl;
			SetConsoleTextAttribute(h, FOREGROUND_GREEN);

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
					SetConsoleTextAttribute(h, FOREGROUND_GREEN);
				}
			}
			if (checker != 1) {
				SetConsoleTextAttribute(h, FOREGROUND_RED);
				cout << "Error,you entered wrong ID,try again" << endl;
				SetConsoleTextAttribute(h, FOREGROUND_GREEN);
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
				SetConsoleTextAttribute(h, FOREGROUND_GREEN);
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

	string s; // елемент для считки з файлу

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
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
		wait = _getch();
	}

	if (a == 2) {

		fstream Ffile;
		Ffile.open(file_way_students, ios_base::app);

		if (Ffile.is_open() != 1) {
			SetConsoleTextAttribute(h, FOREGROUND_RED);
			cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
			SetConsoleTextAttribute(h, FOREGROUND_GREEN);
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
				cout << "Incorrect name, try again" << endl;
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
				cout << "Entered surname so short,try again" << endl;
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
				cout << "Wrong contract number, try again! contract number is 4200-4999" << endl;
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
				cout << "Wrong type of studing, there are 2 types: Full and Half,try again" << endl;
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
			SetConsoleTextAttribute(h, FOREGROUND_GREEN);
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
			SetConsoleTextAttribute(h, FOREGROUND_GREEN);
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
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
		wait = _getch();
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
		a = 0;
		return;
	}

	if (a == 1) {
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
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
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		cout << "Your list is not connected with this data base, check your way, or create new file" << endl;
		wait = _getch();
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
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
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
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
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
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
				SetConsoleTextAttribute(h, FOREGROUND_GREEN);
			}else {
				if (atoi(stud_id.c_str()) < 3999 && atoi(stud_id.c_str()) > 3000) {
					for (int i = 0; i < count_students; i++) {
						if (students[i].ID_Student == atoi(stud_id.c_str())) {
							
							SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
							cout << "Succsess!" << endl;
							cout << "Name of this student is " << students[i].name << endl;
							SetConsoleTextAttribute(h, FOREGROUND_GREEN);
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
					SetConsoleTextAttribute(h, FOREGROUND_GREEN);
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
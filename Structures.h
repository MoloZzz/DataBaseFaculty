#pragma once
#include<iostream>

typedef int ID;

struct date {
	int day;
	int month;
	int year;
};


struct full_name {
	std::string name;
	std::string surname;
};

enum graduations {
	dosent,
	proffesor,
	asistent

};

enum work_types {
	kyrsova,
	diplomna,
	doctorskaya

};

enum obligations {
	blok_IS,
	bloc_PI,
	bloc_VP

};




struct student {
	ID ID_Student;
	std::string name;
	int contract_number;
	std::string studing_type;
	int place_raiting;
	ID ID_Group;
	void print() {
		std::cout << "ID Student: " << ID_Student << std::endl;
		std::cout << "Name: " << name << std::endl;
		std::cout << "Contract number: " << contract_number << std::endl;
		std::cout << "Studing type: " << studing_type << std::endl;
		std::cout << "Place raiting: " << place_raiting << std::endl;
		std::cout << "ID Group: " << ID_Group << std::endl;
		std::cout << std::endl;
	}
};

struct discipline {
	ID ID_Discipline;
	std::string name;
	ID ID_teacher;
	date date_exam;
	int mark;
	obligations obligation;
};

struct group {
	ID ID_Group;
	std::string name;
	std::string head_student;
	int students_amount;

	void print() {
		std::cout << "ID Group: "<< ID_Group << std::endl;
		std::cout << "Group name: " << name << std::endl;
		std::cout << "Head student: " << head_student << std::endl;
		std::cout << "Students amount: " << students_amount << std::endl;

}

};

struct work {
	ID ID_Work;
	ID ID_Student;
	ID ID_teacher;
	work_types work_type;
	ID ID_Discipline;
	date date_def;
	std::string topic;
};


struct teacher {
	ID ID_teacher;
	full_name name;
	ID ID_Discipline;
	graduations graduation;
};
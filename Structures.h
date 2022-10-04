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
	void print() {

		std::cout << "ID discipline: " << ID_Discipline << std::endl;
		std::cout << "Discipline name: " << name << std::endl;
		std::cout << std::endl;
	}

};

struct group {
	ID ID_Group;
	std::string name;
	std::string head_student;
	int students_amount;

	void print() {

		std::cout << "ID Group: " << ID_Group << std::endl;
		std::cout << "Group name: " << name << std::endl;
		std::cout << "Head student: " << head_student << std::endl;
		std::cout << "Students amount: " << students_amount << std::endl;

    }

};

struct work {
	ID ID_Work;
	ID ID_Student;
	ID ID_Teacher;
	ID ID_Discipline;
	std::string work_type;
	std::string date_def;
	std::string topic;


	void print() {
		std::cout << "Work ID: " << ID_Work << std::endl;
		std::cout << "Student ID: " << ID_Student << std::endl;
		std::cout << "Teacher ID: " << ID_Teacher << std::endl;
		std::cout << "Discipline ID: " << ID_Discipline << std::endl;
		std::cout << "Work type: " << work_type << std::endl;
		std::cout << "Date of defending: " << date_def << std::endl;
		std::cout << "Topic: " << topic << std::endl;
	}
};


struct teacher {
	ID ID_teacher;
	std::string name;
	ID ID_discipline;
	std::string graduation;

	void print() {
		std::cout << "Teacher ID: " << ID_teacher << std::endl;
		std::cout << "Name: " << name << std::endl;
		std::cout << "ID discipline: " << ID_discipline << std::endl;
		std::cout << "Graduation: " << graduation << std::endl;
		std::cout << std::endl;
	}
};



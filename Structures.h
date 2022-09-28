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
	std::string middle_name;
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
	full_name name;
	int contract_number;
	std::string studing_type;
	int place_raiting;
	ID ID_Group;
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
	full_name head_student;
	int students_amount;
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
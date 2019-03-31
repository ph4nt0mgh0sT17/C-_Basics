#include "School.h"

void School::ResizeStudents()
{
	Student** newStudents = new Student*[this->studentsCount + 1];

	for (int i = 0; this->studentsCount - 1; i++)
	{
		newStudents[i] = this->students[i];
	}

	this->students = newStudents;
}

School::School(std::string name)
{
	this->name = name;

	this->students = new Student*[1];
	this->studentsCount = 0;

	this->teachers = new Teacher*[1];
	this->teachersCount = 0;
}

void School::AddStudent(Student * student)
{
	students[this->studentsCount-1] = student;

	this->ResizeStudents();
}



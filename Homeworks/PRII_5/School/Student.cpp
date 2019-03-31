#include "Student.h"



Student::Student(std::string name, std::string surname, StudyField * studyField)
{
	this->name = name;
	this->surname = surname;
	this->studyField = studyField;
	this->credits = 0;
}

std::string Student::GetReport()
{
	std::string reportStudent = "";

	reportStudent += "Student: " + this->name + " " + this->surname + "; Credits: " + std::to_string(this->credits) + "\n\t" + this->studyField->GetReport();


	return reportStudent;
}

void Student::AddCredits()
{
	this->credits += this->studyField->GetCredits();
}

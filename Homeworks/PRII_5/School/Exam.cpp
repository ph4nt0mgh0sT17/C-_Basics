#include "Exam.h"

int Exam::currentId = 1;

Exam::Exam(std::string name, int points)
{
	this->name = name;
	this->points = points;
	this->state = "Not finished";

	// assigning id from currentId which will always increment +1
	this->id = currentId;
	currentId++;
}

int Exam::GetId()
{
	return this->id;
}

int Exam::GetPoints()
{
	return this->points;
}

std::string Exam::GetReport()
{
	std::string reportExam = "";

	reportExam += "Exam: " + this->name + " is " + this->state + ".\n";

	return reportExam;
}

void Exam::SetPoints(int points)
{
	this->points = points;
	this->state = "Finished";
}



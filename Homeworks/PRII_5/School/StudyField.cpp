#include "StudyField.h"

int StudyField::currentId = 1;

void StudyField::ResizeSubjects()
{
	Subject** newSubjects = new Subject*[this->subjectsCount + 1];

	for (int i = 0; i < this->subjectsCount; i++)
	{
		newSubjects[i] = this->subjects[i];
	}
	
	this->subjectsCount++;

	this->subjects = newSubjects;
}

StudyField::StudyField(std::string name, int requiredCredits)
{
	this->name = name;

	this->subjects = new Subject*[1];
	this->subjectsCount = 1;

	this->requiredCredits = requiredCredits;

	this->id = currentId;
	currentId++;
}

std::string StudyField::GetReport()
{
	std::string reportField = "";

	reportField += "Study Field: " + this->name + "; Credits: " + std::to_string(this->requiredCredits) + "\n\n";

	for (int i = 0; i < this->subjectsCount-1; i++)
	{
		reportField += "\t\t" + this->subjects[i]->GetReport() + "\n";
	}

	return reportField;
}

void StudyField::AddSubject(Subject * subject)
{
	this->subjects[this->subjectsCount - 1] = subject;

	this->ResizeSubjects();
}

int StudyField::GetCredits()
{
	int credits = 0;
	for (int i = 0; i < this->subjectsCount - 1; i++)
	{
		if (subjects[i]->CheckCredit() == true)
		{
			credits += subjects[i]->GetCreditPoints();
		}
	}

	return credits;
}

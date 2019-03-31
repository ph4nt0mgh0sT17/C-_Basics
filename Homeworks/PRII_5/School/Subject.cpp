#include "Subject.h"

// this will be invoken only once during compilation all files
int Subject::currentId = 1;

void Subject::ResizeExams()
{
	Exam** newExams = new Exam*[this->examsCount + 1];

	for (int i = 0; i < this->examsCount; i++)
	{
		newExams[i] = this->exams[i];
	}

	this->examsCount++;

	this->exams = newExams;
}

Subject::Subject(std::string name, int creditPoints, int requiredCreditPoints)
{
	this->name = name;
	this->creditPoints = creditPoints;
	this->requiredCreditPoints = requiredCreditPoints;
	this->studentsPoints = 0;
	this->exams = new Exam*[1];
	this->examsCount = 1;
	this->passed = false;

	// assigning id from currentId which will always increment +1
	this->id = currentId;
	currentId++;
}

bool Subject::CheckCredit()
{
	this->passed = (this->studentsPoints >= this->requiredCreditPoints);
	return passed;
}

std::string Subject::GetReport()
{
	std::string reportSubject = "";

	reportSubject += "Subject: " + this->name + "; Credits: " + std::to_string(this->creditPoints) + "\n";
	for (int i = 0; i < this->examsCount-1; i++)
	{
		reportSubject += "\t\t\t" + this->exams[i]->GetReport();
	}

	return reportSubject;
}

int Subject::GetCreditPoints()
{
	return this->creditPoints;
}

void Subject::AddPoints(Exam * exam, int points)
{
	for (int i = 0; i < this->examsCount; i++)
	{
		if (exam == this->exams[i])
		{
			exam->SetPoints(points);
			this->studentsPoints += points;
		}
	}
}

void Subject::AddExam(Exam * exam)
{
	this->exams[this->examsCount-1] = exam;
	
	this->ResizeExams();
}


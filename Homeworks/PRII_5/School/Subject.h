#include <string>

#include "Exam.h"


class Subject
{
private:
	std::string name;
	int id;
	int creditPoints;

	Exam** exams;
	int examsCount;

	int requiredCreditPoints;
	int studentsPoints;

	bool passed;

	static int currentId;

	

	void ResizeExams();

public:
	Subject(std::string name, int creditPoints, int requiredCreditPoints);

	bool CheckCredit();
	std::string GetReport();
	int GetCreditPoints();

	void AddPoints(Exam* exam, int points);
	void AddExam(Exam* exam);



};


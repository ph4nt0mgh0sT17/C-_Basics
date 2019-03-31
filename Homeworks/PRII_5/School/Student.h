#include <string>

#include "StudyField.h"


class Student
{
private:
	std::string name;
	std::string surname;

	int credits;
	
	StudyField* studyField;
public:
	Student(std::string name, std::string surname, StudyField* studyField);

	std::string GetReport();

	void AddCredits();
};


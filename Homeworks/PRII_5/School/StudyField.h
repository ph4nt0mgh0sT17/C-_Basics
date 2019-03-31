#include <string>
#include "Subject.h"

class StudyField
{
private:
	std::string name;
	int id;
	Subject** subjects;
	int subjectsCount;
	int requiredCredits;

	static int currentId;

	void ResizeSubjects();
public:
	StudyField(std::string name, int requiredCredits);

	std::string GetReport();
	
	void AddSubject(Subject* subject);

	int GetCredits();

};


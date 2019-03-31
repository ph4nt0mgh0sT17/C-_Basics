#include "Student.h"
#include "Teacher.h"

class School
{
private:
	Student** students;
	int studentsCount;

	Teacher** teachers;
	int teachersCount;

	std::string name;

	void ResizeStudents();
public:
	School(std::string name);

	void AddStudent(Student* student);
};


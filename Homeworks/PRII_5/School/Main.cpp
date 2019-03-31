#include <iostream>

#include "School.h"

int main(void)
{

	School* vsb = new School("VSB - Technical university of Ostrava");

	Subject* programming, *math, *algorithms;

	programming = new Subject("Programming II.", 7, 51);
	{
		Exam* project = new Exam("Project - School", 5);
		Exam* project2 = new Exam("Something, but I guess it's gonna be hard", 5);

		programming->AddExam(project);
		programming->AddExam(project2);
	}

	math = new Subject("Mathematical Analysis II.", 7, 51);
	{
		Exam* project = new Exam("Differencials", 50);
		Exam* project2 = new Exam("SURPRISE", 50);

		math->AddExam(project);
		math->AddExam(project2);

		math->AddPoints(project, 45);
		math->AddPoints(project2, 45);
	}

	algorithms = new Subject("Algorithms", 7, 51);
	{
		Exam* project = new Exam("Binary tree", 2);
		Exam* project2 = new Exam("Project - Hashing", 40);

		algorithms->AddExam(project);
		algorithms->AddExam(project2);
	}


	


	StudyField* it = new StudyField("Information technology", 60);
	{
		it->AddSubject(programming);
		it->AddSubject(math);
		it->AddSubject(algorithms);
	}

	Student* student = new Student("David", "Miko", it);

	student->AddCredits();

	std::cout << student->GetReport() << std::endl;

	getchar();

	return (0);
}

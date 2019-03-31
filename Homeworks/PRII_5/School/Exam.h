#include <string>



class Exam
{
private:
	std::string name;
	std::string state;
	int id;
	int points;
	

	static int currentId;

public:
	Exam(std::string name, int points);

	int GetId();
	int GetPoints();
	std::string GetReport();

	void SetPoints(int points);
};


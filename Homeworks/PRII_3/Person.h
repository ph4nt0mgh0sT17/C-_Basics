#pragma once

#include <string>

class Person
{
private:
	std::string name;
	std::string adress;

public:
	Person(std::string name, std::string adress);
	std::string GetOwnerData();
};


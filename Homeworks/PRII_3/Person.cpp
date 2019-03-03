#include "Person.h"

Person::Person(std::string name, std::string adress)
{
	this->name = name;
	this->adress = adress;
}

std::string Person::GetOwnerData()
{
	return "Owner: " + this->name + ", Address: " + this->adress;
}




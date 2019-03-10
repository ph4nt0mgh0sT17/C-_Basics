#include "Client.h"



Client::Client(int code, std::string name)
{
	this->code = code;
	this->name = name;
}

int Client::GetCode()
{
	return this->code;
}

std::string Client::GetName()
{
	return this->name;
}

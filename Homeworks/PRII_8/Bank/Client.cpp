#include "Client.h"

int Client::objectsCount = 0;

Client::Client(int code, std::string name)
{
	this->code = code;
	this->name = name;
	Client::objectsCount += 1;
}

Client::~Client()
{
	Client::objectsCount -= 1;
}

int Client::GetObjectsCount()
{
	return Client::objectsCount;
}

int Client::GetCode()
{
	return this->code;
}

std::string Client::GetName()
{
	return this->name;
}
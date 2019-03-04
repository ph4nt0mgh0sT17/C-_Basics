#pragma once

#include "KeyValue.h"

#include <string>

class KeyValues
{
private:
	KeyValue** keyValues;
	int count;

public:
	KeyValues(int n);
	~KeyValues();
	KeyValue* CreateObject(int k, double v);
	KeyValue* SearchObject(int key);
	KeyValue* RemoveObject(int key);
	std::string GetInformation();
	int Count();
};


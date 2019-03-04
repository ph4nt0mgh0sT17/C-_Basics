#pragma once

#include <string>
class KeyValue
{

private:
	int key;
	double value;
	KeyValue *next;

public:
	KeyValue(int k, double v);
	~KeyValue();
	int GetKey();
	double GetValue();
	KeyValue* GetNext();
	KeyValue* CreateNext(int k, double v);
	std::string GetAllKeyValues()
	{
		std::string result = "";

		result += "Key: " + std::to_string(this->key) + "; Value: " + std::to_string(this->value) + "\n";

		if (this->next != nullptr)
		{
			result += this->next->GetAllKeyValues();
		}

		return result;
	}

};


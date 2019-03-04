#include "KeyValue.h"



KeyValue::KeyValue(int k, double v)
{
	this->key = k;
	this->value = v;
	this->next = nullptr;
}


KeyValue::~KeyValue()
{
	if (this->next != nullptr)
	{
		delete this->next;
		this->next = nullptr;
	}
}

int KeyValue::GetKey()
{
	return this->key;
}

double KeyValue::GetValue()
{
	return this->value;
}

KeyValue* KeyValue::GetNext()
{
	return this->next;
}

KeyValue* KeyValue::CreateNext(int k, double v)
{
	this->next = new KeyValue(k, v);

	return this->next;
}

std::string KeyValue::GetAllKeyValues()
{
	std::string result = "";

	result += "Key: " + std::to_string(this->key) + "; Value: " + std::to_string(this->value) + "\n";

	if (this->next != nullptr)
	{
		result += this->next->GetAllKeyValues();
	}

	return result;
}

#include "KeyValue.h"



KeyValue::KeyValue(int k, double v)
{
	this->key = k;
	this->value = v;
	this->next = nullptr;
}


KeyValue::~KeyValue()
{
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

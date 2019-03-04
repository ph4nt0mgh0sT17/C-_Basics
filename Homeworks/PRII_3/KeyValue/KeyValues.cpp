#include "KeyValues.h"



KeyValues::KeyValues(int n)
{
	this->keyValues = new KeyValue*[n];
	this->count = 0;
}


KeyValues::~KeyValues()
{
	for (int i = 0; i < this->count; i++)
	{
		delete this->keyValues[i];
	}
	delete[] this->keyValues;
}

KeyValue* KeyValues::CreateObject(int k, double v)
{
	KeyValue* newObject = new KeyValue(k, v);

	this->keyValues[this->count] = newObject;
	this->count += 1;
	
	return newObject;
}

KeyValue* KeyValues::SearchObject(int key)
{
	for (int i = 0; i < this->count; i++)
	{
		if (this->keyValues[i]->GetKey() == key)
		{
			return this->keyValues[i];
		}
	}

	return nullptr;
}

KeyValue* KeyValues::RemoveObject(int key)
{
	KeyValue* removeObject;
	for (int i = 0; i < this->count; i++)
	{
		if (this->keyValues[i]->GetKey() == key)
		{
			removeObject = this->keyValues[i];

			if (i < this->count - 1)
			{
				for (int j = i+1; j < this->count; j++)
				{
					if (this->keyValues[j] != nullptr)
					{
						this->keyValues[j-1] = this->keyValues[j];
					}
				}
			}
			this->count--;
			return removeObject;
		}
	}

	return nullptr;

}

std::string KeyValues::GetInformation()
{
	std::string result = "";

	for (int i = 0; i < this->count; i++)
	{
		result += "Key: " + std::to_string(this->keyValues[i]->GetKey()) + "; Value: " + std::to_string(this->keyValues[i]->GetValue()) + "\n";
	}

	return result;
}

int KeyValues::Count()
{
	return this->count;
}

#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class TKey, class TValue>
class Dictionary
{
private:
	TKey* keysArray;
	int keysArrayCount;

	TValue* valuesArray;
	int valuesArrayCount;

	void ResizeKeys();
	void ResizeValues();
public:
	Dictionary();


	void Add(TKey key, TValue value);
	void Remove(TKey key);

	TValue Find(TKey key);
	bool ContainsKey(TKey key);
	bool ContainsValue(TValue value);
	vector<TKey>* Keys();
	vector<TValue>* Values();

};

template<class TKey, class TValue>
inline void Dictionary<TKey, TValue>::ResizeKeys()
{
	TKey* keysTemp = new TKey[this->keysArrayCount + 1];

	for (int i = 0; i < this->keysArrayCount; i++)
	{
		keysTemp[i] = this->keysArray[i];
	}

	delete this->keysArray;

	this->keysArray = keysTemp;

	this->keysArrayCount++;
}


template<class TKey, class TValue>
inline void Dictionary<TKey, TValue>::ResizeValues()
{
	TValue* valuesTemp = new TValue[this->valuesArrayCount + 1];

	for (int i = 0; i < this->valuesArrayCount; i++)
	{
		valuesTemp[i] = this->valuesArray[i];
	}

	delete this->valuesArray;

	this->valuesArray = valuesTemp;

	this->valuesArrayCount++;
}

template<class TKey, class TValue>
inline Dictionary<TKey, TValue>::Dictionary()
{
	this->keysArray = new TKey[1];
	this->valuesArray = new TValue[1];
	this->keysArrayCount = 1;
	this->valuesArrayCount = 1;
}

template<class TKey, class TValue>
inline void Dictionary<TKey, TValue>::Add(TKey key, TValue value)
{
	this->keysArray[this->keysArrayCount - 1] = key;
	this->valuesArray[this->valuesArrayCount - 1] = value;

	this->ResizeKeys();
	this->ResizeValues();


}

template<class TKey, class TValue>
inline void Dictionary<TKey, TValue>::Remove(TKey key)
{
	for (int i = 0; i < this->keysArrayCount; i++)
	{
		if (this->keysArray[i] == key)
		{
			
			int index = i;

			while (index < this->keysArrayCount - 2)
			{
				this->keysArray[index] = this->keysArray[index + 1];
				this->valuesArray[index] = this->valuesArray[index + 1];
				index++;
			}

			TKey* tempKeys = new TKey[this->keysArrayCount - 1];
			TValue* tempValues = new TValue[this->valuesArrayCount - 1];

			for (int j = 0; j < this->keysArrayCount - 1; j++)
			{
				tempKeys[j] = this->keysArray[j];
				tempValues[j] = this->valuesArray[j];
			}

			delete keysArray;
			delete valuesArray;

			this->keysArray = tempKeys;
			this->valuesArray = tempValues;

			this->keysArrayCount--;
			this->valuesArrayCount--;

			return;
		}
	}
}


template<class TKey, class TValue>
inline TValue Dictionary<TKey, TValue>::Find(TKey key)
{
	for (int i = 0; i < this->keysArrayCount; i++)
	{
		if (this->keysArray[i] == key)
		{
			return this->valuesArray[i];
		}
	}

	return NULL;
}

template<class TKey, class TValue>
inline bool Dictionary<TKey, TValue>::ContainsKey(TKey key)
{
	for (int i = 0; i < this->keysArrayCount; i++)
	{
		if (this->keysArray[i] == key)
		{
			return true;
		}
	}

	return false;
}

template<class TKey, class TValue>
inline bool Dictionary<TKey, TValue>::ContainsValue(TValue value)
{
	for (int i = 0; i < this->valuesArrayCount; i++)
	{
		if (this->valuesArray[i] == value)
		{
			return true;
		}
	}

	return false;
}

template<class TKey, class TValue>
inline vector<TKey>* Dictionary<TKey, TValue>::Keys()
{
	vector<TKey>* keys = new vector<TKey>();
	
	for (int i = 0; i < this->keysArrayCount; i++)
	{
		keys->push_back(this->keysArray[i]);
	}

	return keys;
}

template<class TKey, class TValue>
inline vector<TValue>* Dictionary<TKey, TValue>::Values()
{
	vector<TValue>* values = new vector<TValue>();

	for (int i = 0; i < this->valuesArrayCount; i++)
	{
		values->push_back(this->valuesArray[i]);
	}

	return values;
}


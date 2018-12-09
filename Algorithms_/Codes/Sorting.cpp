#include <iostream>
#include <ctime>

using namespace std;

int *LoadValues(int *pArray, int n);
void PrintArray(int *pArray, int n);
int GetIndex(int *pArray, int n, int element);
int GetMin(int *pArray, int n, int index = 0);
void SelectSort(int *pArray, int n);

int main(void)
{
	cout << "Ahoj" << endl;

	int N = 10;

	int *pArray = new int[N];
	pArray = LoadValues(pArray, N);
	PrintArray(pArray, N);
	cout << "Minimal value of array: " << GetMin(pArray, N) << " and its index is: " << GetIndex(pArray, N, GetMin(pArray, N)) << endl;
	SelectSort(pArray, N);

	PrintArray(pArray, N);

	

	system("pause");

	return 0;
}

int *LoadValues(int *pArray, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		pArray[i] = rand() % 100 + 1;
	}

	return pArray;
}

void PrintArray(int *pArray, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << pArray[i] << "; ";
	}

	cout << endl;
}

int GetIndex(int *pArray, int n, int element)
{
	for (int i = 0; i < n; i++)
	{
		if (pArray[i] == element)
		{
			return i;
		}
	}

	return -1;
}

int GetMin(int *pArray, int n, int index)
{
	int minValue = pArray[index];

	for (int i = index+1; i < n; i++)
	{
		if (minValue > pArray[i])
		{
			minValue = pArray[i];
		}
	}

	return minValue;
}

void SelectSort(int *pArray, int n)
{
	for (int i = 0; i < n; i++)
	{
		int index = GetIndex(pArray, n, GetMin(pArray, n, i));
		swap(pArray[i], pArray[index]);
	}
}
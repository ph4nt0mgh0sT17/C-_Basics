/*
*	Algorithm I. - 11/26/2018
*	Author: David Miko
*	Professor: Pavel Dohnalek
*
*	Curriculum: Sorting arrays
*	Description: TBA
*/

#include <iostream>
#include <ctime>

using namespace std;

#pragma region Defined values

#define OK 0;
#define FAIL -1;

#pragma endregion

#pragma region Function headers 

void space();
void loadUniqueValues(int *arr, int N, int range);
void printArray(int *arr, int N);
int* bubbleSort(int *arr, int N);
int* bubbleSortDohnalek(int *arr, int N);
int* selectSort(int *arr, int N);
int min(int *arr, int N, int index);

#pragma endregion

int main(void)
{
	cout << "\t\tAlgorithm I. - 11 / 26 / 18" << endl;
	space();

	const int N = 10;

	int *p = new int[N];

	loadUniqueValues(p, N, 100);

	cout << "Unsorted array:" << endl;
	printArray(p, N);

	cout << endl;
	space();
	
	cout << "Sorted array - bubble sort:" << endl;
	printArray(bubbleSort(p, N), N);

	cout << endl;
	space();

	cout << "Sorted array - bubble sort - do-while:" << endl;
	printArray(bubbleSortDohnalek(p, N), N);

	cout << endl;
	space();

	cout << "Sorted array - selection sort:" << endl;
	printArray(selectSort(p,N), N);

	delete[] p;
	p = nullptr;

	system("pause");
	return OK;
}

#pragma region Function bodies

/// <summary>Prints space for better lucidity in console...</summary>
void space()
{
	cout << "============================================================" << endl;
}

/// <summary>Prints array</summary>
/// <param name="arr">Current array to be searched through</param>
/// <param name="N">Quantity of elements in the array</param>
void printArray(int *arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "; ";
	}
}

/// <summary>Load unique values (random) to array</summary>
/// <param name="arr">Current array to be searched through</param>
/// <param name="N">Quantity of elements in the array</param>
/// <param name="range">Range of random bounds</param>
void loadUniqueValues(int *arr, int N, int range)
{
	// unsigned int because of pedantic error -> this function 'time' expects unsigned int
	srand(unsigned int(time(nullptr)));

	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % (range + 1);
	}
}

/// <summary>Sorts an array by Bubble sort algorithm</summary>
/// <param name="arr">Current array to be searched through</param>
/// <param name="N">Quantity of elements in the array</param>
/// <returns>Sorted array</returns>
int* bubbleSort(int *arr, int N)
{
	int* arr_sort = arr;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N-1; j++)
		{
			if (arr_sort[j] > arr_sort[j + 1])
			{
				// I could write also instead of these 3 lines -> swap(arr_sort[j], arr_sort[j+1]);
				int tmp = arr_sort[j];
				arr_sort[j] = arr_sort[j + 1];
				arr_sort[j + 1] = tmp;
			}
		}
	}

	return arr_sort;
}

/// <summary>Sorts an array by Bubble sort algorithm by do-while</summary>
/// <param name="arr">Current array to be searched through</param>
/// <param name="N">Quantity of elements in the array</param>
/// <returns>Sorted array</returns>
int* bubbleSortDohnalek(int *arr, int N)
{
	int* arr_sort = arr;

	bool changed;

	do
	{
		changed = false;

		for (int j = 0; j < N - 1; j++)
		{
			if (arr_sort[j] > arr_sort[j + 1])
			{
				changed = true;

				// I could write also instead of these 3 lines -> swap(arr_sort[j], arr_sort[j+1]);
				int tmp = arr_sort[j];
				arr_sort[j] = arr_sort[j + 1];
				arr_sort[j + 1] = tmp;
			}
		}
	} while (changed);

	return arr_sort;
}

/// <summary>Gets minimal value of the current array</summary>
/// <param name="arr">Current array to be searched through</param>
/// <param name="N">Quantity of elements in the array</param>
/// <param name="index">Where to start from in the array (default set to 0)</param>
/// <returns>Minimal value</returns>
int min(int *arr, int N, int index = 0)
{
	int min = arr[index];
	for (int i = index+1; i < N; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	return min;
}

/// <summary>Sorts an array by Select Sort algorithm</summary>
/// <param name="arr">Current array to be searched through</param>
/// <param name="N">Quantity of elements in the array</param>
/// <returns>Sorted array</returns>
int* selectSort(int *arr, int N)
{
	// temporary array for sorting
	int *arr_sort = arr;

	//minimal value of the array
	int min_val;

	for (int i = 0; i < N; i++)
	{
		min_val = min(arr_sort, N, i);
		arr_sort[i] = min_val;
	}

	return arr_sort;
}



#pragma endregion

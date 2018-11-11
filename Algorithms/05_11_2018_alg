/*

	Algorithms I. - 5. 11. 2018
	Student: David Miko
	Professor: Dohnálek

	Popis: Vyhledávání v poli...

*/

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void write_arr(int* arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << "; ";
	}
}

// first method
void add_unique_values(int *arr, int N)
{
	bool unused_number;

	for (int i = 0; i < N; i++)
	{
		unused_number = true;
		int rnd_num = rand() % N + 1;

		for (int j = 0; j < i; j++)
		{
			if (arr[j] == rnd_num)
			{
				unused_number = false;
				break;
			}
		}
		if (!unused_number)
		{
			i--;
		}

		else
		{
			arr[i] = rnd_num;
		}
	}
}

void add_unique_values_bool(int *arr, int N)
{
	bool *used_values = new bool[N];

	for (int i = 0; i < N; i++)
	{
		used_values[i] = false;
	}

	//add unique values

	for (int i = 0; i < N; i++)
	{
		int rnd_num = rand() % N;

		if (!used_values[rnd_num])
		{
			arr[i] = rnd_num + 1;
			used_values[rnd_num] = true;
		}

		else
		{
			i--;
		}
	}

	delete[] used_values;
	used_values = nullptr;
}

int main(void)
{
	cout << "\t\tAlgorithms I. - 11/05/2018" << endl;
	cout << "==========================================================" << endl;

	// Dereference pole není nutná - protože máme indexaci pole 

	srand(time(0)); // we should write time(0) instead of time(NULL) because we don't want it to be NULL (NULL is not 0 its voidless)

	int N = 10;

	int *_arr = new int[N];
	
	add_unique_values_bool(_arr, N);

	write_arr(_arr, N);

	// at the end of the program we should always delete our pointers to clean memory up
	delete[] _arr;
	_arr = nullptr;


	system("pause");
	return (0);
}

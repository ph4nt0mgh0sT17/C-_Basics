#include <iostream>

using namespace std;


int** allocation(int ROWS, int COLS)
{
	int **arr2D = new int*[ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		arr2D[i] = new int[COLS];

	}

	return arr2D;
}

int** load_data(int ROWS, int COLS, int** arr)
{
	
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = i * j;
		}
	}

	return arr;
}

void deallocation(int ROWS, int COLS, int** arr)
{
	for (int i = 0; i < ROWS; i++)
	{
		delete[] arr[i];
		//p2D[i] = nullptr;

	}

	delete[] arr;
	arr = nullptr;
}

int main(void)
{
	cout << "Hello, world!";

	const int ROWS = 10000;
	const int COLS = 11000;

	// operators for getting address -> [ '&' and 'new' ]

	//pointer is just variable

	cout << endl;

	
	// inicialization and allocation
	int** p2D = allocation(ROWS, COLS);

	// load data to array2D
	p2D = load_data(ROWS, COLS, p2D);

	
	
	// Deallocation
	deallocation(ROWS, COLS, p2D);


	system("pause");
	return (0);
}

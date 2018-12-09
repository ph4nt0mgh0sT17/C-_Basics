#include <iostream>

using namespace std;

// & need to be used to reference to array dynamic
void allocation(int ROWS, int COLS, int **&arr)
{
	arr = new int*[ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		arr[i] = new int[COLS];

	}

	
}


void initialize_2d(int** arr, const unsigned ROWS, const unsigned COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = i * j;
		}
	}
}

void print_2d(int** arr, const unsigned ROWS, const unsigned COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "; \t";
		}

		cout << endl;
	}
}

int main(void)
{
	cout << "Hello, world!";

	const int ROWS = 10;
	const int COLS = 10;

	// operators for getting address -> [ '&' and 'new' ]

	//pointer is just variable

	cout << endl;

	int** p2D;
	// inicialization and allocation
	allocation(ROWS, COLS, p2D);
	initialize_2d(p2D, ROWS, COLS);
	print_2d(p2D, ROWS, COLS);
	

	//cout << p2D[0];

	system("pause");
	return (0);
}

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


void space();
long factorial(int n);
void load_values(int *arr, int N);
int sum_values(int *arr, int N);


int main(void)
{
	cout << "\t\tAlgorithms - 11/12/18" << endl;
	cout << "\t\tAuthor: David Miko" << endl;
	space();
	
	int N = 2;
	int *_arr = new int[N];

	load_values(_arr, N);
	cout << "Sum of the array is: " << sum_values(_arr, N) << endl;

	delete[] _arr;
	_arr = nullptr;

	system("pause");
	return (0);
}

long factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}

	long num = 1;
	for (int i = 1; i <= n; i++)
	{
		num *= i;
	}


	return (num);
}

void load_values(int *arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		arr[i] = 100;
	}
}

int sum_values(int *arr, int N)
{
	
	if (N > 1)
	{
		return arr[N-1] + sum_values(arr, N - 1); // need to decrease N in the next function to move on to net element in the array
	}
	
	return arr[0];


}

// default argument -> int i = 0
int sum_values_dohnalek(int *arr, int N, int i = 0)
{

	if (i >= N)
	{
		return (0);
	}

	return arr[i] + sum_values_dohnalek(arr, N, i + 1);

}

void space()
{
	cout << "===========================================================" << endl;
}

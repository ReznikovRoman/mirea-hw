#include <iostream>
#include <vector>
#include <array>

using namespace std;


void printVector(const vector<int> & v)
{
	cout << endl;

	for (int el : v)
	{
		cout << el << " ";
	}

	cout << endl;
}


void printArr(int *arr, const int & n)
{
	cout << endl;

	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}


void populateArr(int* arr, const int & n)
{
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = rand() % 2 + 1;
	}
}


void delFirstMethod(int *x, int n, const int & key)
{
	int i = 0;

	while (i <= n)
	{
		if (x[i] == key)
		{
			for (int j = i; j < n - 1; j++)
			{
				cout << x[j] << " " << x[j + 1] << endl;
				x[j] = x[j + 1];
			}

			n -= 1;
		}
		else
		{
			i += 1;
		}
	}

	
}


void task1()
{
	// vector<int> v = {1, 2, 3, 4, 5, 6, 7};

	// delFirstMethod(v, v.size(), 2);

	// printVector(v);

	int n = 5;
	int key = 2;
	int* arr = new int[n];

	populateArr(arr, n);
	printArr(arr, n);

	delFirstMethod(arr, n, key);

	printArr(arr, n);
}


void task2()
{

}


int main()
{
	task1();
	// task2();
}


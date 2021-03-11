#include <iostream>

using namespace std;

void printArr(int *arr, const int &n)
{
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void populateArr(int *arr, const int &n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10 + 1;
	}
}

void delFirstMethod(int *x, int &n, const int &key)
{
	int i = 0;
	int actionsCount = 0;

	while (i < n)
	{
		actionsCount++;
		if (x[i] == key)
		{
			for (int j = i; j < n - 1; j++)
				x[j] = x[j + 1];
			n -= 1;
			actionsCount++;
		}
		else
		{
			i += 1;
		}
	}
	cout << "\nActions (permutations, deletions) count: " << actionsCount;
}

void task1()
{

	int n = 5;
	int key = 1;
	int *arr = new int[n];

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

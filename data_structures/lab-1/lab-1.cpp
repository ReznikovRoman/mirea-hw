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
	cout << "\nTask - 1.2 (#6)" << endl;

	const int n = 3, m = 3;
	int matrix[n][m];
	int maxValue = -1000;

	// populate matrix
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout << "Enter value: ";
			cin >> matrix[i][j];
		}
		cout << endl;
	}

	// print matrix
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	// find max value
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < m; j++)
		{
			cout << matrix[i][j] << " ";
			if (matrix[i][j] > maxValue)
				maxValue = matrix[i][j];
		}
	}
	cout << endl;

	// print max value
	cout << "Max value: " << maxValue << endl;
}

int main()
{
	//task1();
	task2();
}

#include <string>
#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int *generateRandomArray(int size)
{
    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100; //Generate number between 0 to 99
    }

    return arr;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = new int[n1];
    int *M = new int[n2];

    // L: A[p .. q]
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
    }

    // M: A[q+1 .. r]
    for (int j = 0; j < n2; j++)
    {
        M[j] = arr[q + 1 + j];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void shakerSort(int arr[], int n)
{
    for (int i = 0; i < n;)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(&arr[j], &arr[j - 1]);
            }
        }

        n--;

        for (int k = n - 1; k > i; k--)
        {
            if (arr[k] < arr[k - 1])
            {
                swap(&arr[k], &arr[k - 1]);
            }
        }

        i++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        // Сортируем левую и правую часть по отдельности
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Мерджим получившиеся массивы
        merge(arr, left, middle, right);
    }
}

void bubbleSortExample(int size)
{
    cout << "Bubble sort: ";

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int *arr = generateRandomArray(size);
    bubbleSort(arr, size);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}

void bubbleSortDescendingExample()
{
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int arr[] = {64, 34, 25, 12, 10, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Bubble sort: ";
    printArr(arr, n);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function (descending order): " << duration.count() << " microseconds" << endl;
}

void bubbleSortAscendingExample()
{
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int arr[] = {8, 9, 10, 12, 25, 34, 64};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Bubble sort: ";
    printArr(arr, n);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function (ascending order): " << duration.count() << " microseconds" << endl;
}

void shakerSortExample(int size)
{
    cout << "Shaker sort: ";

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int *arr = generateRandomArray(size);
    shakerSort(arr, size);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}

void shakerSortDescendingExample()
{
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int arr[] = {64, 34, 25, 12, 10, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    shakerSort(arr, n);
    cout << "Shaker sort: ";
    printArr(arr, n);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function (descending order): " << duration.count() << " microseconds" << endl;
}

void shakerSortAscendingExample()
{
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int arr[] = {8, 9, 10, 12, 25, 34, 64};
    int n = sizeof(arr) / sizeof(arr[0]);
    shakerSort(arr, n);
    cout << "Shaker sort: ";
    printArr(arr, n);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function (ascending order): " << duration.count() << " microseconds" << endl;
}

void mergeSortExample(int size)
{
    cout << "Merge sort: ";

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int *arr = generateRandomArray(size);
    mergeSort(arr, 0, size - 1);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}

void mergeSortDescendingExample()
{
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int arr[] = {64, 34, 25, 12, 10, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function (descending order): " << duration.count() << " microseconds" << endl;
}

void mergeSortAscendingExample()
{
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int arr[] = {8, 9, 10, 12, 25, 34, 64};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function (ascending order): " << duration.count() << " microseconds" << endl;
}

void task1()
{
    bubbleSortExample(100);   // 63 ms
    bubbleSortExample(1000);  // 5140 ms
    bubbleSortExample(10000); // 566653 ms
    // bubbleSortExample(100000);  // 57707651 ms | 57,7 s
    // bubbleSortExample(1000000);  // 565534979.8 ms | 9,4 m

    shakerSortExample(100);   // 55 ms
    shakerSortExample(1000);  // 4859 ms
    shakerSortExample(10000); // 516526 ms
    // shakerSortExample(100000);  // 52702786 ms | 52,7 s
    // shakerSortExample(1000000);  // 516487302.8 ms | 8,6 m

    mergeSortExample(100);   // 68 ms
    mergeSortExample(1000);  // 585 ms
    mergeSortExample(10000); // 5304 ms
                             // mergeSortExample(100000);  // 50664 ms
                             // mergeSortExample(1000000);  // 511381 ms
}

void task2()
{
    bubbleSortDescendingExample(); // 719 ms
    bubbleSortAscendingExample();  // 426 ms
    cout << endl;

    shakerSortDescendingExample(); // 821 ms
    shakerSortAscendingExample();  // 566 ms
    cout << endl;

    mergeSortDescendingExample(); // 3 ms
    mergeSortAscendingExample();  // 3 ms
    cout << endl;
}

int main(void)
{
    task1();
    cout << endl
         << endl;

    task2();
    cout << endl;

    return 0;
}

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Вариант - 3

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
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

void selectionSort(int arr[], int size)
{
    int minIndex;

    for (int i = 0; i < size - 1; i++)
    {
        // Find the min in the unsorted array
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void selectionSortDescendingOrder()
{
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int arr[] = {64, 25, 12, 11, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);

    selectionSort(arr, size);

    printArray(arr, size);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}

void bubbleSortDescendingOrder()
{
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int arr[] = {64, 25, 12, 11, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);

    bubbleSort(arr, size);

    printArray(arr, size);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}

void selectionSortAscendingOrder()
{
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int arr[] = {1, 11, 12, 25, 64};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);

    selectionSort(arr, size);

    printArray(arr, size);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}

void bubbleSortAscendingOrder()
{
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int arr[] = {1, 11, 12, 25, 64};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);

    bubbleSort(arr, size);

    printArray(arr, size);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}

void selectionSortRandonNumbers(int size)
{
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int *arr = generateRandomArray(size);

    selectionSort(arr, size);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function (size: " << size << ") : "
         << duration.count() << " microseconds" << endl;
}

void bubbleSortRandonNumbers(int size)
{
    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int *arr = generateRandomArray(size);

    bubbleSort(arr, size);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function (size: " << size << ") : "
         << duration.count() << " microseconds" << endl;
}

void testSelectionSort()
{
    selectionSortDescendingOrder(); // 1702 ms
    cout << endl;

    selectionSortAscendingOrder(); // 650 ms
    cout << endl;

    // Random N numbers
    selectionSortRandonNumbers(100); // 25 ms
    cout << endl;

    // selectionSortRandonNumbers(1000);  // 1088 ms
    cout << endl;

    // selectionSortRandonNumbers(10000);  // 94634 ms
    cout << endl;

    // selectionSortRandonNumbers(100000);  // 8818236 ms | 8.8182 s
    cout << endl;

    // selectionSortRandonNumbers(1000000);  // 67048860 ms | 67.0489 s
    cout << endl;
}

void testBubbleSort()
{
    bubbleSortDescendingOrder(); // 900 ms
    cout << endl;

    bubbleSortAscendingOrder(); // 626 ms
    cout << endl;

    // Random N numbers
    bubbleSortRandonNumbers(100); // 60 ms
    cout << endl;

    // bubbleSortRandonNumbers(1000);  // 2229 ms
    cout << endl;

    // bubbleSortRandonNumbers(10000);  // 112235 ms
    cout << endl;

    // bubbleSortRandonNumbers(100000);  // 9594501 ms | 9.5945 s
    cout << endl;

    // bubbleSortRandonNumbers(1000000);  // 76756008 ms | 76.756 s
    cout << endl;
}

int main()
{
    // testSelectionSort();

    testBubbleSort();
}

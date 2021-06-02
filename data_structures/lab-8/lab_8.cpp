#include <string>
#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

int *generateArray(int size)
{
    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = i; //Generate number between 0 to 99
    }

    return arr;
}

// Линейный поиск
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

// Поиск с барьером
int searchWithBarrier(int arr[], int n, int key)
{
    if (n != 0)
    {
        int last = arr[n - 1];
        arr[n - 1] = key;
        int i = 0;

        for (i = 0; arr[i] != key; ++i)
        {
        }

        arr[n - 1] = last;
        if (i != (n - 1) || key == last)
        {
            return i;
        }
    }

    return -1;
}

struct University
{
    int code;
    string name;
};

University *generateUniversities(int size)
{
    University *arr = new University[size];

    for (int code = 0; code < size; code++)
    {
        arr[code] = {code + 1, "Jim Smith"};
    }

    return arr;
}

// Рекурсивный бинарный поиск
int binarySearch(University arr[], int left, int right, int key)
{
    if (right >= left)
    {
        // "середина" массива
        int middle = left + (right - left) / 2;

        if (arr[middle].code == key)
            return middle;

        // Если элемент меньше середины, то ищем в левой части массива
        if (arr[middle].code > key)
            return binarySearch(arr, left, middle - 1, key);

        // Иначе - ищем во второй
        return binarySearch(arr, middle + 1, right, key);
    }

    // Элемента в массиве нет
    return -1;
}

void linearSearchExample(int size)
{
    cout << "Linear search: \n";

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int *arr = generateArray(size);
    cout << "Key index: " << linearSearch(arr, size - 1, size - 5) << endl;

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}

void searchWithBarrierExample(int size)
{
    cout << "Search with barrier: \n";

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int *arr = generateArray(size);
    cout << "Key index: " << searchWithBarrier(arr, size - 1, size - 5) << endl;

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}

void task1()
{
    linearSearchExample(100);     // 488 ms
    linearSearchExample(1000);    // 182 ms
    linearSearchExample(10000);   // 299 ms
    linearSearchExample(100000);  // 720 ms
    linearSearchExample(1000000); // 3941 ms

    cout << endl
         << endl;

    searchWithBarrierExample(100);     // 102 ms
    searchWithBarrierExample(1000);    // 169 ms
    searchWithBarrierExample(10000);   // 271 ms
    searchWithBarrierExample(100000);  // 507 ms
    searchWithBarrierExample(1000000); // 3713 ms
}

void task2()
{
    cout << "Binary search:\n";
    // Complexity: O(log n)

    int n = 10;
    int key = 2;
    University *arr = generateUniversities(n);
    cout << "Key index: " << binarySearch(arr, 0, n - 1, key) << endl;
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

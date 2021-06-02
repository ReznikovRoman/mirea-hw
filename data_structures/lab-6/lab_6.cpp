#include <string>
#include <iostream>
#include <stack>
using namespace std;

// 1. Рекурсивный бинарный поиск
int binarySearch(int arr[], int left, int right, int key)
{
    if (right >= left)
    {
        // "середина" массива
        int middle = left + (right - left) / 2;

        if (arr[middle] == key)
            return middle;

        // Если элемент меньше середины, то ищем в левой части массива
        if (arr[middle] > key)
            return binarySearch(arr, left, middle - 1, key);

        // Иначе - ищем во второй
        return binarySearch(arr, middle + 1, right, key);
    }

    // Элемента в массиве нет
    return -1;
}

// 2. Создание двунаправленного списка (без рекурсии ?)
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

// Вставить новую ноду в начало списка
void push(Node **headRef, int newData)
{
    Node *newNode = new Node();
    newNode->data = newData;

    newNode->next = (*headRef);
    newNode->prev = NULL;

    // Переставляем "предыдущий" указатель на добавленную ноду
    if ((*headRef) != NULL)
    {
        (*headRef)->prev = newNode;
    }

    // Переставляем указатель на добавленную ноду
    (*headRef) = newNode;
}

// Вывод двунаправленного списка
void printList(Node *node)
{
    cout << "Iterate in forward direction \n";
    while (node != NULL)
    {
        cout << " " << node->data << " ";
        node = node->next;
    }
}

void task1()
{
    int arr[] = {2, 3, 4, 10, 40};
    int key = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, key);

    cout << "Index of `" << key << "`: " << result << endl;
}

void task2()
{
    Node *head = NULL;

    push(&head, 7);
    push(&head, 1);

    cout << "List items: ";
    printList(head);
}

int main(void)
{
    task1();
    cout << endl;

    task2();
    cout << endl;

    return 0;
}

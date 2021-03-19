#include <iostream>
using namespace std;


/*

1. Информационная часть узла определена вариантом                       +
2. Разработать функцию для создания исходного списка, используя         +
функцию вставки нового узла перед первым узлом.                         +
3. Разработать функцию вывода списка.                                   +

Вариант 7:

Дан линейный однонаправленный список L
                                                    #1                  +
                                                    #2                  +
                                                    #3                  -
1) Разработать функцию, которая
проверяет, есть ли в списке L два одинаковых
элемента.
2) Разработать функцию, которая удаляет
из списка L максимальное значение.
3) Разработать функцию, которая
вставляет в список L новое значение перед
каждым узлом в четной позиции.

*/


struct Node 
{
    int data;
    Node* next;
};


// Print list's content starting from the head
void printList(Node* n) 
{
    while (n != NULL) 
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// Insert a new node with given data on the front of the list
void push(Node** headRef, int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}


// Insert a new node after the given previous node
void insertAfter(Node* prevNode, int newData)
{
    if (prevNode == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}


// Append a new node at the end
void append(Node** headRef, int newData)
{
    Node* newNode = new Node();
    Node* last = *headRef;
    newNode->data = newData;

    // if list is empty - make the new node as head
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }

    // find the last node
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
    return;
}


// Delete the first occurence of key in the list
void deleteNodeByKey(Node** headRef, int key)
{
    Node* temp = *headRef;
    Node* previous = NULL;

    if (temp != NULL && temp->data == key)
    {
        *headRef = temp->next;
        delete temp;
        return;
    }
    else 
    {
        while (temp != NULL && temp->data != key)
        {
            previous = temp;
            temp = temp->next;
        }

        // if there is no key in the list
        if (temp == NULL)
        {
            cout << "There is no " << key << " in the list\n";
            return;
        }

        previous->next = temp->next;  // unlink the node from  the list
        delete temp;
    }
}


int getLargestElement(Node** headRef) {
    int maxElement = INT_MIN;
    Node* element = *headRef;

    while (element != NULL)
    {
        if (maxElement < element->data)
        {
            maxElement = element->data;
        }
        element = element->next;
    }

    return maxElement;
}


void deleteLargestElement(Node** headRef)
{
    deleteNodeByKey(headRef, getLargestElement(headRef));
}


bool hasDuplicates(Node* head)
{
    while (head->next != NULL)
    {
        Node* ptr = head->next;
        while (ptr != NULL)
        {
            if (ptr->data == head->data)
            {
                return true;
            }
        }
    }

    return false;
}




int main()
{
    Node* head = NULL;

    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 2);

    printList(head);

    deleteLargestElement(&head);
    printList(head);

    cout << "List has duplicates?(1-yes, 0-no) " << hasDuplicates(head);
    
}


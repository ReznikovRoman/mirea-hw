#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Print list's content starting from the head
void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// Get length of the list
int getLength(Node *head)
{
    int length = 0;
    Node *current = head;

    while (current != NULL)
    {
        length++;
        current = current->next;
    }

    return length;
}

// Create new Node
Node *getNode(int newData)
{
    Node *newNode = new Node();

    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

// Insert a new node with given data on the front of the list
void push(Node **headRef, int newData)
{
    Node *newNode = getNode(newData);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Insert a new node after the given previous node
void insertAfter(Node *prevNode, int newData)
{
    if (prevNode == NULL)
    {
        cout << "The given previous node cannot be NULL" << endl;
        return;
    }

    Node *newNode = getNode(newData);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Insert new Node at required position
void insertPos(Node **current, int pos, int newData)
{
    int size = getLength(*current);

    if (pos < 1 || pos > size + 1)
    {
        cout << "Invalid position" << endl;
    }
    else
    {
        while (pos--)
        {
            if (pos == 0)
            {
                Node *temp = getNode(newData);
                temp->next = *current;
                *current = temp;
            }
            else
            {
                current = &(*current)->next;
            }
            size++;
        }
    }
}

// Append a new node at the end
void append(Node **headRef, int newData)
{
    Node *newNode = getNode(newData);
    Node *last = *headRef;

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
void deleteNodeByKey(Node **headRef, int key)
{
    Node *temp = *headRef;
    Node *previous = NULL;

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
            cout << "There is no " << key << " in the list" << endl;
            return;
        }

        previous->next = temp->next; // unlink the node from  the list
        delete temp;
    }
}

// Get largest element from the list
int getLargestElement(Node **headRef)
{
    int maxElement = INT_MIN;
    Node *element = *headRef;

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

// Task - 1
void deleteLargestElement(Node **headRef)
{
    cout << "\nTask - 1" << endl;
    deleteNodeByKey(headRef, getLargestElement(headRef));
}

// Task - 2
bool hasDuplicates(Node *head)
{
    cout << "\nTask - 2";
    while (head->next != NULL)
    {
        Node *ptr = head->next;
        while (ptr != NULL)
        {
            if (ptr->data == head->data)
            {
                cout << endl;
                return true;
            }
            ptr = ptr->next;
        }
        head = head->next;
    }

    cout << endl;
    return false;
}

// Task - 3
void insertValueAtEvenPos(Node **headRef, int value)
{
    cout << "\nTask - 3";
    int size = getLength(*headRef);
    int insertCount = 0;

    Node *element = *headRef;

    for (size_t i = 1; i < size + 1; i += 2)
    {
        insertPos(headRef, i + insertCount, value); // insert node at odd positions (before even ones)
        insertCount++;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 7);
    push(&head, 5);
    push(&head, 5);

    printList(head);

    deleteLargestElement(&head);
    printList(head);

    cout << "List has duplicates?(1-yes, 0-no): " << hasDuplicates(head) << endl;

    insertValueAtEvenPos(&head, 999);
    printList(head);
}

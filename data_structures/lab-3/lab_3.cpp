#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Вариант - 7

struct Date
{
    int year{};
    int month{};
    int day{};
};

bool operator==(const Date &date1, const Date &date2)
{
    return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
}

bool operator!=(const Date &date1, const Date &date2)
{
    return (date1.year != date2.year || date1.month != date2.month || date1.day != date2.day);
}

struct Product
{
    int id{};
    Date dateOfSale{};
    float price{};
    string productNote{};
};

struct Node
{
    Product data;
    Node *next;
    Node *prev;
};

// Print list's content starting from the head
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data.id << " ";
        node = node->next;
    }
    cout << endl;
}

// Print list's content starting from the last element
void printReversedList(Node *node)
{
    struct Node *p;
    p = node;

    while (p->next != NULL)
        p = p->next;

    while (p != NULL)
    {
        cout << p->data.id;
        p = p->prev;
    }

    cout << endl;
}

// Create new Node
Node *getNode(Product newData)
{
    Node *newNode = new Node();

    newNode->data = newData;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert a new node with given data on the front of the list
void push(Node **headRef, Product newData)
{

    Node *newNode = getNode(newData);
    newNode->next = *headRef;

    if (*headRef != NULL)
    {
        newNode->prev = *headRef;
    }

    *headRef = newNode;
}

// Get node by the given key (product ID)
Node *getNodeByKey(Node **headRef, int key)
{
    Node *temp = *headRef;
    Node *previous = NULL;

    if (temp != NULL && temp->data.id == key)
    {
        *headRef = temp->next;
        return temp;
    }
    else
    {
        while (temp != NULL && temp->data.id != key)
        {
            previous = temp;
            temp = temp->next;
        }

        // if there is no key in the list
        if (temp == NULL)
        {
            cout << "There is no " << key << " in the list" << endl;
            return 0;
        }

        return temp;
    }
}

// Compare 2 given `Dates`
bool compareDates(const Date &d1, const Date &d2)
{
    if (d1.year < d2.year)
        return true;
    if (d1.year == d2.year && d1.month < d2.month)
        return true;
    if (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day)
        return true;

    return false;
}

// Sort products by `date of sale`
void sortByDateOfSale(Node *head)
{
    for (Node *i = head; i; i = i->next)
    {
        for (Node *j = head; j; j = j->next)
        {
            if (compareDates(i->data.dateOfSale, j->data.dateOfSale))
            {
                Product temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Delete product from the list by the given `id` and `date`
void deleteProductByDateAndId(Node **headRef, int productId, Date date)
{
    Node *temp = *headRef;
    Node *previous = NULL;
    vector<pair<Node *, Node *>> nodesToDelete = {};

    if (temp != NULL && temp->data.id == productId && temp->data.dateOfSale == date)
    {
        *headRef = temp->next;
        delete temp;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data.id == productId && temp->data.dateOfSale == date)
            {
                nodesToDelete.push_back(pair<Node *, Node *>(previous, temp));
            }
            previous = temp;
            temp = temp->next;
        }

        // if there is no such product in the list
        if (nodesToDelete.empty())
        {
            cout << "There is no such product in the list" << endl;
            return;
        }

        for (auto nodeToDelete : nodesToDelete)
        {
            nodeToDelete.first->next = nodeToDelete.second->next; // unlink the node from the list
            delete nodeToDelete.second;
        }
    }
}

int main()
{
    Node *head = NULL;

    // Create products
    Product p1{1, Date{2021, 5, 6}, 10, "apple"};
    Product p2{2, Date{2021, 5, 7}, 15, "orange"};
    Product p3{3, Date{2021, 5, 9}, 20, "banana"};
    Product p4{4, Date{2022, 12, 9}, 25, "kiwi"};
    Product p5{4, Date{2022, 12, 9}, 30, "kiwi"};
    Product p6{4, Date{2021, 10, 25}, 35, "kiwi"};

    // Push products to the list
    push(&head, p1);
    push(&head, p3);
    push(&head, p2);
    push(&head, p4);
    push(&head, p5);
    push(&head, p6);

    printList(head); // >>> 4 4 4 2 3 1

    // Sort list of products (task-1)
    sortByDateOfSale(head);

    printList(head); // >>> 1 2 3 4 4 4

    // Delete all `kiwis` that were sold on `Date{2022, 12, 9}`
    deleteProductByDateAndId(&head, 4, Date{2022, 12, 9});

    printList(head);
}

#include <string>
#include <iostream>
#include <stack>
using namespace std;

// Задание 1
// Получаем приоритет операторов
int getOperatorsPrecedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Конвертируем инфиксную форму в постфиксную
string infixToPostfix(string s)
{
    stack<char> operationsStack;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // Добавляем операнды к результату
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'))
        {
            result += c;
        }

        // "Обработка скобок"
        else if (c == '(')
            operationsStack.push('(');

        else if (c == ')')
        {
            while (!operationsStack.empty() && operationsStack.top() != '(')
            {
                char temp = operationsStack.top();
                operationsStack.pop();
                result += temp;
            }
            operationsStack.pop();
        }
        else
        {
            while (!operationsStack.empty() &&
                   getOperatorsPrecedence(s[i]) < getOperatorsPrecedence(operationsStack.top()))
            {
                char temp = operationsStack.top();
                operationsStack.pop();
                result += temp;
            }
            operationsStack.push(c);
        }
    }

    // Убираем оставшиеся элементы из стэка
    while (!operationsStack.empty())
    {
        char temp = operationsStack.top();
        operationsStack.pop();
        result += temp;
    }

    return result;
}

// Задание - 2 (стек реализован с помощью списка)
struct StackNode
{
    int data;
    StackNode *next;
};

StackNode *newNode(int data)
{
    StackNode *stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// 2 - "Пуст ли стек"
int isEmpty(StackNode *root)
{
    return !root;
}

// 2 - "Воткнуть элемент в стек"
void push(StackNode **root, int data)
{
    StackNode *stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    cout << data << " pushed to stack\n";
}

// 2 - "Вытолкнуть элемент из стек"
int pop(StackNode **root)
{
    if (isEmpty(*root))
        return INT_MIN;
    StackNode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

// 2 - "Вернуть значение вершины стека"
int peek(StackNode *root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

void task1()
{
    string exp = "((a+b)*c)";

    cout << infixToPostfix(exp) << endl; // ab + c*
}

void task2()
{
    StackNode *root = NULL;

    push(&root, 1);
    push(&root, 2);
    push(&root, 3);

    cout << pop(&root) << " has been popped from stack\n";

    cout << "Top element is " << peek(root) << endl;

    cout << "Elements in stack : ";
    while (!isEmpty(root))
    {
        // Выводим значение "верхнего" элемента
        cout << peek(root) << " ";

        // Удаляем значение "верхнего" элемента
        pop(&root);
    }
}

int main()
{
    task1();
    cout << endl;

    task2();
    cout << endl;

    return 0;
}

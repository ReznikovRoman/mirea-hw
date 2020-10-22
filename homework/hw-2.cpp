

#include <iostream>
#include <cmath>
using namespace std;


/*
 Комментарии к дз-2:

0. Добавил интерфейс (возможность выбирать номера заданий)

1. По первому заданию: - добавил интерфейс и проверку
задача не доделана.
нет интерфейса.
нет проверки на существование конуса.
нет условий проверки ввода данных.
сама работа работает некорректно. - программа работает корректно

2. По второму заданию - исправил проверку
программа работает неверно.

3. По третьему заданию: - исправил проверку
программа вообще не выполняется.

4. По четвертому заданию: - добавил интерфейс
Число я должен вводить с клавиатуры. задание не выполнено.

5. По пятому заданию: - программа работает корректно
программа работает некорректно

*/



void task1()
{
    cout << endl << "Task - 1" << endl;

    double h, r, R, l;
    cout << "Enter height, lower and upper radii, slant height: ";
    cin >> h >> r >> R >> l;

    double V, S;

    const double PI = 3.141592653589793;
    
    try
    {
        V = (PI * h * (R * R + R * r + r * r)) / 3;
        S = PI * (R * R + (R + r) * l + r * r);

        cout << "V: " << V << endl;
        cout << "S: " << S << endl << endl;
    }
    catch (...)
    {
        cout << "error";
    }

    cout << endl;
}

void task2()
{
    float w, a, x;

    cout << endl << "Task 2" << endl << "Enter 'a' and 'x': ";
    cin >> a >> x;

    if ((a - x * x) < 0 || abs(x) < 0) { cout << "Error" << endl; }
    else
    {
        if (abs(x) < 1) { w = a * log(abs(x)); }
        if (abs(x) >= 1) { w = sqrt(a - x * x); }

        cout << "W: " << w << endl;
    }
}

void task3()
{
    cout << endl << "Task - 3" << endl;

    float z;
    float x = -1, y = -1, b = -1;

    cout << "Enter b, y, x: ";
    cin >> b >> y >> x;

    if ((b - y) < 0 || (b - x) < 0) { cout << "Error" << endl; }
    else
    {
        z = (log(b - y)) * sqrt(b - x);

        cout << "Z: " << z << endl;
    }
}

void task4()
{
    cout << endl << "Task - 4" << endl;

    int N;
    cout << "Enter N: ";
    cin >> N;

    for (int i = 0; i < 10; ++i)
    {
        cout << "I: " << i + 1 << "\t\tN: " << N << endl;
        N += 5;
    }

    cout << endl;
}



float f5(const float& x5)
{
    return ((x5 * x5 - 2 * x5 + 2) / (x5 - 1));
}

void task5()
{
    cout << endl << "Task - 5" << endl;

    for (float i = -4; i < 4.5; i += 0.5)
    {
        cout << "Current x: " << i << "\t\tF(x): " << f5(i) << endl;
    }
    cout << endl;
}


// array of pointers to void functions with no params
void (*funcPtrs[])() = { task1, task2, task3, task4, task5 };


int main()
{
    cout << endl << "Homework - 2" << endl << endl;

    
    while (true)
    {
        int taskNum;

        cout << "Which task do you want to check (1-5, 0 to quit) ?: ";
        cin >> taskNum;

        if (taskNum == 0) break;

        try
        {
            (*funcPtrs[taskNum - 1])();
        }
        catch (...)
        {
            continue;
        }

        cout << endl;
    }
    

    return 0;
}



#include <iostream>

#include <vector>
using namespace std;


void task1()
{

    /*
        a + b * n < c
        b * n < c - a
        n < (c - a) / b
        n = (c - a) mod b
     */

    cout << endl << "1 - Spinners" << endl;

    int a; // стоимость основания спиннера
    int b; // стоимость одной лопасти
    int c; // максимальная стоимость всего спиннера
    int n; // кол-во лопастей

    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;

    n = (c - a) / b;
    cout << "N: " << n << endl;

    cout << endl;
}


void task2()
{

    /*
    1. Надо использовать все M лопастей, неограниченный запас оснований
    */

    cout << endl << "2 - Spinners again" << endl;

    int m; // кол-во лопастей (в спиннере либо 3, либо 4 лопасти)
    int n3, n4; // кол-во произведенных спиннеров с 3 и 4 лопастями соотв.

    cout << "Enter m: ";
    cin >> m;

    n4 = m % 3;  // m % 3 == 1 ==> n4 = 1 ||||| m % 3 == 2 ==> n4 = 2
    n3 = (m - 4 * n4) / 3; // оставшиеся лопасти идут на трехлопастные спиннеры

    if (n3 >= 0) { cout << "n3: " << n3 << endl << "n4: " << n4 << endl; }
    else { cout << 0 << endl << 0; }

    cout << endl;
}


void task3()
{
    cout << endl << "3 - Not about spinners" << endl;



    cout << endl;
}


void task4()
{
    cout << endl << "4 - Train carriage" << endl;



    cout << endl;
}


void task5()
{
    cout << endl << "5 - Cinema" << endl;



    cout << endl;
}



int main()
{

    task1(); // задача 1 - спиннеры

    task2(); // задача 2 - снова спиннеры

    task3(); // задача 3 - не про спиннеры

    task4(); // задача 4 - плацкартный вагон

    task5(); // задача 5 - кинотеатр


    return 0;
}

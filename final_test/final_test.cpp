

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

    if (n3 >= 0) cout << "n3: " << n3 << endl << "n4: " << n4 << endl;
    else cout << 0 << endl << 0;

    cout << endl;
}


void task3()
{
    cout << endl << "3 - Not about spinners" << endl;

    int n, m, ansX = 0, ansY = 0;
    cin >> n;
    cin >> m;

    for (int x1 = 0; x1 < n; x1++)
    {
        for (int x2 = x1; x2 < n; x2++)
        {
            ansX += 1;
        }
    }

    for (int y1 = 0; y1 < m; y1++)
    {
        for (int y2 = y1; y2 < m; y2++)
        {
            ansY += 1;
        }
    }

    cout << ansX * ansY;

    cout << endl;
}


/*
* Находит номер купе по номеру свободного места
*/
int section(int k)
{
    if (k <= 36) return (k - 1) / 4;
    return 8 - (k - 37) / 2;
}

void task4()
{
    cout << endl << "4 - Train carriage" << endl;

    int count[9] = { }; // число свободных мест в i-ом купе
    int n;
    int ans = 0, curr = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int fp;
        cin >> fp;
        count[section(fp)] += 1;
    }

    // находим самое большое число подряд идущих 6 (т.е. свободных купе)
    for (int i = 0; i < 9; i++)
    {
        if (count[i] == 6)
        {
            curr += 1;
            ans = max(ans, curr);
        }
        else
        {
            curr = 0;
        }
    }

    cout << ans;

    cout << endl;
}


void task5()
{
    cout << endl << "5 - Cinema" << endl;



    cout << endl;
}



int main()
{

    task1(); // задача 1 - спиннеры - DONE

    task2(); // задача 2 - снова спиннеры - DONE

    task3(); // задача 3 - не про спиннеры - DONE

    task4(); // задача 4 - плацкартный вагон - DONE

    // task5(); // задача 5 - кинотеатр


    return 0;
}

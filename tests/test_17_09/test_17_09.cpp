

#include <iostream>

#include <string>

#include <vector>

using namespace std;


void task1()
{

    cout << endl << "Task-1" << endl;

    int S = 45;
    int V, T;

    cin >> V;
    cin >> T;

    cout << (V * T) % S;

    cout << endl;
}


void task2()
{
    cout << endl << "Task-2" << endl;

    int X;

    cin >> X;

    cout << X / 100;

    cout << endl;
}


void task3()
{
    cout << endl << "Task-3" << endl;

    int D, S;

    cin >> D;
    cin >> S;

    cout << S / D;

    cout << endl;
}


void task4()
{
    cout << endl << "Task-4" << endl;

    int X;
    
    cin >> X;

    cout << (X / 10) % 5;

    cout << endl;
}


void task5()
{
    cout << endl << "Task-5" << endl;

    float X, Y;
    cin >> X;
    cin >> Y;

    if (((X < -100) || (X > 100)) && ((Y < -100) || (Y > 100)))
    {
        cout << "Error." << endl;
    }
    else 
    {
        if ((Y > X * X - 2) && ((Y > -X) || (Y < X))) { cout << "YES"; }
        else { cout << "NO"; }
    }

    cout << endl;
}


void task6()
{
    cout << endl << "Task-6" << endl;

    int A, B;

    cin >> A;
    cin >> B;

    for (int i = A; i < B; i++)
    {
        if (i % 3 == 0) { cout << i << " "; }
    }

    cout << endl;
}


void task7()
{
    cout << endl << "Task-7" << endl;

    // a1 = 5; d = 2

    int S,n;

    int a1 = 5, d = 2;
    
    cin >> S;

    n = (S - a1 + d) / d;

    cout << n;

    cout << endl;
}


void task8()
{
    cout << endl << "Task-8" << endl;

    int x = -1;
    int count = 0;

    while (x != 0)
    {

        cin >> x;

        if ((x < 1) || (x > 1000))
        {
            cout << "Error" << endl;
            break;
        }

        if (((x % 19) == 0) && (x != 0)) { count++; }

    }

    cout << count;

    cout << endl;
}


int factorial(int n)
{
    if (n >= 1) { return n * factorial(n-1); }
    else { return 1; }
}

void task9()
{
    cout << endl << "Task-9" << endl;

    int x;

    cin >> x;

    cout << factorial(x);

    cout << endl;
}


int addN(int x, int start)
{
    if (((start + 8) == x) || ((start + 9) == x)) { return x; }
    else if (((start + 8) > x) && ((start + 9) > x)) { return -x; }
    else
    { 
        return addN(x, start + 8);
        return addN(x, start + 9);
    }
}

void task10()
{
    cout << endl << "Task-10" << endl;

    int X;

    cin >> X;

    int ans = addN(X, 1);

    if (X < 1) { cout << "NO"; }
    else 
    {
        if (ans == X) { cout << "YES"; }
        if (ans == -X) { cout << "NO"; }
    }

    cout << endl;
}


void task11()
{
    cout << endl << "Task-11" << endl;

    int n;
    vector<int> a;
    int sum = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        a.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        if ((a[i] % 7) == 0) { sum += a[i]; }
    }

    cout << sum;

    cout << endl;
}


void task12()
{
    cout << endl << "Task-12" << endl;

    int n;
    vector<int> a;
    int maxN = -1;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        a.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        if (((a[i] % 3) == 0) && (a[i] > maxN)) { maxN = a[i]; }
    }

    if (maxN != -1) { cout << maxN; }
    else { cout << "There are no multiples of 3 in the vector."; }

    cout << endl;
}



int main()
{
    //task1();

    //task2();

    //task3();

    //task4();

    //task5();

    //task6();

    //task7();
    
    //task8();

    //task9();
    
    //task10();
    
    //task11();

    task12();


    return 0;
}

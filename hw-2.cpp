

#include <iostream>
#include <cmath>
using namespace std;

void task1(double h, double r, double R, double l)
{
    double V, S;

    const double PI = 3.141592653589793;

    V = (PI * h * (R*R + R*r +r*r)) / 3;
    S = PI * (R * R + (R + r) * l + r * r);


    cout << endl << "Task - 1" << endl;
    cout << "V: " << V << endl;
    cout << "S: " << S << endl << endl;

}

void task2()
{
    float w, a, x;

    cout << endl << "Task 2" << endl << "Enter 'a' and 'x': ";
    cin >> a >> x;

    if ((x >= 1 || x <= -1) && ((a - x * x) < 0)) { cout << "Error" << endl; }
    else
    {
        if (x < 1 && x > -1) { w = a * log(abs(x)); }
        if (x >= 1 || x <= -1) { w = sqrt(a - x * x); }

        cout << "W: " << w << endl;
    }
}

void task3(float x, float y, float b)
{
    float z;

    cout << endl << "Task - 3" << endl;

    if (b - y < 0 || b - x < 0) { cout << "Error" << endl; }
    else
    {
        z = (log(b - y)) * sqrt(b - x);

        cout << "Z: " << z << endl;
    }
}

void task4(int N)
{

    cout << endl << "Task - 4" << endl;
    for (int i = 0; i < 10; ++i)
    {
        cout << "I: " << i + 1 << "\t\tN: " << N << endl;
        N += 5;
    }
    cout << endl;
}



float f5(float x5)
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


int main()
{
    task1(2, 7, 1, 10);
    task2();
    task3(100, 5, 90); // 3, 5, 6
    task4(5);
    task5();

    return 0;
}

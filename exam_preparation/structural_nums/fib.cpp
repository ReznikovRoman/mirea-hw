#include <iostream>

using namespace std;

int fib(const int &n)
{
    if (n <= 1) { return n; }

    return fib(n - 1) + fib(n - 2);
}


int main()
{

    int n;
    cout << endl << "\tFibonacci sequence" << endl;

    cout << "\tEnter 'n': ";
    cin >> n;

    cout << endl << "\tFib_n: " << fib(n) << endl;
}
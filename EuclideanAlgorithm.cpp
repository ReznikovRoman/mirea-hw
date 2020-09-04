

#include <iostream>
using namespace std;

int gcd(int num1, int num2)
{
    while (num1 != num2)
    {
        if (num1 > num2) { num1 -= num2; }
        else { num2 -= num1; }
    }

    return num2;
}


int main()
{
    // Алгоритм Евклида - наибольший общий делитель
    int ans;

    ans = gcd(35, 10);

    cout << "GCD: " << ans << endl;

    return 0;
}

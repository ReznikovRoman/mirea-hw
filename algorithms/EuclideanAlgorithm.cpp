

#include <iostream>
using namespace std;

int gcd(int num1, int num2)
{
    // Пока числа не равны (==> пока не нашли НОД)
    // Отнимаем от большего числа меньшее
    
    // Пример
    /*
    1. 35, 10  (35 > 10 ==> 35 - 10)
    2. 25, 10  (25 > 10 ==> 25 - 10)
    3. 15, 10  (15 > 10 ==> 15 - 10)
    4. 5, 10  (10 > 5 ==> 10 - 5)
    5. 5, 5  (5 == 5 ==> gcd = 5)

    --> 5
    */
    

    while (num1 != num2) // 
    {
        if (num1 > num2) { num1 -= num2; }  // 
        else { num2 -= num1; }
    }

    return num2;
}


int main()
{
    // Алгоритм Евклида - наибольший общий делитель
    int ans;
	
	cin >> x >> y;

    ans = gcd(x, y);

    cout << "GCD: " << ans << endl;

    return 0;
}

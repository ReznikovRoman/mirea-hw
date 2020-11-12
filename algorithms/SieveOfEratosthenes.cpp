

#include <iostream>
#include <vector>
using namespace std;


void SieveOfEratosthenes()
{
    cout << endl << "Sieve Of Eratosthenes" << endl;

    /*
    
    - Заполнить массив из N элементов целыми числами подряд от 2 до N.
    - Присвоить переменной p значение 2 (первого простого числа).
    
    - Удалить из массива числа от p2 до N с шагом p (это будут числа кратные p: p2, p2+p, p2+2p и т. д.).
    - Найти первое неудаленное число в массиве, большее p, и присвоить значению переменной p это число.
    - Повторять два предыдущих шага пока это возможно.
    
    */

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 0; i < n + 1; i++)
    {
        a[i] = i;
    }

    for (int p = 2; p < n + 1; p++)
    {
        if (a[p] != 0)
        {
            cout << a[p] << endl;
            for (int j = p * p; j < n + 1; j += p) a[j] = 0; 
        }
    }

    cout << endl;
}


int main()
{
    SieveOfEratosthenes();

    return 0;
}

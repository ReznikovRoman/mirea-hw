

#include <iostream>


using namespace std;


void task1()
{
    cout << endl << "Task - 1" << endl;

    int N;
    string ans = "N is: ";

    cin >> N;

    if (N < 0) { ans += "negative"; }
    else { ans += "positive"; }

    if (N % 2 != 0) { ans += "; odd"; }
    else { ans += "; even"; }

    if (N > -3) { ans += "; bigger than 3."; }
    else { ans += "; less than 3 (or equal)."; }

    cout << ans;

    cout << endl;
}



void task2()
{
    cout << endl << "Task - 2" << endl;

    float x, y;
    cin >> x;

    bool flag = true;

    if (x < 0) { y = abs(x + 1); }
    
    if ((x > 0) and (abs(x-1) > 0)) { y = log(x - 1); }
    else if (abs(x - 1) <= 0)
    { 
        cout << "No solutions."; 
        flag = false; 
    }
    
    if (x == 0) { y = sqrt(9 - x) / 3; }

    if (flag) { cout << "X: " << x << "\tY: " << y; }

    cout << endl;
}


void task3()
{
    cout << endl << "Task - 3" << endl;

    for (int i = 35; i < 88; i++)
    {
        if ((i % 7 == 1) || (i % 7 == 2) || (i % 7 == 5))
        {
            cout << i << " ";
        }
    }

    cout << endl;
}


float f(float x)
{
    return (x * x + x + 1) * log(abs(x) + 1);
}

void task4()
{
    cout << endl << "Task - 4" << endl;
    
    for (float i = -5; i < 5.5; i += 0.5)
    {
        cout << "\tX: " << i << "\t\t" << "Y: " << f(i) << endl;
    }

    cout << endl;
}


int factorial(int n)
{
    if (n >= 1) { return n * factorial(n - 1); }
    else { return 1; }
}

void task5()
{
    cout << endl << "Task - 5" << endl;

    char userInput;
    bool isWorking = true;


    do 
    {
        int x;

        cout << "Enter X: ";
        cin >> x;

        cout << "Factorial of x: " << factorial(x) << endl;
       
        cout << "Stop? (press 'y' or 'Y' to quit): ";
        cin >> userInput;
        cout << endl;

        if ((userInput == 89) || (userInput == 121)) { isWorking = false; }
        
    } while (isWorking);

    cout << endl;
}

int main()
{
    //task1();

    //task2();

    //task3();

    //task4();

    //task5();

    return 0;
}

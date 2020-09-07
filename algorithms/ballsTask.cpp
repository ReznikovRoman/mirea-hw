

#include <iostream>

#include <vector>
using namespace std;


void printBalls(vector<int> balls)
{
    for (int i = 0; i < balls.size(); i++) { cout << balls[i] << " "; }
    cout << endl;
}

void perestanovka(int m, int n, vector<int> balls)
{

    for (int i = 0; i < balls.size(); i++)
    {

        auto iter = balls.cbegin();

        if (i + 1 == m)
        {
            cout << "i: " << i + 1 << endl;
            balls.erase(iter + i);
            printBalls(balls);
        }
        else
        {
            cout << "NO" << endl;
            int temp;
            temp = balls[i];
            balls[i] = balls[m];
            balls[m] = temp;
            printBalls(balls);
        }

        m += 1;
    }
}


void ballsTask()
{
    vector<int> balls;
    int n;

    cout << "Enter balls amount - n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        balls.push_back(i + 1);
    }

    perestanovka(1, n, balls);
    

    


}


int main()
{

    // К какой задаче относится алгоритм генератора перестановок?

    ballsTask();


    return 0;
}

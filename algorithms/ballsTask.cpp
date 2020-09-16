

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


/*

*/


void printBalls(const vector<int> &balls)
{
    for (int i = 0; i < balls.size(); i++) { cout << balls[i] << " "; }
    cout << endl;
}


void ballsTask()
{
    vector<int> balls;
    int n;
    vector<vector<int>> permutations;
    int sum = 0;

    cout << "Enter balls amount - n: ";
    cin >> n;

    for (int i = 1; i < n + 1; i++)
    {
        balls.push_back(i);
    }



    while (next_permutation(balls.begin(), balls.end()))
    {
        permutations.push_back(balls);
    }

    for (auto balls : permutations)
    {
        for (int i = 0; i < balls.size(); i++)
        {
            if (balls[i] == i + 1)
            {
                sum += 1;
                //printBalls(balls); 
            }
        }
    }

    cout << "Sum: " << sum << endl;




}


int main()
{

    ballsTask();


    return 0;
}

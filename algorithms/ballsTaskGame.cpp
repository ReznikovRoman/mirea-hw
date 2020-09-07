

#include <iostream>

#include <vector>

#include <random>
#include <algorithm>
using namespace std;


void printBalls(vector<int> balls)
{
    for (int i = 0; i < balls.size(); i++) { cout << balls[i] << " "; }
    cout << endl;
}


void ballsTask2()
{
    vector<int> balls;
    int n;
    auto rng = default_random_engine{};
    
    int user_score = 0;

    cout << "Enter balls amount - n: ";
    cin >> n;
    cout << endl;

    for (int i = 1; i < n + 1; ++i) { balls.push_back(i); }
    shuffle(balls.begin(), balls.end(), rng);
    
    for (int i = 0; i < n; ++i)
    {
        int user_guess = -1;

        // Get User input
        while (user_guess < 1 || user_guess > n)
        {
            cout << endl;
            cout << "What is the number on the ball #" << i+1 << "?: ";
            cin >> user_guess;
        }
        
        // Check user guess
        if (user_guess == balls[i])
        {
            user_score += 1;
            cout << "Yes, you are right!" << endl;
        }
        else { cout << "No, it is: " << balls[i] << endl; }
    }

    cout << "\n\n" << "Your score is - " << user_score << "." << endl;

}



/*
        "Нормальная игра"

1. Пользователь вводит 'n' - количество шариков
2. Создается вектор длиной n, каждый шарик имеет число (от 1 до n включительно), которое присваивается ему случайным образом
3. Пользователь 'n' раз пытается угадать число, записанное на i-ом шарике
    3.1. Если пользователь угадывает - программа сообщает ему об этом и увеличивает счетчик очков 
    3.2. Если пользователь не угадывает - программа сообщает ему об этом и показывает число, записанное на шарике
4. В конце игры программа выводит пользователю его счет

*/

int main()
{

    ballsTask2();

    return 0;
}

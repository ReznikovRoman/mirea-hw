

#include <iostream>

#include <fstream>
#include <string>

#include <vector>
#include <cmath>
#include <map>

#include <algorithm>
using namespace std;


const float  PI = 3.14159265358979;


void task1()
{

    cout << endl << endl << "Task - 1" << endl;

    string line;
    int sum = 0;

    ofstream in_file;
    in_file.open("task1.txt");

    cout << "Enter 10 numbers:" << endl;
    for (int i = 0; i < 10; i++)
    {
        int x;
        cout << "Enter number: ";
        cin >> x;

        in_file << x << endl;
    }

    in_file.close();

    ifstream out_file;
    out_file.open("task1.txt");
    while (getline(out_file, line))
    {
        sum += stoi(line);
    }

    cout << endl << "Sum: " << sum << endl;
}


int sign(const int& x)
{
    if (x > 0) { return 1; }
    if (x < 0) { return -1; }
    return 0;
}

void task2()
{
    cout << endl << endl << "Task - 2" << endl;

    int x;
    cout << "Enter x: ";
    cin >> x;

    cout << endl << "Sign X: " << sign(x) << endl;
}


int rectangleArea(const int& width, const int& height)
{
    return width * height;
}

float triangleArea(const float& base, const float& height)
{
    return (base * height) / 2;
}

float circleArea(const float& r)
{
    return PI * r * r;
}

void task3()
{
    cout << endl << endl << "Task - 3" << endl;

    int width, height;
    cout << "Enter width and height of a rectangle: ";
    cin >> width >> height;
    cout << "Rectangle area is: " << rectangleArea(width, height) << endl;
    cout << endl;

    float base, tHeight;
    cout << "Enter base and verical height of a triangle: ";
    cin >> base >> tHeight;
    cout << "Triangle area is: " << triangleArea(base, tHeight) << endl;
    cout << endl;

    float r;
    cout << "Enter radius of a circle, r: ";
    cin >> r;
    cout << "Circle area is: " << circleArea(r) << endl;
    cout << endl;
}

void task4() // былая слава
{
    cout << endl << "Task - 4" << endl << endl;

    int size = 34, height = 13; //11 - stars; ; 13 lines

    vector<string> flag(height, string(size, '-'));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (i % 2 != 0 && j % 2 != 0) { flag[i][j] = '*'; }
            else if (i % 2 != 0 && j % 2 == 0) { flag[i][j] = ' '; }
            else if (i % 2 == 0 && j % 2 == 0) { flag[i][j] = '*'; }
            else if (i % 2 == 0 && j % 2 != 0) { flag[i][j] = ' '; }
        }
    }

    for (auto p : flag)
    {
        if (p == "o") p = "-";
        cout << p << '\n';
    }

    cout << endl;
}


void task5() // синусоида
{

    cout << endl << "Task - 5" << endl;

    int size = 100, height = 21;

    // preparing 'field' with spaces and a line in the middle
    vector<string> chart(height, string(size, ' '));
    chart[height / 2] = std::string(size, '-');

    // calculate the y-values
    for (int i = 0; i < size; i++)
    {
        //cout << (round(10 * sin(i / 4.76)) + 10) << endl;
        chart[(round(10 * sin(i / 4.76)) + 10)][i] = '.';
    }

    //printing the chart
    for (auto p : chart)
    {
        cout << p << '\n';
    }

    cout << endl;
}

void task6()  // автоматный распознаватель
{
    cout << endl << "Task - 6" << endl;

    string s;

    cout << "Enter Roman value: ";
    cin >> s;

    // перевод из римской системы счисления в десятичную
    map<char, int> m = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    int ans = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (m[s[i + 1]] <= m[s[i]]) ans += m[s[i]];
        else ans -= m[s[i]];
    }

    cout << "Ans: " << ans;
    
    cout << endl;
}

void task7()  // генератор случайных чисел
{
    cout << "Task 7" << endl;

    // (m * Si + i) mod c
    int m = 37, i = 3, c = 64;
    int S;

    for (int j = 0; j < i + 10; j++)
    {
        S = rand() % 100;
        S = (m * S + i) % c;
        cout << S << endl;
    }

    cout << endl;
}


void printMatrix(vector<vector<int>> m)
{
    cout << endl;
    for (auto v : m)
    {
        for (auto el : v)
        {
            cout << el << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void task8()  // умножение матриц
{
    int Na, Ma, Nb, Mb;

    cout << "Enter Rows and Columns for matrix A: ";
    cin >> Na >> Ma;

    Nb = Ma;
    Mb = 2;

    vector<vector<int>> A(Na); // A[Na, Ma]
    vector<vector<int>> B(Nb); // B[Ma, 2]
    vector<vector<int>> C(Na); // C[Na, 2]

    float ans1MaxValue = -1, ans1MinValue = 10001, ans2MaxValue = -1, ans2MinValue = 10001;
    int ans1MaxInd = 0, ans2MaxInd = 0, ans1MinInd = 0, ans2MinInd = 0;
    float ans3 = 0, ans4 = 0, ans5 = 0;
    float fee1 = 0, fee2 = 0;

    for (int i = 0; i < Na; i++)
    {
        for (int j = 0; j < Ma; j++)
        {
            cout << "Enter product count: ";
            int x;
            cin >> x;
            A[i].push_back(x);
        }
        cout << endl;
    }

    for (int i = 0; i < Nb; i++)
    {
        cout << "Enter product's price and tax: ";
        int px, tx;
        cin >> px >> tx;
        B[i].push_back(px);
        B[i].push_back(tx);
    }

    for (int i = 0; i < Na; i++)
    {

        for (int j = 0; j < 2; j++)
        {
            C[i].push_back(0);
            for (int k = 0; k < Ma; k++)
            {
               C[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    for (int i = 0; i < Na; i++)
    {
        ans3 += C[i][0];  // общая сумма денег, вырученных за проданные товары

        ans4 += C[i][1];  // сколько всего комиссионных получили продавцы

        ans5 += C[i][0] - C[i][1];  // общая сумма денег, прошедших через руки продавцов (с учетом комиссионных)

        if (C[i][1] > ans2MaxValue)
        {
            ans2MaxValue = C[i][1];
            ans2MaxInd = i;
        }
        else if (C[i][1] < ans2MinValue)
        {
            ans2MinValue = C[i][1];
            ans2MinInd = i;
        }

        if (C[i][0] - C[i][1] > ans1MaxValue)
        {
            ans1MaxValue = C[i][0] - C[i][1];
            ans1MaxInd = i;
        }
        else if (C[i][0] - C[i][1] < ans1MinValue)
        {
            ans1MinValue = C[i][0] - C[i][1];
            ans1MinInd = i;
        }
    }

    cout << "Ans 1: Max: " << ans1MaxInd + 1 << "  Min: " << ans1MinInd + 1 << endl;
    cout << "Ans 2: Max: " << ans2MaxInd + 1 << "  Min: " << ans2MinInd + 1 << endl;
    cout << "Ans 3: " << ans3 << endl << "Ans 4: " << ans4 << endl << "Ans 5: " << ans5;

    cout << endl;
}


int toDigit(const char& c)  // переводим текущий символ в число
{
    if (c >= '0' && c <= '9') { return (int)c - '0'; }
    else { return (int)c - 'A' + 10; }
}

char toChar(const int& num)  // переводим текущее число в строку
{
    if (num >= 0 && num <= 9) { return (char)(num + '0'); }
    else { return (char)(num - 10 + 'A'); }
}


int toDecimal(string s, const int& base)
{

    /*
        1. Умножаем каждую цифру числа на основание текущей с.с. с учетом веса текущего разряда
        2. Записываем сумму полученных произведений
    */

    int num = 0;
    int power = 1;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (toDigit(s[i]) >= base) // если пользователь ввел неверное число (есть цифры >= основанию с.с.)
        {
            cout << "Invalid number!";
            return -1;
        }

        num += toDigit((s[i])) * power;
        power *= base;
    }

    return num;
}

string fromDecimal(int num, const int& base)
{

    /*
       1. Делим 10-ичное число на base(заданную с.с.), запоминаем остатки от деления
       2. Переворачиваем получившиеся остатки
    */

    int index = 0;
    string ans;

    while (num > 0)
    {
        ans += toChar(num % base);
        num /= base;
    }

    reverse(ans.begin(), ans.end());

    return ans;

}

void task9()  // системы счисления
{
    cout << endl << endl << "Task - 9" << endl;

    /*
    1. Переводим число в 10-ичную систему счисления
    2. Из 10-ичной с.с. переводим в заданную с.с.
    */

    string userNum;
    int currBase, newBase;
    cout << "Enter number, current base and new base: ";
    cin >> userNum >> currBase >> newBase;


    //cout << endl << "Decimal value: " << toDecimal(userNum, currBase) << endl;
    cout << endl << "In base " << newBase << " : " << fromDecimal(toDecimal(userNum, currBase), newBase) << endl;
}


// array of pointers to void functions with no params
void (*funcPtrs[])() = { task1, task2, task3, task4, task5, task6, task7, task8, task9 };


// hw-4
int main()
{

    cout << endl << "Homework - 4" << endl;


    while (true)
    {
        int taskNum;

        cout << "Which task do you want to check (1-9, 0 to quit) ?: ";
        cin >> taskNum;

        if (taskNum == 0) break;

        try
        {
            (*funcPtrs[taskNum - 1])();
        }
        catch (...)
        {
            continue;
        }

        cout << endl;
    }


    /*

    task1();  // файл - DONE

    task2();  // знак числа - DONE

    task3();  // геометрические фигуры - DONE

    //task4();  // былая слава - DONE

    //task5();  // синусоида - DONE

    //task6();  // автоматный распознаватель - DONE

    //task7();  // генератор случайных чисел

    //task8();  // умножение матриц - DONE

    task9();  // системы счисления - DONE

    */

    return 0;
}

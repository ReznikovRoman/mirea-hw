

#include <iostream>

#include <fstream>
#include <string>;

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
    in_file << 10 << endl;
    in_file << 12 << endl;
    in_file << 130 << endl;
    in_file << 1 << endl;
    in_file << 24 << endl;
    in_file << 75 << endl;
    in_file << 34 << endl;
    in_file << 87 << endl;
    in_file << 90 << endl;
    in_file << 67 << endl;
    in_file.close();

    ifstream out_file;
    out_file.open("task1.txt");
    while (getline(out_file, line))
    {
        sum += stoi(line);
        cout << line << endl;
    }

    cout << endl << "Sum: " << sum << endl;
}


int sign(const int &x)
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


int rectangleArea(const int &width, const int &height)
{
    return width * height;
}

float triangleArea(const float &base, const float &height)
{
    return (base*height) / 2;
}

float circleArea(const float &r)
{
    return PI * r*r ;
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

void task4()
{

}

void task5()
{

}

void task6()
{

}

void task7()
{

}

void task8()  // умножение матриц
{

}


int toDigit(const char &c)  // переводим текущий символ в число
{
    if (c >= '0' && c <= '9') { return (int)c - '0'; }
    else { return (int)c - 'A' + 10; }
}

char toChar(const int &num)  // переводим текущее число в строку
{
    if (num >= 0 && num <= 9) { return (char)(num + '0'); }
    else { return (char)(num - 10 + 'A'); }
}


int toDecimal(string s, const int &base)
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

string fromDecimal(int num, const int &base)
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


// hw-4
int main()
{

    task1();  // файл

    task2();  // знак числа

    task3();  // геометрические фигуры

    //task4();  // былая слава

    //task5();  // синусоида

    //task6();  // автоматный распознаватель

    //task7();  // генератор случайных чисел

    //task8();  // умножение матриц

    task9();  // системы счисления

    return 0;
}

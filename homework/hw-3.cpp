

#include <iostream>
#include <math.h>

#include <fstream>
#include <string>

#include <algorithm>

using namespace std;


void task1()
{
    float S, p, n, m, r;

    cout << endl << "Task 1";
    cout << endl << "Enter S, p, n: ";
    cin >> S >> p >> n;

    r = p / 100;

    m = (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1));

    cout << "m: " << m << endl;
}

void task2()
{
    // формула - ?
    // https://idroo.com/board-mxn19ajMe1

    float S, p, n, m, r;
    float a1, a2, p1, p2;

    cout << endl << "Task 2";
    cout << endl << "Enter S, m, n: ";
    cin >> S >> m >> n;

    // a = pow((1+r), n)
    // a*a - a*(S + 12*m) + 12*m = 0

    a1 = (S + 12 * m + sqrt((S + 12 * m) * (S + 12 * m) - 4 * 12 * m * S)) / (2 * S);
    a2 = (S + 12 * m - sqrt((S + 12 * m) * (S + 12 * m) - 4 * 12 * m * S)) / (2 * S);

    p1 = (pow(a1, 1 / n) - 1) * 100;
    p2 = (pow(a2, 1 / n) - 1) * 100;

    cout << "P1: " << p1 << "\t\tP2: " << p2 << endl;


}

void task3()
{

    cout << endl << "Task 3";

    string line;

    ofstream in_file;
    in_file.open("test.txt");
    in_file << "Test file";
    in_file.close();

    ifstream o_file;
    o_file.open("test.txt");

    while (getline(o_file, line))
    {
        cout << line;
    }
}

void task4()
{
    cout << endl << "Task 4" << endl;
    string num = "";

    string line;

    ofstream in_file;
    in_file.open("test_4.txt");
    in_file << "jkhsgfw34r353bfbsfdhb whgwfb4t 4tt4hjkgs 4t4jt2 t4jt";
    in_file.close();

    ifstream o_file;
    o_file.open("test_4.txt");

    char digits[11] = "0123456789";

    while (getline(o_file, line))
    {
        for (auto c : line)
        {
            if (isdigit(c)) { num += c; }
            else
            {
                if (num.length() > 0) { cout << num << endl; }
                num = "";
            }
        }
    }
}


void sortedStr(string &s)
{
    sort(s.begin(), s.end());
}


string sortStr(string s)
{
    char temp;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[j] < s[i])
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    return s;
}

void task5()
{
    cout << endl;

    string s1 = "gfdjhgsjgjgjgjgjrfgewadfazfop";
    string s2 = "hadakgrhdfjkgsgfdgvxcbchdtqde";
    string sortedS2;

    sortedStr(s1);  // using <algorithm>
    cout << "Sorted s1: " << s1 << endl;

    sortedS2 = sortStr(s2);  // using BubbleSort
    cout << "Sorted s2: " << sortedS2 << endl;
}


int main()
{

    task1();

    task2();

    task3();

    task4();

    task5();

    return 0;
}


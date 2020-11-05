

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

    float S, n, m, r;
    float a1, a2, p1, p2;

    cout << endl << "Task 2";
    cout << endl << "Enter S, m, n: ";
    cin >> S >> m >> n;

    float ans = -1;

    float ansDelta = FLT_MAX;
    float currDelta;

    for (float p = 0; p < 101; p++)
    {
        r = p / 100;
        currDelta = abs(m - (S * r * pow((1 + r), n)) / (12 * (pow((1 + r), n) - 1)));

        if (currDelta < ansDelta)
        {
            ansDelta = currDelta;
            ans = p;
        }
    }

    if (ans == -1)
    {
        cout << "Error" << endl;
    }
    else
    {
        cout << "Ans: " << ans << endl;
    }

    //a1 = (S + 12 * m + sqrt((S + 12 * m) * (S + 12 * m) - 4 * 12 * m * S)) / (2 * S);
    //a2 = (S + 12 * m - sqrt((S + 12 * m) * (S + 12 * m) - 4 * 12 * m * S)) / (2 * S);

    //p1 = (pow(a1, 1 / n) - 1) * 100;
    //p2 = (pow(a2, 1 / n) - 1) * 100;

    //cout << "P1: " << p1 << "\t\tP2: " << p2 << endl;
}

void task3()
{

    cout << endl << "Task 3" << endl;

    string line;

    string inputStr;

    cout << "Enter string: ";
    cin.ignore(cin.rdbuf()->in_avail());  // https://cppstudy.wordpress.com/2009/03/27/cin-get-and-co/
    getline(cin, inputStr);
    cin.clear();

    ofstream in_file;
    in_file.open("test.txt");
    in_file << inputStr;
    in_file.close();

    ifstream o_file;
    o_file.open("test.txt");

    while (getline(o_file, line))
    {
        cout << line;
    }

    cout << endl;
}

void task4()
{
    cout << endl << "Task 4" << endl;
    string num = "";

    string line;
    string inputStr;

    cout << "Enter string: ";
    cin.ignore(cin.rdbuf()->in_avail());  // https://cppstudy.wordpress.com/2009/03/27/cin-get-and-co/
    getline(cin, inputStr);
    cin.clear();

    ofstream in_file;
    in_file.open("test_4.txt");
    in_file << inputStr + " ";
    in_file.close();

    ifstream o_file;
    o_file.open("test_4.txt");

    char digits[11] = "0123456789";

    while (getline(o_file, line))
    {
        for (auto c : line)
        {
            if (isdigit(c))
            {
                num += c;
            }
            else
            {
                if (num.length() > 0)
                {
                    cout << num << endl;
                }
                num = "";
            }
        }
    }
}


void sortedStr(string& s)
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
    string s2;
    //string s2 = "hadakgrhdfjkgsgfdgvxcbchdtqde";

    cout << "Enter string: ";
    cin.ignore(cin.rdbuf()->in_avail());  // https://cppstudy.wordpress.com/2009/03/27/cin-get-and-co/
    getline(cin, s2);
    cin.clear();

    string sortedS2;

    //sortedStr(s1);  // using <algorithm>
    //cout << "Sorted s1: " << s1 << endl;

    sortedS2 = sortStr(s2);  // using BubbleSort
    cout << "Sorted s2: " << sortedS2 << endl;
}


// array of pointers to void functions with no params
void (*funcPtrs[])() = { task1, task2, task3, task4, task5 };


int main()
{

    cout << endl << "Homework - 3" << endl;

    while (true)
    {
        int taskNum;

        cout << "Which task do you want to check (1-5, 0 to quit) ?: ";
        cin >> taskNum;

        if (taskNum == 0) break;

        try
        {
            (*funcPtrs[taskNum - 1])();
        }
        catch (...)
        {
            break;
        }

        cout << endl;
    }

    return 0;
}


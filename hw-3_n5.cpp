

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


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
    task5();


    return 0;
}

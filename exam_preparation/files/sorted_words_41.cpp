

#include <iostream>

#include <vector>

#include <algorithm>

#include <string>
using namespace std;


vector<string> splitString(string s)
{
    vector<string> words;

    string word = "";
    s += " ";

    for (auto c : s)
    {
        if (c != ' ')
        {
            word += c;
        }
        else
        {
            words.push_back(word);
            word = "";
        }
    }

    return words;
}


bool compareLength(const string& i, const string& j)
{
    return i.size() < j.size();
}

void sortByLength(vector<string>& words)
{
    sort(words.begin(), words.end(), compareLength);
}


void printWords(const vector<string>& words)
{
    for (auto word : words) { cout << word << endl; }
}


int main()
{
    string S = "";
    int n;
    vector<string> words;

    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cout << "Enter word: ";
        string word;
        cin >> word;
        S += word + " ";
    }

    S.resize(S.size() - 1);

    words = splitString(S);

    sortByLength(words);

    cout << endl << endl;
    cout << "Sorted words (by length):" << endl;
    printWords(words);

    return 0;
}

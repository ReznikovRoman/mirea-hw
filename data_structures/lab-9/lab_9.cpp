#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct StringPair
{
    string s1;
    string s2;
    int similarity;
};

vector<string> splitString(string str)
{
    string word = "";
    vector<string> words;

    for (auto x : str)
    {
        if (x == ' ')
        {
            words.push_back(word);
            word = "";
        }
        else
        {
            word = word + x;
        }
    }

    words.push_back(word);
    return words;
}

void compareStrings(StringPair &sp)
{
    int size;
    int maxSequence = 0;
    if (sp.s1.size() > sp.s2.size())
        size = sp.s2.size();
    else
        size = sp.s1.size();

    for (int i = 0; i < size - 1; i++)
    {
        int currSequence = 0;
        if (sp.s1[i] == sp.s2[i])
        {
            maxSequence += 1;
            if (currSequence > maxSequence)
            {
                maxSequence = currSequence;
            }
        }
        else
        {
            currSequence = 0;
        }
    }

    sp.similarity = maxSequence;
}

void task1()
{
    int maxSimilarity = 0;
    StringPair mostSimilarPair = {"No similar strings", "No similar strings", 0};
    string input, s;
    vector<string> words;
    getline(cin, input); // mother father dog frog

    // remove all commas from string
    input.erase(remove(input.begin(), input.end(), ','), input.end());

    // remove all redundant spaces
    unique_copy(input.begin(), input.end(), back_insert_iterator<string>(s),
                [](char a, char b)
                { return isspace(a) && isspace(b); });

    // split string by spaces
    words = splitString(s);

    for (int i = 0; i < words.size() - 1; i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            // find similarities in strings
            StringPair sp = {words[i], words[j], 0};
            compareStrings(sp);

            // find pair with the maximum similarity
            if (sp.similarity > maxSimilarity)
            {
                maxSimilarity = sp.similarity;
                mostSimilarPair = sp;
            }
        }
        cout << endl;
    }

    // mother father (`ther` > `og`)
    cout << "Most similar: " << mostSimilarPair.s1 << " " << mostSimilarPair.s2 << endl;
}

int main(void)
{

    task1();

    return 0;
}



#include <iostream>

#include <fstream>
#include <string>

#include <algorithm>

#include <vector>

using namespace std;


void task1()
{
    string line, text;

    ofstream in_file;
    in_file.open("file_1.txt");
    in_file << "dada fdsf  fsfs fw\ngfdsgs gwgw   ewgw    wfwf wf wfw\n gfwgfw fwfw   rqr";
    in_file.close();

    ifstream out_file;
    out_file.open("file_1.txt");

    while (getline(out_file, line))
    {
        text += line + '\n';
    }

    replace(text.begin(), text.end(), ' ', '_');

    out_file.close();

    ofstream in_file2;
    in_file2.open("file_1.txt");
    in_file2 << text;
    in_file2.close();


    cout << "\n\tText has been edited - new separator has been added." << endl;
}


bool isNull(int x) { return x == 0; }


void task19()
{

    string alph = "abcdefghijklmnopqrstuvwxyz";

    vector<int> counter(alph.size());
    
   
    string line, text;

    // write text to the file
    ofstream in_file;
    in_file.open("file_1.txt");
    in_file << "DADA fdsf  fsfs fw\ngfdsgs Gwgw   ewgW    wfwf wf wfw\n gfwgfw fwfw   rqr";
    in_file.close();

    // get text from the file
    ifstream out_file;
    out_file.open("file_1.txt");
    while (getline(out_file, line))
    {
        text += line;
    }
    out_file.close();

    // Convert to lowercase
    for (char& el : text) { el = tolower(el); }

    // counter
    for (char el : text)
    {
        if (el > 96 && el < 123) { counter[alph.find(el)] += 1; }
    }

    // get statistics
    cout << endl;
    for (int i = 0; i < counter.size(); ++i)
    {
        cout << '\t' << alph[i] << " : " << counter[i] << endl;
    }

    // get the most frequent letter
    int maxElInd = max_element(counter.begin(), counter.end()) - counter.begin();
    cout << endl << "The most frequent letter: " << alph[maxElInd];

    // get the least frequent letter
    int minElInd = min_element(counter.begin(), counter.end()) - counter.begin();
    cout << endl << "The least frequent letter: " << alph[minElInd];


    cout << endl << endl;
}


// text files
int main()
{
    //task1();
    
    task19();
    


    return 0;
}

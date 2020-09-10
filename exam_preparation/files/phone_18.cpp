

#include <iostream>


#include <map>
#include <vector>
#include <fstream>

#include <string>
using namespace std;


int main()
{
    string line;
    string userName;

    cout << "Enter name: ";
    cin >> userName;

    ofstream in_file;
    in_file.open("phone18.txt");
    in_file << "Reznikov" << " 123" << "\n";
    in_file << "Ivanov" << " 456" << "\n";
    in_file << "Petrov" << " 789" << "\n";
    in_file << "Ivanov" << " 042" << "\n";
    in_file.close();

    ifstream out_file;
    out_file.open("phone18.txt");

    while (getline(out_file, line))
    {   
        size_t found = line.find(userName);
        if (found != string::npos) { cout << line << endl; }
    }

    return 0;
}

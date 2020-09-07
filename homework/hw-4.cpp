

#include <iostream>

#include <fstream>
#include <string>;

using namespace std;


void task1()
{

    cout << endl << "Task - 1" << endl;

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

void task2()
{

}

void task3()
{

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

void task8()
{

}

void task9()
{

}


// hw-4
int main()
{

    task1();

    //task2();

    //task3();

    //task4();

    //task5();

    //task6();

    //task7();

    //task8();

    //task9();

    return 0;
}

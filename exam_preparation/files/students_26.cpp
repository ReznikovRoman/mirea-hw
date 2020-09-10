

#include <iostream>


#include <map>
#include <vector>
#include <fstream>

#include <string>
using namespace std;

class Student
{
private:
    int id;
    string firstName, lastName;
    map<string, int> grades;
    float avgGrade = -1;

public:
    Student(int a_id, string a_fName, string a_lName, map<string, int> a_grades)
    {
        id = a_id;
        firstName = a_fName;
        lastName = a_lName;
        grades = a_grades;
    }
    
    int getId() { return id; }

    string getFirstName() { return firstName; }

    string getLastName() { return lastName; }

    string getFullName() { return firstName + " " + lastName; }

    map<string, int> getGrades() { return grades; }

    float getAverageGrade()
    {
        float sum = 0;
        for (auto grade : grades)
        {
            sum += grade.second;
        }

        avgGrade = sum / grades.size();

        return avgGrade;
    }

    void print()
    {
        cout << "ID: " << id << "; Full name: " << getFullName() << endl;
        cout << "Grades: " << endl;
        for (auto grade : grades)
        {
            cout << grade.first << " : " << grade.second;
            cout << endl;
        }
        cout << endl;
    }

};


int main()
{
    cout << endl;

    string line;
    int n;
    
    ofstream in_file;
    //in_file.open("students_26.txt");

    vector<string> subjects = { "Math", "Programming", "Informatics" };
    vector<Student> students;
    

    cout << "Enter Students amount: ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; ++i)
    {
        int id;
        string firstName, lastName;
        map<string, int> grades;

        cout << "Enter Student ID, First Name and Last Name: ";
        cin >> id >> firstName >> lastName;

        for (auto subject : subjects)
        {
            cout << "Enter Student's grade in " << subject << ": ";
            cin >> grades[subject];
        }
        cout << endl;

        Student newStudent(id, firstName, lastName, grades);
        students.push_back(newStudent);

        newStudent.print();
    }



    return 0;
}

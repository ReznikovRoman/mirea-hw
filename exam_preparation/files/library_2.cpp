

#include <iostream>

#include <map>
#include <string>
#include <vector>

#include <fstream>

using namespace std;


void printBook(const map<string, string> &book)
{
    for (auto it : book)
    {
        cout << it.first
            << ":"
            << it.second
            << endl;
    }

    cout << endl;
}

pair<string, string> findBookByTitle(const vector<map<string, string>> &books, const string &title)
{

    for (map<string, string> book : books)
    {
        if (book["Title"] == title) { return make_pair(book["Author"], book["Year"]); }
    }

    return make_pair("Error", "There is no book with this title");
}


int main()
{
    int books_count;
    string a_name, b_title, year;

    vector<map<string, string>> books;
    map<string, string> book;

    string user_title;
    pair<string, string> bookInfo;


    // User Input
    cout << endl << "Task - 2" << endl << "Library" << endl;

    cout << endl << "Enter Books Amount: ";
    cin >> books_count;

    ofstream in_file;
    in_file.open("books_2.txt");

    for (int i = 0; i < books_count; ++i)
    {
        in_file << "\nBook #" << i + 1 << "\n";

        cout << endl << "Enter Author Name: ";
        // https://stackoverflow.com/questions/21373234/using-two-getlinecin-s-in-c
        cin.ignore(cin.rdbuf()->in_avail());  // https://cppstudy.wordpress.com/2009/03/27/cin-get-and-co/
        getline(cin, a_name);
        cin.clear();
        in_file << "Author: " << a_name << "\n";

        cout << "Enter Book Title: ";
        cin.ignore(cin.rdbuf()->in_avail());
        getline(cin, b_title);
        cin.clear();
        in_file << "title: " << b_title << "\n";

        cout << "Enter Year of Publication: ";
        cin >> year;
        cout << endl;
        in_file << "Year of Publication: " << year << "\n";

        book["Author"] = a_name;
        book["Title"] = b_title;
        book["Year"] = year;

        books.push_back(book);
        book.clear();
    }

    in_file.close();


    /*
    for (auto book : books)
    {
        printBook(book);
    }
    */


    // Find Book by Title
    cout << endl << "Find book by a title";
    cout << endl << "Enter Book title: ";
    cin.ignore(cin.rdbuf()->in_avail());
    getline(cin, user_title);
    cin.clear();

    bookInfo = findBookByTitle(books, user_title);

    cout << endl;

    if (bookInfo.first == "Error") { cout << "There is no book with title " << user_title << endl; }
    else { cout << "Author: " << bookInfo.first << "\t\tYear of Publication: " << bookInfo.second << endl; }

    return 0;
}

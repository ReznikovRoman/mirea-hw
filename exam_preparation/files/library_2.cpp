

#include <iostream>

#include <map>
#include <string>
#include <vector>

#include <fstream>


void printBook(std::map<std::string, std::string> book)
{
    for (auto it : book)
    {
        std::cout << it.first
                  << ":"
                  << it.second
                  << std::endl;
    }

    std::cout << std::endl;
}

std::pair<std::string, std::string> findBookByTitle(std::vector<std::map<std::string, std::string>> books, std::string title)
{

    for (std::map<std::string, std::string> book : books)
    {
        if (book["Title"] == title) { return std::make_pair(book["Author"], book["Title"]); }
    }

    return std::make_pair("Error", "There is no book with this title");
}


int main()
{
    int books_count;
    std::string a_name, b_title, year;

    std::vector<std::map<std::string, std::string>> books;
    std::map<std::string, std::string> book;

    std::string user_title;
    std::pair<std::string, std::string> bookInfo;


    // User Input
    std::cout << std::endl << "Task - 2" << std::endl << "Library" << std::endl;

    std::cout << std::endl << "Enter Books Amount: ";
    std::cin >> books_count;

    std::ofstream in_file;
    in_file.open("books_2.txt");

    for (int i = 0; i < books_count; ++i)
    {
        in_file << "\nBook #" << i + 1 << "\n";

        std::cout << std::endl << "Enter Author Name: ";
        // https://stackoverflow.com/questions/21373234/using-two-getlinecin-s-in-c
        std::cin.ignore(std::cin.rdbuf()->in_avail());  // https://cppstudy.wordpress.com/2009/03/27/cin-get-and-co/
        std::getline(std::cin, a_name);
        std::cin.clear();
        in_file << "Author: " << a_name << "\n";

        std::cout << "Enter Book Title: ";
        std::cin.ignore(std::cin.rdbuf()->in_avail());
        std::getline(std::cin, b_title);
        std::cin.clear();
        in_file << "title: " << b_title << "\n";

        std::cout << "Enter Year of Publication: ";
        std::cin >> year;
        std::cout << std::endl;
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

    std::cout << std::endl << "Find book by a title";
    std::cout << std::endl << "Enter Book title: ";
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::getline(std::cin, user_title);
    std::cin.clear();

    bookInfo = findBookByTitle(books, user_title);

    std::cout << std::endl;

    if (bookInfo.first == "Error") { std::cout << "There is no book with title " << user_title << std::endl; }
    else { std::cout << "Author: " << bookInfo.first << "\t\tYear of Publication: " << bookInfo.second << std::endl; }

    return 0;
}

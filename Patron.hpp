

#ifndef PATRON_HPP
#define PATRON_HPP

#include <string>
#include <vector>

class Book;  // forward declaration

class Patron
{
private:
    std::string idNum;
    std::string name;
    std::vector<Book*> checkedOutBooks;
    double fineAmount;
public:
    Patron();
    Patron(std::string idn, std::string n);
    void setIdNum(std::string);
    std::string getIdNum();
    void setName(std::string);
    std::string getName();
    std::vector<Book*> getCheckedOutBooks();
    void addBook(Book* b);
    void removeBook(Book* b);
    double getFineAmount();
    void amendFine(double amount);
};

#endif

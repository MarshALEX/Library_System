/**************************************************
 * **Author: Alexandria Marsh
 * **Date: March 11, 2015
 * **Description: This is the implementation file for
 * 	the Patron class.
 ***********************************************/
#include "Book.hpp"
#include "Patron.hpp"
#include <iostream> 
#include <vector>

//default constructor
Patron::Patron()
{
 setIdNum("  ");
 setName("   ");

}	 

//overloaded constructor
Patron::Patron(std::string idn, std::string n)
{
 setIdNum(idn);
 setName(n);
 amendFine(0);
}

void Patron::setIdNum(std::string idn)
{
 idNum = idn;
}

std::string Patron::getIdNum()
{
  return idNum;
}

void Patron::setName(std::string n)
{
 name = n;
}

std::string Patron::getName()
{
 return name;
}

std::vector<Book*> Patron::getCheckedOutBooks()
{
 return checkedOutBooks;
}

void Patron::addBook(Book* b)
{
 checkedOutBooks.push_back(b);
}

void Patron::removeBook(Book* b)
{


 for(int x=0; x< checkedOutBooks.size(); x++)
 {
    if(b->getIdCode() == checkedOutBooks[x]->getIdCode())
	{
	  std::cout<<"Title: "<<checkedOutBooks[x]->getTitle()<<std::endl;
	  std::cout<<"ID Code: "<<checkedOutBooks[x]->getIdCode()
	     <<std::endl;
	  checkedOutBooks.erase(checkedOutBooks.begin(), checkedOutBooks.begin()+1);

	}
 }

}

double Patron::getFineAmount()
{
  return fineAmount;
}

void Patron::amendFine(double amount)
{
  fineAmount = fineAmount + amount;
}


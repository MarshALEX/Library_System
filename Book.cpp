/*************************************
 * **Author: Alexandria Marsh
 * **Date: March 11, 2015
 * **Description: This file is the implemenation
 * 	file for the Book class. 
 **********************************/

#include "Book.hpp"
#include "Patron.hpp"
#include <iostream>
#include <vector>
//default constructor
Book::Book()
{
 setIdCode(" ");
 setTitle("   ");
 setAuthor("  ");

}

//overloaded constructor
Book::Book(std::string idc, std::string t, std::string a)
{
 setIdCode(idc);
 setTitle(t);
 setAuthor(a);
 checkedOutBy = NULL;
 requestedBy = NULL;
 location = ON_SHELF; 
} 	

void Book::setIdCode(std::string idc) 
{
  idCode = idc;
}
std::string Book::getIdCode()
{
	return idCode;
}

void Book::setTitle(std::string t)
{
  title = t;
}

std::string Book::getTitle()
{
  return title;
}

void Book::setAuthor(std::string a )
{
  author = a;
}

std::string Book::getAuthor()
{
 return author;
}

void Book::setLocation(Locale lo)
{
  location = lo;
}

Locale Book::getLocation()
{
  return location;
}

Patron* Book::getCheckedOutBy()
{
 return checkedOutBy; 
}

void Book::setCheckedOutBy(Patron* p)
{
 Patron* checkedOutBy = p; 
}

Patron* Book::getRequestedBy()
{
  return requestedBy;
}

void Book::setRequestedBy(Patron* p)
{
 Patron* requestedBy = p;
}

int Book::getDateCheckedOut()
{
 return dateCheckedOut;
}

void Book::setDateCheckedOut(int d)
{
 dateCheckedOut = d;
}

/*******************************************
 * **Author:Alex Marsh
 * **Date:March 11, 2015
 * **Description:This is the implementation 
 * 	file for the library class. 
 ***************************************/
#include "Book.hpp"
#include "Patron.hpp"
#include "Library.hpp"
#include <iostream>
#include <string>
#include<algorithm>
#include<vector>
//constructor
Library::Library()
{
 currentDate = 0;
// holdings.reserve(100);
// members.reserve(100); 
}
 
/**************************
 * 	addBook
 * Description: This function adds
 *      a new book to the library
 * Parameters: No parameters and no 
 * 	return, but a new book in input
 **************************/ 	    	
void Library::addBook()
{
  std::string xT;
  std::string A;
  std::string I;

  std::cout<<"Please enter the book's title: "<<std::endl;
  std::cin.ignore(); 
  std::getline(std::cin, xT);

  std::cout<<"Please enter the book's author: "<<std::endl;
  std::getline(std::cin, A); 	

  std::cout<<"Please enter the book's ID Code: "<<std::endl;
  std::getline(std::cin, I);

  if(holdings.empty())
  { 
	 Book newBook(I, xT, A);
	 holdings.push_back(newBook);
  } 
  
  else
  { 
   bool flag = true;
   for(int i=0; i < holdings.size(); i++)
   {
	
	if(holdings[i].getIdCode() == I)
	{
	 std::cout<<"That ID already exists."<<std::endl;
	 flag = false;
	}
   }
   if(flag == true)
   {
   
    Book newBook(I, xT, A);
    holdings.push_back(newBook);
   } 
 }
 
  
} 

/********************************
 * 	addMember
 * Description: This function adds
 * 	a new member to the patron
 * 	list,
 * Parameters: No parameters and no
 * 	return, but a new parton in input
 * ******************************/
void Library::addMember()
{
  std::string N;
  std::string I;

  std::cout<<"Please enter the person's name: "<<std::endl;
  std::cin.ignore();
  std::getline(std::cin, N);

  std::cout<<"Please enter the ID number: "<<std::endl;
  std::getline(std::cin, I); 	

  if(members.empty())
  { 
	 Patron newPatron(I, N);
	 members.push_back(newPatron);
  } 
  else
  {
   bool flag2 = true;
   for(int x=0; x < members.size(); x++)
   {
  
    if(members[x].getIdNum() == I)
     {
	std::cout<<"That ID already exists."<<std::endl;
        std::cout<<members[x].getIdNum()<<std::endl;
        flag2 = false; 
     }
    }
   if( flag2 == true)
     {	
        Patron newPatron(I, N);
        members.push_back(newPatron);
     }
   }
 
}
/*************************************
 * 		checkOutBook
 * **Description:This function checks out a book
 * 	to a specified patron.
 * **Paramaters:the function takes the parameters
 * 	of a specified string for the patron ID and
 * 	bookID. This function doesn't return any values		
*****************************************/
void Library::checkOutBook(std::string patronID, std::string bookID)
{
  bool flagC = false; 
  bool flagB = false;
  int location; 
 for(int j=0; j < members.size(); j++)
   {
     if(members[j].getIdNum() == patronID) 
      { 
       flagC = true;
      }
   }
  if(flagC == false)
   {
	std::cout<<"That patron doesn't exist"<<std::endl;
   }

  for(int k=0; k< holdings.size(); k++)
   {
    
    if(holdings[k].getIdCode() == bookID)
	{
	  flagB = true;
  	  location = holdings[k].getLocation();
        }
   }
  if(flagB == false)
   {
	std::cout<<"That book doesn't exist"<<std::endl;
   }
  if((flagC == true) && (flagB == true))
  { 

  if(location == 2)
    {
	std::cout<<"The book is already checked out."<<std::endl;
        flagC = false;
    }
  else if(location == 1)
    {  
	std::cout<<"Sorry, The book is on hold."<<std::endl; 
        flagC = false;
    }
  else if(location == 0)
    {
     bool flag2 = false;	
     std::cout<<bookID<<std::endl;
     for(int i=0; i<holdings.size(); i++)
     { for(int x=0; x< members.size(); x++){
	  if(holdings[i].getIdCode() == bookID && members[x].getIdNum() == patronID)
	  {
 	   flag2 = true;
	  
	   holdings[i].setCheckedOutBy(&members[x]);//update CheckedOutBy
	   holdings[i].setDateCheckedOut(currentDate);
	   holdings[i].setLocation(CHECKED_OUT);
	   std::cout<<"The book "<<holdings[i].getTitle() 
	            <<" was checked out by "<<members[x].getName()<<std::endl;
	
	  }
 	  }	  
         }
      
    
  }
}

}
/****************************************
 *        returnBook
 ***Description: This function returns
	a book a parton has checkedout        
**Parameters:this function takes a parameter
	of a string for the bookID that is
	specified by the user.
*************************************/ 

void Library::returnBook(std::string bookID)
{
  bool flagW = false;

  for(int i=0; i<holdings.size(); i++)
  {
    if(holdings[i].getIdCode() == bookID && holdings[i].getLocation() ==2)
    {
	holdings[i].setLocation(ON_SHELF);
	holdings[i].getCheckedOutBy()->removeBook(&(holdings[i]));
	std::cout<<"The book "<<holdings[i].getTitle()<<"has been returned."
	   <<std::endl;
	flagW = true;

    } 
   if(holdings[i].getIdCode() == bookID && holdings[i].getLocation()==0)
    {
	std::cout<<"This book isn't checked out. It's on the shelf."<<std::endl;    }   
    
   if(holdings[i].getIdCode() == bookID && holdings[i].getLocation()==1)
    {
	std::cout<<"This book isn't checked out. It's on the hold shelf."
	<<std::endl; 
     }   
  }  
 
  if(flagW == false)
   { 
	std::cout<<"That book doesn't exist in the Library."<<std::endl;
   }	
		
}
/************************************************
 * 		requestBook
 * Description:This function allows a patron to request a 
 * 	book and thus put the book on the hold shelf if it is
 * 	not already checked out or on hold.
 * Paramters: This funciton takes in a string of the patron and book
 *      id and returns no values.
 ******************************************/      	 		
void Library::requestBook(std::string patronID, std::string bookID)
{

  bool flagW = false;
  bool flagZ = false;
  for(int i=0; i<holdings.size(); i++)
  {
    for(int x=0; x<members.size(); x++)
    { 	
     if(holdings[i].getIdCode() == bookID)
 	{
	   flagW = true;	
	}
     if(members[x].getIdNum() == patronID)
	{
	   flagZ = true;
	}
    }
  }

  if(flagW == false)
   {
	std::cout<<"That book doesn't exist."<<std::endl;
   }
  if(flagZ == false)
   {
	std::cout<<"That patron doesn't exist."<<std::endl;
   }
  if(flagW == true && flagZ == true)
   { 	 
		 
  for(int i=0; i<holdings.size(); i++)
  {
    for(int x=0; x<members.size(); x++)
    { 	
     if(holdings[i].getIdCode() == bookID && members[x].getIdNum() == patronID)
     {
	if((holdings[i].getLocation() ==2)||(holdings[i].getLocation()==0))
        { 
	holdings[i].setLocation(ON_HOLD_SHELF);
	holdings[i].setRequestedBy(&members[x]);	
	std::cout<<"The book "<<holdings[i].getTitle()
	         <<"has been put on hold for"<<members[x].getName()<<std::endl;
	   
	flagW = true;
        }
     } 
   if(holdings[i].getIdCode() == bookID && holdings[i].getLocation()==2)
    {
	std::cout<<"This book is already checked out to this patron."<<std::endl;       
    }
   if(holdings[i].getIdCode() == bookID && holdings[i].getLocation()==1)
    {
	std::cout<<"This is already on hold."<<std::endl;
    }  
  } 
 } 
}
}


/****************************
 * 	   incrementCurrentDate
 * **Description: This function increases
 * 	the day by one and prints the date
 * **Parameters: This function has no 
 * 	parameters and returns no values.
 ********************************/
void Library::incrementCurrentDate()
{
  currentDate += 1;
  std::cout<<"The Date is now: "<<currentDate<<std::endl;
  std::vector <Book*> pBooks; 
  for(int i=0; i <members.size(); i++)
  {
    pBooks = members[i].getCheckedOutBooks();
    for(int r=0; r<pBooks.size(); r++)
    {	
	if(currentDate - pBooks[r]->getDateCheckedOut()>21)
	   { members[i].amendFine(.10);}		
    } 


  }
  	 
}
/****************************************
 * **		payFine
 * **Description:: this function allows a 
 * 	user to pay a amount of fines.
 * **Parameters: Thus function takes in a 
 * 	string of the patron and book ID.
 * 	This function doesn't return any value
 *******************************************/ 		
void Library::payFine(std::string patronID, double payment)
{
  bool flagC = false; 

 for(int j=0; j < members.size(); j++)
   {
     if(members[j].getIdNum() == patronID) 
      { 
       flagC = true;
      }
   }
  if(flagC == false)
   {
	std::cout<<"That patron doesn't exist"<<std::endl;
   }

  if(flagC == true) 
   {
     for(int j=0; j < members.size(); j++)
      {
        if(members[j].getIdNum() == patronID) 
        { 
	  members[j].amendFine(-1 * payment);
          std::cout<<"The patron "<<members[j].getName()<<" now has "<<
		    members[j].getFineAmount()<<" fine amount. "<<std::endl;	
	}
      }
   }
}
/********************************
 * 	   viewPatronInfo 
 ***Description: this function shows the
      infomation of a specific patron. It
	prints the patrons: name, ID, fines and 
	titles they have checked out

**Parameters: This function has the parameters
	of a stron of the partonID and returns
	no value 	    
*********************************/
void Library::viewPatronInfo(std::string patronID)
{
 bool flag = true;
 for(int j=0; j < members.size(); j++)
 {
   if(members[j].getIdNum() == patronID) 
    { 
       std::cout<<"Name : "<<members[j].getName()<<std::endl;
       std::cout<<"ID   : "<<members[j].getIdNum()<<std::endl;
       std::cout<<"Fine Amount: "<<members[j].getFineAmount()<<std::endl;
       std::cout<<"Books Checked Out: "<<std::endl;

	std::vector<Book*> pBooks;
	pBooks = members[j].getCheckedOutBooks();
	for(int y=0; y < pBooks.size(); y++)
	{
	  std::cout<<"IN HERE NOW!"<<std::endl;
	  std::cout<<pBooks[y]->getTitle()<<std::endl;
	}	   
       flag = false;
     }
 }
 if(flag == true)
 {
   std::cout<<"There is no Patron with that ID in the Library."<<std::endl;  
 } 
 
}
/**********************************************
 * 		viewBook
 * Description: This function shows the information of a 
 * 	specific book. It prints the books title and id
 * 	and location.
 * Parameters: This function takes the parameters
 * 	of a specified book ID and returns no valeus
 *************************************************/ 				
void Library::viewBookInfo(std::string bookID)
{
  bool flagA = true;
 
  std::cout<<"The Book ID is"<<bookID<<std::endl;
  for(int i = 0; i < holdings.size(); i++)
  {
    if(holdings[i].getIdCode() == bookID)
    {
  	flagA = false;
	std::cout<<"ID code: "<<holdings[i].Book::getIdCode()<<std::endl;
	std::cout<<"Title: "<<holdings[i].Book::getTitle()<<std::endl;
	std::cout<<"Author: "<<holdings[i].Book::getAuthor()<<std::endl;
	std::cout<<"Location: ";

	int location = holdings[i].Book::getLocation();
	 if(location == 0)
	 {
	   std::cout<<"The book is on the shelf."<<std::endl;
 	  }
	 else if(location == 1)
	 {  
	   std::cout<<"The book is on hold."<<std::endl; 
	 }  
	 else if(location == 2)
	 {
	   std::cout<<"The book is checked out."<<std::endl;
 	  }
    }


  }
  if(flagA == true)
  {
    std::cout<<"There is not a book with that ID in the Library."<<std::endl;
  }		

}
/***********************************************
 * 		printBook
 * Description: this function prints all of the 
 * 	books in the library with the title, author,
 * 	ID code, and location.
 * Parameters: This function takes in no parameters
 * 	and returns no values		 		
**************************************************/
void Library::printBooks()
{

  for (int i=0; i < holdings.size(); i++)
    {
	std::cout<<"ID code: "<<holdings[i].Book::getIdCode()<<std::endl;
	std::cout<<"Title: "<<holdings[i].Book::getTitle()<<std::endl;
	std::cout<<"Author: "<<holdings[i].Book::getAuthor()<<std::endl;
	std::cout<<"Location: ";
	int location = holdings[i].Book::getLocation();
	 if(location == 0)
	 {
	   std::cout<<"The book is on the shelf."<<std::endl;
 	  }
	 else if(location == 1)
	 {  
	   std::cout<<"The book is on hold."<<std::endl; 
	 }  
	 else if(location == 2)
	 {
	   std::cout<<"The book is checked out."<<std::endl;
 	  }
 }
}	
/*********************************************
 * **		  printPatrons
 * **description: this function prints all of the 
 * 	patrons in library with their name and ID
 * **Parametres: the function takes in no parameters
 * 	and returns no values
 * **********************************************/		 
void Library::printPatrons()
{
 for (int x=0; x<members.size(); x++)
  {
	std::cout<<"Name: "<<members[x].Patron::getName()<<std::endl;
	std::cout<<"ID Num: "<<members[x].Patron::getIdNum()<<std::endl; 

  } 

}		

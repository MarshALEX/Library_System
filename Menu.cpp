/******************************************
 * **Authro:Alexandri Marsh
 * **Date: March 11, 2015
 * **Description: This program contains the 
 *   	main menu presented to the user.
 ******************************************/
#include "Book.hpp"
#include "Patron.hpp"
#include "Library.hpp"
#include<iostream>
#include<string>
#include<vector>
int main(){

   
  Library test; //Library object
  int choice;
  
   do{
	std::cout<<"*************************************"<<std::endl;
	std::cout<<"Hello! Welcome to the Library Menu!"<<std::endl;
	std::cout<<"   "<<std::endl;
	std::cout<<"1.) Add a Book to the Library. "<<std::endl;
	std::cout<<"2.) Add a Member to the Library. "<<std::endl;
	std::cout<<"3.) Check Out a Book. "<<std::endl;
	std::cout<<"4.) Return a Book. "<<std::endl;
	std::cout<<"5.) Request a Book. "<<std::endl;
	std::cout<<"6.) Increment the Current Date. "<<std::endl;
	std::cout<<"7.) Pay your fine. "<<std::endl;
	std::cout<<"8.) View Patron Information. "<<std::endl;
	std::cout<<"9.) View Book Information. "<<std::endl;
 	std::cout<<"10.) Print All Books."<<std::endl;	
	std::cout<<"11.) Print All Patrons."<<std::endl;
	std::cout<<"12.) Quit. "<<std::endl;
	std::cout<<"*************************************"<<std::endl;
	std::cout<<"Please enter your choice: "<<std::endl; 
	std::cin >> choice; 	
      

   if(choice == 1)
	{ 
	  std::cout<<"Choice 1! ADD BOOK"<<std::endl; 
	 test.addBook(); 
	}

   if(choice == 2)
	{ 
	  std::cout<<"Choice 2! ADD MEMBER"<<std::endl; 
	  test.addMember();
	}

   if(choice == 3)
	{ 
	  std::string IdInput, naInput;
 	
	  std::cout<<"Choice 3! CHECK OUT BOOK "<<std::endl; 
	  std::cout<<"Please enter your Patron ID: "<<std::endl;
	  std::cin.ignore();
	  std::getline(std::cin, IdInput);

	  std::cout<<"Please enter the book's ID: "<<std::endl;
	  std::getline(std::cin, naInput);
	  
	  test.checkOutBook(IdInput, naInput); 
	}

   if(choice == 4)
	{ 
	  std::string inputID;
	  std::cout<<"Choice 4! RETURN A BOOK"<<std::endl; 
	  std::cout<<"Please enter book's ID: "<<std::endl;
	  std::cin.ignore();
	  std::getline(std::cin, inputID);
	  test.returnBook(inputID);
	}

   if(choice == 5)
	{ 
	  std::cout<<"Choice 5! REQUEST A BOOK "<<std::endl; 
	  std::string inputBID;
	  std::string inputPID;
	  std::cout<<"Please enter patron ID: "<<std::endl;
	  std::cin.ignore();
	  std::getline(std::cin, inputPID);
	  std::cout<<"Please enter book's ID: "<<std::endl;
	  std::getline(std::cin, inputBID);
	  test.requestBook(inputPID, inputBID);
        }  
   if(choice == 6)
	{ 
	  std::cout<<"Choice 6! INCREMENT DAY "<<std::endl; 
	  test.incrementCurrentDate();
	}

   if(choice == 7)
	{ 
	  double inputP;
	  std::string inputID;
	  std::cout<<"Choice 7! PAY FINES"<<std::endl; 
	  std::cout<<"Please enter your Patron ID: "<<std::endl;
	  std::cin.ignore();
	  std::getline(std::cin, inputID);
	  std::cout<<"Please enter the fine\n"
		   <<"you would like to pay."<<std::endl;
	  std::cin>> inputP;
	  test.payFine(inputID, inputP);
	}

   if(choice == 8)
	{ 
	  std::string inputID;
	  std::cout<<"Choice 8! VIEW PATRON INFO"<<std::endl; 
	  std::cout<<"Please enter the Patron's ID: "<<std::endl;
	  std::cin.ignore();
	  std::getline(std::cin, inputID);
	  test.viewPatronInfo(inputID);
        }
   
   if(choice == 9)
	{ 
	  std::string input;
	  std::cout<<"Choice 9! VIEW BOOK INFO"<<std::endl; 
	  std::cout<<"Please enter the books ID: "<<std::endl;
	  std::cin.ignore();
	  std::getline(std::cin, input);
	  test.viewBookInfo(input);
	}

   if(choice == 10)
	{
	  std::cout<<"Choice 10! PRINT ALL THE BOOKS!"<<std::endl;
	  test.printBooks();
	}

   if(choice == 11)
	{
	   std::cout<<"Choice 11! PRINT ALL PATONS!"<<std::endl;
	   test.printPatrons();
	} 
  }while(choice != 12);

return 0;
}   	

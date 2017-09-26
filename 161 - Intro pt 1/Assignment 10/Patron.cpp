/************************************************************************
 * Author: Riley Brandau
 * Date: 3/10/16
 * Description: This is the definition file for the class called Patron.
************************************************************************/

#include "Patron.hpp"
#include "Book.hpp"
#include <string>
#include <vector>




/***************************
 *******CONSTRUCTOR*********
***************************/

Patron::Patron(std::string idn, std::string n)
{
   idNum = idn;
   name = n;
   fineAmount = 0.0;
}


/*************************
 *******GET METHODS*******
*************************/

std::string Patron::getIdNum()
{
   return idNum;
}

std::string Patron::getName()
{
   return name;
}

std::vector<Book*> Patron::getCheckedOutBooks()
{
   return checkedOutBooks;
}

double Patron::getFineAmount()
{
   return fineAmount;
}


/************************
 ******SET METHODS*******
************************/

void Patron::addBook(Book* b)
{
   checkedOutBooks.push_back(b);
}

void Patron::removeBook(Book* b)
{
   checkedOutBooks.erase(checkedOutBooks.begin()); //this is correct syntax, but need to determine which book to erase...
}

void Patron::amendFine(double f)
{
   fineAmount += f;
}


/**********************************************************************
 * Author: Riley Brandau
 * Date: 3/10/16
 * Description: This is the definition file for the class called Book
**********************************************************************/

#include "Book.hpp"
#include <string>

class Patron;

/******************************
 ********CONSTRUCTOR***********
******************************/

Book::Book(std::string idc, std::string t, std::string a)
{
   idCode = idc;
   title = t;
   author = a;
   setCheckedOutBy(NULL);
   setRequestedBy(NULL);
   setLocation(ON_SHELF);
}

/*****************************
 *********GET METHODS*********
*****************************/

int Book::getCheckOutLength()
{
   return CHECK_OUT_LENGTH;
}

std::string Book::getIdCode()
{
   return idCode;
}

std::string Book::getTitle()
{
   return title;
}

std::string Book::getAuthor()
{
   return author;
}

Locale Book::getLocation()
{
   return location;
}

Patron* Book::getCheckedOutBy()
{
   return checkedOutBy;
}

Patron* Book::getRequestedBy()
{
   return requestedBy;
}

int Book::getDateCheckedOut()
{
   return dateCheckedOut;
}

/****************************
 ********SET METHODS*********
****************************/

void Book::setLocation(Locale loc)
{
   location = loc;
}

void Book::setCheckedOutBy(Patron* pat)
{
   checkedOutBy = pat;
}

void Book::setRequestedBy(Patron* pat)
{
   requestedBy = pat;
}

void Book::setDateCheckedOut(int d)
{
   dateCheckedOut = d;
}


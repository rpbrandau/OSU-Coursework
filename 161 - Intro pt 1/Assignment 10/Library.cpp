/*********************************************************************************
 * Author: Riley Brandau
 * Date: 3/10/16
 * Description: This is the definition file for the class called Library.
********************************************************************************/

#include <string>
#include <vector>
#include "Book.hpp" //not sure if needed
#include "Patron.hpp"
#include "Library.hpp"


/**************************
 *******CONSTRUCTOR********
**************************/

Library::Library() //might need more in here? not missing initializing vectors or something?
{
   currentDate = 0;
}


/************************
 *******GET METHODS******
************************/

Patron* Library::getPatron(std::string pID)
{
   for(int i = 0; i <= members.size(); i++)
     {
	if(pID == members.at(i)->getIdNum())
	  {
	     Patron* pPointer;
	     pPointer = members.at(i);
	     return pPointer;
	  }
	else
	  {
	     return NULL;
	  }     
     }
}


Book* Library::getBook(std::string bID)
{
   for(int i = 0; i <= holdings.size(); i++)
     {
	if(bID == holdings.at(i)->getIdCode())
	  {
	    Book* bPointer;
	    bPointer = holdings.at(i); 
	    return bPointer;
	  }
	else
	  {
	     return NULL;
          }
     }
}

/*****************************
 *****CONDITIONAL METHODS*****
*****************************/

std::string Library::checkOutBook(std::string pID, std::string bID)
{
   for(int i = 0; i <= members.size(); i++)
     {
	if(pID != members.at(i)->getIdNum())
	  {
	     return "Patron not found";
	  }
	else
	  {
	     for(int i2 = 0; i2 <= holdings.size(); i++)
	       {
		 if(bID != holdings.at(i2)->getIdCode())
		   {
		     return "Book not found";
		   }
		else if(bID == holdings.at(i2)->getIdCode())
		   {
		     if(holdings.at(i2)->getLocation() == CHECKED_OUT)
		       {
			 return "Book already checked out";
		       }
		     else if(holdings.at(i2)->getLocation() == ON_HOLD_SHELF)
		       {
			 return "Book on hold by other patron";
		       }
		     else
		       {
			 checkedOutBooks.checkedOutBy(pID);
			 checkedOutBooks.addBook(bID);
			 Book.setDateCheckedOut(0);
			 Book.setLocation(CHECKED_OUT);

			 if(pID == holdings.at(i2)->getRequestedBy())
			   {
			     holdings.at(i2)->setRequestedBy(NULL);
			   }
			 return "Check out successful";
			}
		   }
	       }
          }
     }
}

std::string Library::returnBook(std::string bID)
{
   for(int i = 0; i <= holdings.size(); i++)
     {
        if(bID == holdings.at(i)->getIdCode()) //i think these vectors might need to be replaced with Book.getIdCode(holdings.length(i)) ?
	  {
	    if(holdings.at(i)->getLocation() == CHECKED_OUT)
	      {
		checkedOutBooks.removeBook(bID);
		holdings.at(i)->setCheckedOutBy(NULL);
		
		if(holdings.at(i)->getRequestedBy() != NULL)
		  {
		    holdings.at(i)->setLocation(ON_HOLD_SHELF);
		  }
		else
		  {
		    holdings.at(i)->setLocation(ON_SHELF);
		  }
		return "Return successful";
	      }
	   else if(holdings.at(i)->getLocation() == ON_SHELF || holdings.at(i)->getLocation() == ON_HOLD_SHELF)
	      {
		return "Book already in library";
	      }
	  }
	else
	  {
	    return "Book not found";
	  }
     }
}

std::string Library::requestBook(std::string pID, std::string bID)
{
   for(int i = 0; i <= holdings.size(); i++)
     {
       if(bID == holdings.at(i)->getIdCode())
	{
	  for(int i2 = 0; i2 <= members.size(); i2++)
	    {
	      if(pID == members.at(i2)->getIdNum())
	        {
		  if(holdings.at(i)->getLocation() == ON_HOLD_SHELF)
		   {
		     return "Book already on hold";
		   }
		  else
		   {
		     holdings.at(i)->requestedBy(pID);
		     if(holdings.at(i)->getLocation() == ON_SHELF)
		      {
			holdings.at(i)->setLocation(ON_HOLD_SHELF);
			return "Request successful";
		      }
		   }
		}
	      else
		{
		  return "Patron not found";
		}
	    }
	 else
	   {
	     return "Book not found";
	   }
	}
     }

}

std::string Library::payFine(std::string pID, double payment)
{
   for(int i = 0; i <= members.size(); i++)
     {
       if(pID != members.at(i)->getIdNum)
	{
	  return "Patron not found";
	}
       else
	{
	  double paid = payment*-1;
	  amendFine(paid);
	  return "Payment successful";
	}
     }
}

void Library::incrementCurrentDate()
{
   currentDate += currentDate;

   for(int i = 0; i <= members.size(); i++)
     {
       for(int i2 = 0; i2 <= holdings.size(); i++)
	 {
	   if(currentDate >= 22)
	    {
	      int dif = currentDate - CHECK_OUT_LENGTH;
	      fineAmount = dif*0.1;
	      amendFine(fineAmount);
	    }
         }
      }
}

/**************************
 ******OTHER METHODS*******
**************************/

void Library::addBook(Book* b)
{
   holdings.push_back(b);
}

void Library::addPatron(Patron* p)
{
   members.push_back(p);
}


//Be careful - a Book can be on request without its location being the hold shelf.

#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
#include <vector>
#include "Patron.hpp"

class Library
{
private:
    std::vector<Book*> holdings;        //a vector of pointers to Books in the Library
    std::vector<Patron*> members;    //a vector of pointers to Patrons in the Library
    int currentDate;                              //stores the current date represented as an integer number of "days" since the Library object was created
public:
    Library();                                      //constructor. Initializes the currentDate to zero
    void addBook(Book*);                   //adds the parameter to holdings vector
    void addPatron(Patron*);              //adds the parameter to members vector
   
    std::string checkOutBook(std::string pID, std::string bID);     
		//if the specified Book is not in the Library, return "book not found"
		//if the specified Patron is not in the Library, return "patron not found"
		//if the specified Book is already checked out, return "book already checked out"
		//if the specified Book is on hold by another Patron, return "book on hold by other patron"
		//Otherwise, update the Book's checkedOutBy, dateCheckedOut, and Location.
			//If the Book was on hold for this Patron, update requestedBy
				//update the Patron's checkedOutBooks
				//return "check out successful"
				
    std::string returnBook(std::string bID);
		//if the specified Book is not in the Library, return "book not found"
		//if the Book is not checked out, return "book already in library"
		//update the Patron's checkedOutBooks
			//update the Book's location depending on whether another Patron has requested iter_swap
			//update the Book's checkedOutBy
			//return "return successful"
			
    std::string requestBook(std::string pID, std::string bID);
		//if the specified Book is not in the Library, return "book not found"
		//if the specified Patron is not in the Library, return "patron not found"
		//if the specified Book is already requested, return "book already on hold"
		//Update the Book's requestedBy
			//if the Book is on the shelf, return its location to on hold
			//return "request successful"
		
    std::string payFine(std::string pID, double payment);
		//takes as a parameter the amount that is being paid (not the negative of that amount)
		//if the specified Patron is not in the Library, return "patron not found"
		//use amendFine to update the Patron's fine. Return "payment successful"
		
    void incrementCurrentDate();
		//increment current date. Increase each patron's fines by 10 cents for each overdue Book they have checked out (using amendFine)
		//If a book is checked out on day 0, then on day 1, the patron has had it for 1 day. On day 21, the patron has had it for 21 days, so it is still not overdue.
		//on day 22, the book is overdue and fines will be charged.
		
    Patron* getPatron(std::string pID);  //returns a pointer to the Patron corresponding to the ID parameter, or NULL if no such Patron is a member
    Book* getBook(std::string bID);   //returns a pointer to the Book corresponding to the ID parameter, or NULL if no such Patron is a member
};

#endif
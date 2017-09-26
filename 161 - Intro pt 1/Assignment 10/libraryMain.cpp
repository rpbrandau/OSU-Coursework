/*****************************
 * Main Method for Library class
 *****************************/

#include "Library.hpp"
#include <iostream>

int main()
{

	//create some books
Book b1("123", "Jurassic Park", "Crichton");
Book b2("234", "The Stand", "King");
Book b3("345", "The Name of the Wind", "Rothfuss");

	//create some patrons
Patron p1("abc", "Paul");
Patron p2("def", "Wanda");

	//Create the library
Library lib;

	//add books to library
lib.addBook(&b1);
lib.addBook(&b2);
lib.addBook(&b3);

	//add patrons to library
lib.addPatron(&p1);
lib.addPatron(&p2);

	//check out a book
lib.checkOutBook("abc", "123"); //Patron Paul trying to check out Jurassic Park
   for(int i = 0; i < 7; i++)
	lib.incrementCurrentDate();

lib.checkOutBook("def", "234"); //Patron Wanda trying to check out The Stand

lib.checkOutBook("abc", "345"); //Patron Paul trying to check out The name of the wind
   for(int i = 0; i <24; i++)
	lib.incrementCurrentDate(); //guessing it'll add +2 days of fines to this book, and +8 days to other book. so... a dollar worth of fines?

lib.payFine("def", 0.4);

double p1Fine = p1.getFineAmount();
double p2Fine = p2.getFineAmount();

std::cout << "Patron 1's fine:$ " << p1Fine << std::endl;
std::cout << "Patron 2's fine:$ " << p2Fine << std::endl;

return 0;
}

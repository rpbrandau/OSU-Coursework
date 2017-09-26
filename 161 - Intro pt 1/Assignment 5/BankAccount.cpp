/***
 * Author: Riley Brandau
 * Date: 2/3/16
 * Description: This file contains the definitions for the function prototypes declared in BankAccount.hpp
***/

#include "BankAccount.hpp" // uses the BankAccount class header file that we created

BankAccount::BankAccount(string name, string id, double bal) //constructor
{
	customerName = name;
	customerID = id;
	customerBalance = bal;
}
//get functions that return their variable value
string BankAccount::getCustomerName()
{
	return customerName;
}

string BankAccount::getCustomerID()
{
	return customerID;
}

double BankAccount::getCustomerBalance()
{
	return customerBalance;
}
//functions that manipulate the customerBalance variable by either adding or subtracting from it
void BankAccount::withdraw(double w)
{
	withdrawAmount = w;
	customerBalance -= withdrawAmount;
}

void BankAccount::deposit(double d)
{
	depositAmount = d;
	customerBalance += depositAmount;
}


/***
 * Author: Riley Brandau
 * Date: 2/3/16
 * Description: This is the header file for a class called BankAccount
***/

#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP
#include <string>
#include <iostream>

using namespace std;

class BankAccount
{
	private: //declaring private variables
		string customerName;
		string customerID;
		double customerBalance;
		double withdrawAmount;
		double depositAmount;

	public://declaring public function prototypes
		BankAccount(string, string, double);//three parameter constructor
		string getCustomerName();
		string getCustomerID();
		double getCustomerBalance();
		void withdraw(double);
		void deposit(double);
};
#endif 

/***
 * Author: Riley Brandau
 * Date: 2/3/16
 * Description: a main method for testing BankAccount.cpp
***/

#include <iostream>
#include <string>
#include "BankAccount.hpp"
using namespace std;

int main()
{

	string name;
	string id;
	double balance;
	double deposit;
	double withdrawl;
//	BankAccount account(name, id, balance);

	cout << "Please enter your name\n";
	getline(cin, name);
	cout << "Please enter your ID\n";
	getline(cin, id);
	cout << "Please enter your balance\n";
	cin >> balance;

	BankAccount account(name, id, balance);

	cout << "Displaying your information\n";
	cout << "Name: " << account.getCustomerName() << endl;
	cout << "ID: " << account.getCustomerID() << endl;
	cout << "Balance: $" << account.getCustomerBalance() << endl;

	cout << "Please enter how much you would like to withdraw" << endl;
	cin >> withdrawl;
	account.withdraw(withdrawl);
	cout << "Your new balance is: $" << account.getCustomerBalance() << endl;

	cout << "Please enter how much you would like to deposit" << endl;
	cin >> deposit;
	account.deposit(deposit);
	cout << "Your new balance is: $" << account.getCustomerBalance() << endl;

return 0;
}


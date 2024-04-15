#include <iostream>
#include "Bank.h"


int main()
{
    Bank myBank;
	myBank.createAccount();
	myBank.createAccount();
	for (size_t i = 0; i < 14; i++)
	{
		myBank.createAccount();
	}
	myBank.createAccount();
	myBank.deleteAccount(6);
	myBank.changeBalanceOfAccount(0, 400);
	myBank.changeBalanceOfAccount(0, -50);
	myBank.transferMoney(0, 16, 200);
	myBank.printAccounts();
}

#include "Bank.h"

Bank::~Bank() {
	free();
}

void Bank::free() {
	delete[] accounts;
}

void Bank::resize() {
	maxNumberOfAccounts += 16;
	Account* temp = new Account[maxNumberOfAccounts];
	for (size_t i = 0; i < numberOfAccounts; i++)
	{
		temp[i] = accounts[i];
	}
	//Delete the old array
	delete[] accounts;
	//Change the pointer "accounts" to point to temp
	accounts = temp;
}

void Bank::createAccount() {
	if (numberOfAccounts == 0)
	{
		accounts = new Account[maxNumberOfAccounts];
	}
	if (numberOfAccounts == maxNumberOfAccounts)
	{
		resize();
	}
	Account newAccount(numberOfAccounts);
	accounts[numberOfAccounts] = newAccount;
	++numberOfAccounts;
}

void Bank::deleteAccount(const int id) {
	if (id <= numberOfAccounts)
	{
		accounts[id] = accounts[numberOfAccounts - 1];
		--numberOfAccounts;
	}
	else
	{
		std::cout << "No such id exists in the bank!" << std::endl;
	}
}

void Bank::printAccounts() const {
	for (size_t i = 0; i < numberOfAccounts; i++)
	{
		std::cout << accounts[i].getId() << " " << accounts[i].getAmountOfMoney() << " " << accounts[i].getIsBlocked() << std::endl;
	}
}

int Bank::findAccount(const int id) {
	// We must iterate trough all of the accounts, because deleteion shuffles their positions
	for (size_t i = 0; i < numberOfAccounts; i++)
	{
		if (accounts[i].getId() == id)
		{
			return i;
		}
	}
	return -1;
}

//A single method used both for adding and withdrawing money in an account
void Bank::changeBalanceOfAccount(const int id, const int amount) {
	int accId = findAccount(id);
	if (accId != -1)
	{
		accounts[accId].changeBalance(amount);
	}
}

void Bank::blockAccount(const int id) {
	if (id <= numberOfAccounts)
	{
		int accId = findAccount(id);
		if (accId != -1)
		{
			accounts[accId].block();
		}
		else
		{
			std::cout << "No such id exists in the bank!" << std::endl;
		}
	}
	else
	{
		std::cout << "No such id exists in the bank!" << std::endl;
	}
}

void Bank::transferMoney(const int senderId, const int recieverId, const int amount) {
	if (amount < 0)
	{
		std::cout << "You can't transfer a negative amount of money between accounts!" << std::endl;
	}
	int sender = findAccount(senderId);
	int reciever = findAccount(recieverId);
	accounts[sender].changeBalance(-1 * amount);
	accounts[reciever].changeBalance(amount);
}
#pragma once
#include "Account.h"

class Bank {
private:
	Account* accounts = nullptr;
	int numberOfAccounts = 0;
	int maxNumberOfAccounts = 16;
	void resize();
	void free();
	int findAccount(const int id);
public:
	Bank() = default;
	~Bank();

	void createAccount();
	void blockAccount(const int id);
	void deleteAccount(const int id);
	void changeBalanceOfAccount(const int id, const int amount);
	void transferMoney(const int senderId, const int recieverId, const int amount);
	void printAccounts() const;
};
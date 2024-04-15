#include "Account.h"

Account::Account(const int id) {
	setId(id);
}

void Account::setId(const int id) {
	this->id = id;
}

void Account::changeBalance(const int amount) {
	if (amountOfMoney + amount < 0)
	{
		std::cout << "Not enough funds in the bank account!" << std::endl;
	}
	else
	{
		amountOfMoney += amount;
	}
}

int Account::getAmountOfMoney() const {
	return amountOfMoney;
}

int Account::getId() const {
	return id;
}

bool Account::getIsBlocked() const {
	return isBlocked;
}

void Account::block() {
	isBlocked = true;
}
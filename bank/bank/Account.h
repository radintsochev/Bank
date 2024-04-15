#pragma once
#include <iostream>

class Account {
private:
	int id = 0;
	int amountOfMoney = 0;
	bool isBlocked = false;
public:
	Account() = default;
	Account(const int id);
	void setId(const int id);
	int getAmountOfMoney() const;
	int getId() const;
	bool getIsBlocked() const;
	void block();
	void changeBalance(const int amount);
};
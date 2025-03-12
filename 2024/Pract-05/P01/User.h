#pragma once
#include <iostream>
#include "GlobalConstants.h"

class User
{
private:
	size_t userId = 0;
	char name[GlobalConstants::USER_NAME_MAX]{};
	double balance = 0;
public:
	User() = default;
	User(size_t userId, char* name, double balance);

	void setUserId(size_t userId);
	void setName(char* name);
	void setBalance(double balance);

	size_t getUserId();
	char* getName();
	double getBalance();
};

//Конструктор по подразбиране(слагат се default стойности на член - данните като id = 0).
//Конструктор с параметри.
//void updateMoney(double amount); -Добавя amount към парите.Парите не могат да бъдат отрицателни
//bool hasMoney(double amount); -Връща дали потребителя има достатъчно пари.
//size_t getID - Връща индекса на потребителя
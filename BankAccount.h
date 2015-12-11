#pragma once
#include "Bank.h"

#include <string>
#include <vector>
#include <random>

class Bank;					// Predefine (error fix)

class BankAccount
{
private:
	long long kontonumber_;
	std::vector<std::string> transactions;				// Save all transactions from this account
	std::string username_;
	std::string surname_;
	std::string birthday_;
	short age_;
	std::string isbn_;
	std::string bic_;
	int money_;
	int pin_;
	Bank* registredbank_;							// Reference to the bank we are registred

public:
	BankAccount(const std::string&, const std::string&, const std::string, short, Bank*);
	void setIsbn();
	void setPin();
	const std::string getUsername();
	const std::string getSurname();
	const std::string getBirthday();
	const short getAge();
	const long long getKontonummer();
	const std::string getIsbn();
	const std::string getBic();
};

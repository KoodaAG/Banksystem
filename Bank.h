#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "BankAccount.h"
#include <iostream>
class BankAccount;					// Predefine (error fix)

class Bank
{
private:
	void addAccount(const std::string&, const std::string&, const std::string&, short);
	bool accountExist(const std::string&, const std::string&, const std::string&, short);
protected:
	std::string bic_;
	int usercounter_;
	std::string bankname_;
	std::string countryAbbrv_;		// Country abbreviation
	std::vector<BankAccount> Users;
public:
	Bank(const std::string&, const std::string&, const std::string&);
	~Bank();
	const std::string getBankname();
	const std::string getCountryAbbrv();
	const int getuserCounter();
	bool registerAccount(const std::string&, const std::string&, const std::string&, short);
	void readAccountData();
	void writeAccountData();
	const std::string getBic();
};

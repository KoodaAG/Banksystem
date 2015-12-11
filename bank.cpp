#include "Bank.h"

Bank::Bank(const std::string &bankname, const std::string&bic, const std::string &countryAbbrv)
{
	bic_ = bic;
	bankname_ = bankname;
	Users.push_back(BankAccount("Root", "Admin", "00.00.0000", 0, this));
	readAccountData();
	std::cout << "Created " << bankname << "\tBic:" << bic << "\tLandcode:" << countryAbbrv << std::endl;
}

const std::string Bank::getBic() { return bic_; }
const std::string Bank::getBankname() { return bankname_; }
const std::string Bank::getCountryAbbrv() { return countryAbbrv_; }
const int Bank::getuserCounter() { return usercounter_; }

void Bank::readAccountData()
{
	std::ifstream data(bankname_ + ".txt");
	if (!data.read(reinterpret_cast<char*>(this), sizeof(Bank)))
		std::cout << "Couldn't read account informations out of file<" << bankname_ + ".txt>" << std::endl;
	data.close();
}

void Bank::writeAccountData()
{
	std::ofstream data(bankname_ + ".txt");
	if (!data.write(reinterpret_cast<char*>(this), sizeof(Bank)))
		std::cout << "Couldn't write account informations in file<" << bankname_ + ".txt>" << std::endl;
	data.close();
}

Bank::~Bank()
{
	writeAccountData();
}

void Bank::addAccount(const std::string& username, const std::string& surname, const std::string& birthday, short age) { Users.push_back(BankAccount(username, surname, birthday, age, this)); }
bool Bank::accountExist(const std::string& username, const std::string& surname, const std::string& birthday, short age)
{
	for (auto usr : Users)
		if (usr.getUsername() == username && usr.getSurname() == surname && usr.getBirthday() == birthday && usr.getAge() == age)
			return true;
	return false;
}

bool Bank::registerAccount(const std::string& username, const std::string& surname, const std::string& birthday, short age)
{
	if (accountExist(username, surname, birthday, age))
		return false;
	addAccount(username, surname, birthday, age);
}


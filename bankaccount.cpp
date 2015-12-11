#include "BankAccount.h"

BankAccount::BankAccount(const std::string& username, const std::string& surname, const std::string birthday, short age, Bank* registredbank)
{
	username_      = username;
	registredbank_ = registredbank;
	age_           = age;
	surname_       = surname;
	birthday_      = birthday;
	setPin();
	setIsbn();
}


void BankAccount::setIsbn()
{
	isbn_ = registredbank_->getCountryAbbrv();
	isbn_ += kontonumber_;
	isbn_ += bic_;
	isbn_ += registredbank_->getuserCounter();
}

void BankAccount::setPin()
{
	std::default_random_engine generate;
	std::uniform_int_distribution<int> randomRange(1000, 9999);
	pin_ = randomRange(generate);
}

const std::string BankAccount::getUsername() { return username_; }
const std::string BankAccount::getSurname() { return surname_; }
const std::string BankAccount::getBirthday() { return birthday_; }
const short BankAccount::getAge() { return age_; }
const long long BankAccount::getKontonummer() { return kontonumber_; }
const std::string BankAccount::getIsbn() { return isbn_; }
const std::string BankAccount::getBic() { return registredbank_->getBic(); }

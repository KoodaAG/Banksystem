#pragma once
#include "Bank.h"
#include <iostream>

class TrivagoBank : public Bank
{
public:
	TrivagoBank(const std::string&, const std::string&, const std::string&);
	~TrivagoBank();
};

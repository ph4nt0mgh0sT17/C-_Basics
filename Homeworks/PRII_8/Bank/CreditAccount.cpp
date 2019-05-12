#include "CreditAccount.h"


CreditAccount::CreditAccount(int number, Client* owner, double credit) : Account(number, owner)
{
	std::cout << "CreditAccount constructor" << std::endl;
	this->credit = credit;
}

CreditAccount::CreditAccount(int number, Client* owner, double interestRate, double credit) : Account(number, owner, interestRate)
{
	std::cout << "CreditAccount constructor" << std::endl;
	this->credit = credit;
}

CreditAccount::~CreditAccount()
{
	std::cout << "CreditAccount destructor" << std::endl;
}

bool CreditAccount::CanWithdraw(double amount)
{
	return (this->GetBalance() + this->credit >= amount);
}

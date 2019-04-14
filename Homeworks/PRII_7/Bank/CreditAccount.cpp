#include "CreditAccount.h"


CreditAccount::CreditAccount(int number, Client* owner, double credit) : Account(number, owner)
{
	this->credit = credit;
}

CreditAccount::CreditAccount(int number, Client* owner, double interestRate, double credit) : Account(number, owner, interestRate)
{
	this->credit = credit;
}

bool CreditAccount::CanWithdraw(double amount)
{
	return (this->GetBalance() + this->credit >= amount);
}

bool CreditAccount::Withdraw(double amount)
{
	bool success = false;

	if (this->CanWithdraw(amount))
	{
		this->balance -= amount;
		success = true;
	}

	return success;
}



#include "Account.h"



Account::Account(int number, Client* client)
{
	std::cout << "Account constructor" << std::endl;
	this->balance = 0;
	this->number = number;
	this->owner = client;
	this->interestRate = 0;
}

Account::Account(int number, Client* client, double interestRate)
{
	std::cout << "Account constructor" << std::endl;
	this->balance = 0;
	this->number = number;
	this->owner = client;
	this->interestRate = interestRate;
}

Account::~Account()
{
	std::cout << "Account destructor" << std::endl;
}

int Account::GetNumber()
{
	return this->number;
}

double Account::GetBalance()
{
	return this->balance;
}

double Account::GetInterestRate()
{
	return this->interestRate;
}

Client* Account::GetOwner()
{
	return this->owner;
}

bool Account::CanWithdraw(double amount)
{
	return (amount > this->balance);
}

void Account::Deposit(double amount)
{
	this->balance += amount;
}

bool Account::Withdraw(double amount)
{
	if (this->CanWithdraw(amount))
	{
		this->balance -= amount;
		return true;
	}

	return false;
}

void Account::AddInterest()
{
	this->balance += (int)(balance * this->interestRate);
}
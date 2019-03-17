#include "Account.h"



Account::Account(int number, Client* client)
{
	this->number = number;
	this->owner = client;
	this->partner = nullptr;
	this->interestRate = 0;
}

Account::Account(int number, Client* client, double interestRate)
{
	this->number = number;
	this->owner = client;
	this->partner = nullptr;
	this->interestRate = interestRate;
}

Account::Account(int number, Client* client, Client* partner)
{
	this->number = number;
	this->owner = client;
	this->partner = partner;
	this->interestRate = 0;
}

Account::Account(int number, Client* client, Client* partner, double interestRate)
{
	this->number = number;
	this->owner = client;
	this->partner = partner;
	this->interestRate = interestRate;
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

Client* Account::GetPartner()
{
	return this->partner;
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


#pragma once
#include "Account.h"
#include "Client.h"

class CreditAccount : public Account
{
private:
	double credit;

public:
	CreditAccount(int number, Client* owner, double credit);
	CreditAccount(int number, Client* owner, double interestRate, double credit);
	virtual ~CreditAccount();

	bool CanWithdraw(double amount);
};
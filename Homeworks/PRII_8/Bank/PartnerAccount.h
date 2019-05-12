
#pragma once

#include "Account.h"

class PartnerAccount : public Account
{
private:
	Client* partner;

public:
	PartnerAccount(int number, Client* owner, Client* partner);
	PartnerAccount(int number, Client* owner, Client* partner, double interestRate);

	Client* GetPartner();
};

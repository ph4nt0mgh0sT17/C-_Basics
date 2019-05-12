
#include "PartnerAccount.h"



PartnerAccount::PartnerAccount(int number, Client* owner, Client* partner) : Account(number, owner)
{
	this->partner = partner;
}

PartnerAccount::PartnerAccount(int number, Client* owner, Client* partner, double interestRate) : Account(number, owner, interestRate)
{
	this->partner = partner;
}

Client* PartnerAccount::GetPartner()
{
	return this->partner;
}
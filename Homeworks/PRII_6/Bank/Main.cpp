#include <iostream>
#include <string>

#include "Bank.h"


/// <summary>
/// Const string variable of the name of the application
/// </summary>
const std::string NAME_APP = "Welcome to my new bank application.";


std::string GetReport(Account* account, Client* client)
{
	std::string report = "";

	report += "Client " + std::to_string(client->GetObjectsCount()) + ": " + client->GetName() + "; His account has these statistics: Balance: " + std::to_string((int)account->GetBalance()) + "; Interest rate: " + std::to_string(account->GetInterestRate());

	return report;

}


int main(void)
{
	Account* account;
	PartnerAccount* partnerAccount;

	Bank* bank = new Bank(100, 100);

	Client* owner = bank->CreateClient(0, "Miko");
	Client* partner = bank->CreateClient(1, "Osmancik");

	account = bank->CreateAccount(0, owner);
	partnerAccount = bank->CreateAccount(1, owner, partner);

	std::cout << account->GetOwner()->GetName() << std::endl;
	std::cout << partnerAccount->GetPartner()->GetName() << std::endl;




	getchar();

	return (0);
}

#include <iostream>
#include <string>

#include "Bank.h"
#include "Client.h"
#include "Account.h"
#include "CreditAccount.h"


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
	Client* owner = new Client(0, "Miko");

	CreditAccount* creditAccount = new CreditAccount(1, owner, 1000);

	std::cout << creditAccount->CanWithdraw(1000) << std::endl;

	std::cout << "********************************" << std::endl;

	Account* account = creditAccount;

	std::cout << account->CanWithdraw(1000) << std::endl;
	std::cout << creditAccount->Withdraw(1000) << std::endl;



	getchar();

	return (0);
}

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
	std::cout << NAME_APP << std::endl;

	Bank* airbank = new Bank(15, 15);

	Client* client = airbank->CreateClient(15, "Davidek");

	Account* account = airbank->CreateAccount(1547, client, 3);

	std::cout << GetReport(account, client) << std::endl;

	Client* client1 = airbank->CreateClient(15, "Davidek");

	Account* account1 = airbank->CreateAccount(1547, client1, 3);

	std::cout << GetReport(account1, client1) << std::endl;

	Client* client2 = airbank->CreateClient(15, "Davidek");

	Account* account2 = airbank->CreateAccount(1547, client2, 3);

	std::cout << GetReport(account2, client2) << std::endl;


	getchar();

	return (0);
}

#pragma once

#include "Account.h"
#include "PartnerAccount.h"

class Bank
{
private:

	/// <summary>
	/// List of clients in the bank
	/// </summary>
	Client** clients;
	int clientsCount;

	/// <summary>
	/// List of accounts in the bank
	/// </summary>
	Account** accounts;
	int accountsCount;

public:

	/// <summary>
	/// Initializes current bank with given parameters
	/// </summary>
	/// <param name="clientsCount">The number of clients in the bank</param>
	/// <param name="accountsCount">The number of accounts in the bank</param>
	Bank(int clientsCount, int accountsCount);

	~Bank();

	/// <summary>
	/// Gets client due to given parameter
	/// </summary>
	/// <param name="code">Identificator of the client</param>
	/// <returns>Client with given code</returns>
	Client* GetClient(int code);

	/// <summary>
	/// Gets account due to given parameter
	/// </summary>
	/// <param name="number">Identificator of the account</param>
	/// <returns>Account with given number</returns>
	Account* GetAccount(int number);

	/// <summary>
	/// Creates client with given parameters
	/// </summary>
	/// <param name="code">Code of the client</param>
	/// <param name="name">Name of the client</param>
	/// <returns>New client</returns>
	Client* CreateClient(int code, std::string name);

	/// <summary>
	/// Creates account with given parameters
	/// </summary>
	/// <param name="number">Number of the account</param>
	/// <param name="client">Client that owns the account</param>
	/// <returns>New account</returns>
	Account* CreateAccount(int number, Client* client);

	/// <summary>
	/// Creates account with given parameters
	/// </summary>
	/// <param name="number">Number of the account</param>
	/// <param name="client">Client that owns the account</param>
	/// <param name="interestRate">Interest rate of the account</param>
	/// <returns>New account</returns>
	Account* CreateAccount(int number, Client* client, double interestRate);

	PartnerAccount* CreateAccount(int number, Client* owner, Client* partner);
	PartnerAccount* CreateAccount(int number, Client* owner, Client* partner, double interestRate);




	/// <summary>
	/// Adds interest to all accounts of the bank
	/// </summary>
	void AddInterest();
};


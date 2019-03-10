#include "Bank.h"



Bank::Bank(int clientsCount, int accountsCount)
{
	this->clients = new Client*[clientsCount];
	this->accounts = new Account*[accountsCount];

	this->accountsCount = 0;
	this->clientsCount = 0;
}


Bank::~Bank()
{
	for (int i = 0; i < this->clientsCount; i++)
	{
		delete this->clients[i];
		this->clients[i] = nullptr;
	}

	delete[] this->clients;
	this->clients = nullptr;

	for (int i = 0; i < this->accountsCount; i++)
	{
		delete this->accounts[i];
		this->accounts[i] = nullptr;
	}

	delete[] this->accounts;
	this->accounts = nullptr;
}

Client* Bank::GetClient(int code)
{
	for (int i = 0; i < this->clientsCount; i++)
	{
		if (this->clients[i]->GetCode() == code)
		{
			return this->clients[i];
		}
	}

	return nullptr;
}

Account* Bank::GetAccount(int number)
{
	for (int i = 0; i < this->accountsCount; i++)
	{
		if (this->accounts[i]->GetNumber() == number)
		{
			return this->accounts[i];
		}
	}

	return nullptr;
}

Client* Bank::CreateClient(int code, std::string name)
{
	Client* newClient = new Client(code, name);

	this->clients[this->clientsCount] = newClient;
	this->clientsCount++;

	return newClient;
}

Account* Bank::CreateAccount(int number, Client* client)
{
	Account* newAccount = new Account(number, client);

	this->accounts[this->accountsCount] = newAccount;
	this->accountsCount++;

	return newAccount;
}

Account* Bank::CreateAccount(int number, Client* client, double interestRate)
{
	Account* newAccount = new Account(number, client, interestRate);

	this->accounts[this->accountsCount] = newAccount;
	this->accountsCount++;

	return newAccount;
}

Account* Bank::CreateAccount(int number, Client* client, Client* partner)
{
	Account* newAccount = new Account(number, client, partner);

	this->accounts[this->accountsCount] = newAccount;
	this->accountsCount++;

	return newAccount;
}

Account* Bank::CreateAccount(int number, Client* client, Client* partner, double interestRate)
{
	Account* newAccount = new Account(number, client, partner, interestRate);

	this->accounts[this->accountsCount] = newAccount;
	this->accountsCount++;

	return newAccount;
}


void Bank::AddInterest()
{
	for (int i = 0; i < this->accountsCount; i++)
	{
		this->accounts[i]->AddInterest();
	}
}

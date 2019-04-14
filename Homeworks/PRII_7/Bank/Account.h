#pragma once

#include "Client.h"

class Account
{
private:

	/// <summary>
	/// Current number of the account
	/// </summary>
	int number;

	/// <summary>
	/// Current interest rate
	/// </summary>
	double interestRate;

	/// <summary>
	/// Current owner
	/// </summary>
	Client* owner;

protected:
	/// <summary>
	/// Current balance of the account
	/// </summary>
	double balance;

public:

	/// <summary>
	/// Initializes account by given parameters
	/// </summary>
	/// <param name="number">Number of the account</param>
	/// <param name="client">Client that owns the account</param>
	Account(int number, Client* client);

	/// <summary>
	/// Initializes account by given parameters
	/// </summary>
	/// <param name="number">Number of the account</param>
	/// <param name="client">Client that owns the account</param>
	/// <param name="interestRate">Interest rate of the account</param>
	Account(int number, Client* client, double interstRate);

	/// <summary>
	/// Gets current number
	/// </summary>
	/// <returns>The number of the account</returns>
	int GetNumber();

	/// <summary>
	/// Gets current balance
	/// </summary>
	/// <returns>The balance of the account</returns>
	double GetBalance();

	/// <summary>
	/// Gets current interest rate
	/// </summary>
	/// <returns>The interest rate of the account</returns>
	double GetInterestRate();

	/// <summary>
	/// Gets current owner
	/// </summary>
	/// <returns>The owner of the account</returns>
	Client* GetOwner();

	/// <summary>
	/// Gets boolean variable if the current account can withdraw given amount
	/// </summary>
	/// <param name="amount">Amount of money</param>
	/// <returns>True or false</returns>
	bool CanWithdraw(double amount);

	/// <summary>
	/// Gives given amount to the current account's balance
	/// </summary>
	/// <param name="amount">Amount of money</param>
	void Deposit(double amount);

	/// <summary>
	/// Gets money from the balance and according the amount returns boolean 
	/// </summary>
	/// <param name="amount">Amount of money</param>
	/// <returns>True or false</returns>
	bool Withdraw(double amount);

	/// <summary>
	/// Adds interest rate to the balance
	/// </summary>
	void AddInterest();

};


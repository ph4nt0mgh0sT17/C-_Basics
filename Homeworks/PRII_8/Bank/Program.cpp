#include <iostream>

#include "Account.h"
#include "Client.h"
#include "CreditAccount.h"
#include "AbstractAccount.h"

using namespace std;

int main()
{
	Client* owner = new Client(0, "Smith");
	CreditAccount* creditAccount = new CreditAccount(1, owner, 1000);

	AbstractAccount* abstractAccount = creditAccount;

	delete abstractAccount;
	delete owner;

	getchar();
	return(0);
}

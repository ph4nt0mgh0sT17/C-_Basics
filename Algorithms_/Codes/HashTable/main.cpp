#include <iostream>
#include "HashTable.h"

int main(void)
{

	HashTable* hashTable = new HashTable();

	hashTable->Add("ABC");
	hashTable->Add("fer");
	hashTable->Add("gegw");
	hashTable->Add("ahoj_ty_byku");
	hashTable->Add("jsem_nejlepsi_lol");
	hashTable->Add("osman_kopiruje");
	hashTable->Add("chci_domu");

	hashTable->Print();

	getchar();

	return (0);
}

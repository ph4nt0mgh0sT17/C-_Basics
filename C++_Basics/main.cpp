#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>

using namespace std;

void printTitle(string title)
{
	for (unsigned int i = 0; i < title.length(); i++)
	{
		cout << title.at(i);
		Sleep(25);
	}
}

void printMenu(string menu)
{
	for (unsigned int i = 0; i < menu.length(); i++)
	{
		cout << menu.at(i);
		Sleep(25);
	}
}

const string nameApp = "\t\tRezervace mistnosti\n"
					"==========================================================\n\n";

const string menu = "Menu:\n"
					"\t1 - Vypsat vsechny mistnosti\n"
					"\t2 - Vypsat nezarezervovane mistnosti\n"
					"\t3 - Vypsani vsech mistnosti\n"
					"\t4 - Export nezarezervovane mistnosti do HTML\n"
					"\t5 - Ukoncit program\n";

int main(void)
{
	printTitle(nameApp);
	printMenu(menu);

#ifndef __PROGTEST__
	system("pause");
#endif /* __PROGTEST__ */

	return 0;
}
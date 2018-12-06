#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>

using namespace std;

#define OK 0
#define WRONG_DATA 1
#define IO_ERROR 2


void printTitle(string title);
void printMenu(string menu);
void chooseSelection(char choice);
int verifyInput();



const string nameApp = "\t\tRezervace mistnosti\n"
					"==========================================================\n\n";

const string menu = "Menu:\n"
					"\t1 - Vypsat vsechny mistnosti\n"
					"\t2 - Vypsat nezarezervovane mistnosti\n"
					"\t3 - Vyhledat mistnosti do urcite ceny:\n"
					"\t4 - Export nezarezervovanych mistnosti do HTML\n"
					"\t5 - Ukoncit program\n\n";

const string end = "Konec programu.";

int main(void)
{
	printTitle(nameApp);
	printMenu(menu);

	int choice = verifyInput();

	while (choice != 5)
	{
		chooseSelection(choice);
		printMenu(menu);

		choice = verifyInput();
	}

	cout << "Konec programu." << endl;
	

#ifndef __PROGTEST__
	system("pause");
#endif /* __PROGTEST__ */

	return 0;
}

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

void chooseSelection(char choice)
{
	switch (choice)
	{
		case '1':
			// TODO: Print all rooms from .csv file
			break;

		case '2':
			// TODO: Print all not booked rooms
			break;

		case '3':
			// TODO: Print all rooms by the price
			break;
		case '4':
			// TODO: Export rooms to HTML
			break;
	}
}

int verifyInput()
{
	string input;
	int choice;
	getline(cin, input);

	if (input.length() > 1)
	{
		cout << "Musis zadat cislo v rozmezi od 1 - 5." << endl;
	}
	choice = stoi(input);

	if (choice > 5 || choice < 1)
	{
		cout << "Musis zadat cislo v rozmezi od 1 - 5." << endl;
	}

	return choice;
}
#pragma region Includes

#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>

#pragma endregion

using namespace std;

#define OK 0
#define WRONG_DATA 1
#define IO_ERROR 2

#pragma region Function headers

void printTitle(string title);
void printMenu(string menu);
void chooseSelection(char choice);
int verifyInput();

#pragma endregion 


/// <summary>
/// Name of the application
/// </summary>
const string nameApp = "\t\tRezervace mistnosti\n"
					"==========================================================\n\n";

/// <summary>
/// Menu of the application
/// </summary>
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


#pragma region Functions
/// <summary>
/// Prints the title of the app
/// </summary>
/// <param name="title">Text to be printed</param>
void printTitle(string title)
{
	for (unsigned int i = 0; i < title.length(); i++)
	{
		cout << title.at(i);
		Sleep(25);
	}
}

/// <summary>
/// Prints menu with delay
/// </summary>
/// <param name="menu">Text to be printed</param>
void printMenu(string menu)
{
	for (unsigned int i = 0; i < menu.length(); i++)
	{
		cout << menu.at(i);
		Sleep(25);
	}
}

/// <summary>
/// Deciding due to choice what to do
/// </summary>
/// <param name="choice">Choice according to menu numbers</param>
void chooseSelection(int choice)
{
	switch (choice)
	{
		case 1:
			// TODO: Print all rooms from .csv file
			break;

		case 2:
			// TODO: Print all not booked rooms
			break;

		case 3:
			// TODO: Print all rooms by the price
			break;
		case 4:
			// TODO: Export rooms to HTML
			break;
	}
}

/// <summary>
/// Returns input (choose from menu) as Integer and verifies it by it's in the range (1 - 5)
/// </summary>
/// <returns>Choice as selection</returns>
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

#pragma endregion
#pragma region Includes

#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>

#pragma endregion

using namespace std;

#define CONVERT_ERROR -1
#define OK 0
#define WRONG_DATA 1
#define IO_ERROR 2

#pragma region Function headers

void PrintTitle(string title);
void PrintMenu(string menu);
void ChooseSelection(int choice);
int VerifyInput();

#pragma endregion 


/// <summary>
/// Name of the application
/// </summary>
const string NAME_APP = "\t\tRezervace mistnosti\n"
					"==========================================================\n\n";

/// <summary>
/// Menu of the application
/// </summary>
const string MENU = "Menu:\n"
					"\t1 - Vypsat vsechny mistnosti\n"
					"\t2 - Vypsat mistnosti podle kriterii\n"
					"\t3 - Zarezervovat mistnost\n"
					"\t4 - Export mistnosti do HTML\n"
					"\t5 - Ukoncit program\n\n";

const string END = "Konec programu.";

int main(void)
{
	PrintTitle(NAME_APP);
	PrintMenu(MENU);

	int choice = VerifyInput();

	while (choice != 5)
	{
		ChooseSelection(choice);
		PrintMenu(MENU);

		choice = VerifyInput();
	}

	cout << END << endl;
	

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
void PrintTitle(string title)
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
void PrintMenu(string menu)
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
void ChooseSelection(int choice)
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
int VerifyInput()
{
	string input;
	int choice;
	getline(cin, input);

	if (input.length() > 1)
	{
		cout << "Musis zadat cislo v rozmezi od 1 - 5." << endl;
		return CONVERT_ERROR;
	}

	try
	{
		choice = stoi(input);
	}

	catch (const std::exception&)
	{
		cout << "Musis zadat cislo v rozmezi od 1 - 5." << endl;
		return CONVERT_ERROR;
	}

	

	if (choice > 5 || choice < 1)
	{
		cout << "Musis zadat cislo v rozmezi od 1 - 5." << endl;
	}

	return choice;
}

#pragma endregion

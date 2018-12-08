#pragma region Includes

#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <fstream>

#pragma endregion

using namespace std;

#pragma region ERRROR DEFINITIONS

#define CONVERT_ERROR -1
#define OK 0
#define WRONG_DATA 1
#define IO_ERROR 2

#pragma endregion

#pragma region Structs

struct Room
{
	int Id;
	int Floor;
	int RoomNumber;
	int CapacitySeats;
	int Price;
};

#pragma endregion


#pragma region Function headers

void PrintTitle(string title);
void PrintMenu(string menu);
void ChooseSelection(int choice);
int VerifyInput();
bool IsTextValid(string text);
string *GetRoomData(string roomData);
Room LoadRoom(string *data);
Room *Load(Room *rooms, int n, Room room);
bool PrintAllRooms(string filename);

#pragma endregion 




#pragma region CONST_VARIABLES

/// <summary>
/// Name of the application
/// </summary>
const string NAME_APP = "\t\tBook reservation\n"
					"==========================================================\n\n";

/// <summary>
/// Menu of the application
/// </summary>
const string MENU = "Menu:\n"
					"\t1 - Print all rooms.\n"
					"\t2 - Print all rooms due to criteria\n"
					"\t3 - Book a room\n" 
					"\t4 - Export rooms into HTML\n"
					"\t5 - Exit application.\n\n";

const string END = "Konec programu.";

const string FILENAME = "rooms.csv";

const int DELAY = 10;

#pragma endregion

int main(void)
{
	PrintTitle(NAME_APP);
	PrintMenu(MENU);

	int choice = VerifyInput();

	while (choice != 5)
	{
		ChooseSelection(choice);
		system("pause");
		return 0;
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
		Sleep(DELAY);
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
		Sleep(DELAY);
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
			PrintAllRooms(FILENAME);
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

	if (IsTextValid(input) == false)
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

bool IsTextValid(string text)
{
	bool start_number = false; 
	bool end_number = false;
	for (unsigned int i = 0; i < text.length(); i++)
	{
		int charAscii = (int)text.at(i);
		if ((charAscii < 48 || charAscii > 57) && charAscii != 32)
		{
			return false;
		}

		if ((charAscii >= 48 || charAscii <= 57))
		{
			if (!start_number)
			{
				start_number = true;
			}

			if (end_number)
			{
				return false;
			}
		}

		if (charAscii == 32 && start_number)
		{
			end_number = true;
			start_number = false;
		}
	}

	return true;
}

string *GetRoomData(string roomData)
{
	string *data = new string[5];
	string current_element = "";

	int current_index = 0;

	for (unsigned int i = 0; i < roomData.length(); i++)
	{
		char currentChar = roomData.at(i);

		if (currentChar == ';')
		{
			data[current_index] = current_element;
			current_element = "";
			current_index++;

			continue;
		}

		if (currentChar != ';')
		{
			current_element += currentChar;
		}
	}

	data[current_index] = current_element;

	

	return data;
	
}

Room LoadRoom(string *data)
{
	Room room;

	room.Id = stoi(data[0]);
	room.Floor = stoi(data[1]);
	room.RoomNumber = stoi(data[2]);
	room.CapacitySeats = stoi(data[3]);
	room.Price = stoi(data[4]);

	return room;

}

Room *Load(Room *rooms, int n, Room room)
{
	Room *newRooms = new Room[n + 1];

	for (int i = 0; i < n; i++)
	{
		newRooms[i] = rooms[i];
	}
	delete[] rooms;
	rooms = nullptr;

	return newRooms;
}

bool PrintAllRooms(string filename)
{
	int n = 1;
	Room *roomsArray = new Room[1];
	string line;
	ifstream rooms(filename);
	
	if (!rooms.is_open())
	{
		return false;
	}

	getline(rooms, line);

	while (rooms.good())
	{
		getline(rooms, line);
		string *data = GetRoomData(line);
		Room currentRoom = LoadRoom(data);
		roomsArray = Load(roomsArray, n, currentRoom);
		
	}
	
	cout << roomsArray[0].RoomNumber << endl;

	rooms.close();

	return true;
}

#pragma endregion

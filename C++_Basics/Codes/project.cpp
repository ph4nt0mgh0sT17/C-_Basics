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

void PrintTitle();
void PrintMenu();
void PrintCriteria();
void ChooseMenu(int choice);
int VerifyInput(int peak);
int VerifyInput();
bool IsTextValid(string text);
string *GetRoomData(string roomData);
Room LoadRoom(string *data);
Room *Load(Room *rooms, int &n, Room room);
bool PrintAllRooms();
void PrintMenuCriteria(string criteria);
void PrintRoomsByPrice(int price);
void SelectPrice();

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
						"\t5 - Exit application\n\n";

const string CRITERIA = "Criteria:\n"
							"\t1 - Print due to price\n"
							"\t2 - Print due to date\n"
							"\t3 - Print due to seats\n"
							"\t4 - Cancel choice\n\n";

const string END = "Exit of the application.";

const string FILENAME = "rooms.csv";

const int DELAY = 10;

#pragma endregion

int main(void)
{
	PrintTitle();
	PrintMenu();

	int choice = VerifyInput(5);

	while (choice != 5)
	{
		ChooseMenu(choice);
		PrintMenu();

		choice = VerifyInput(5);
	}

	cout << END << endl;

#ifndef __PROGTEST__
	system("pause");
#endif /* __PROGTEST__ */

	return 0;
}


#pragma region Functions


void PrintDelay(string text)
{
	for (unsigned int i = 0; i < text.length(); i++)
	{
		cout << text.at(i);
		Sleep(DELAY);
	}
}

/// <summary>
/// Prints the title of the app
/// </summary>
/// <param name="title">Text to be printed</param>
void PrintTitle()
{
	PrintDelay(NAME_APP);
}

/// <summary>
/// Prints menu with delay
/// </summary>
/// <param name="menu">Text to be printed</param>
void PrintMenu()
{
	PrintDelay(MENU);
}

/// <summary>
/// Prints menu with delay
/// </summary>
/// <param name="menu">Text to be printed</param>
void PrintCriteria()
{
	PrintDelay(CRITERIA);
}

/// <summary>
/// Deciding due to choice what to do
/// </summary>
/// <param name="choice">Choice according to menu numbers</param>
void ChooseMenu(int choice)
{
	switch (choice)
	{
		case 1:
			PrintAllRooms();
			break;

		case 2:
			PrintMenuCriteria(CRITERIA);
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
int VerifyInput(int peak)
{
	string input;
	int choice;
	getline(cin, input);

	if (IsTextValid(input) == false)
	{
		cout << "You need to choose between 1 - " << peak << "." << endl;
		return CONVERT_ERROR;
	}

	try
	{
		choice = stoi(input);
	}

	catch (const std::exception&)
	{
		cout << "You need to choose between 1 - " << peak << "." << endl;
		return CONVERT_ERROR;
	}

	

	if (choice > peak || choice < 1)
	{
		cout << "You need to choose between 1 - " << peak << "." << endl;
	}

	return choice;
}

int VerifyInput()
{
	string input;
	int choice;
	getline(cin, input);

	if (IsTextValid(input) == false)
	{
		cout << "It needs to be a number." << endl;
		return CONVERT_ERROR;
	}

	try
	{
		choice = stoi(input);
	}

	catch (const std::exception&)
	{
		cout << "It needs to be a number." << endl;
		return CONVERT_ERROR;
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
	int *cislo = new int[45];
	string current_element = "";

	int current_index = 0;

	for (unsigned int i = 0; i < roomData.length(); i++)
	{
		char currentChar = roomData.at(i);

		if (currentChar == ',')
		{
			data[current_index] = current_element;
			current_element = "";
			current_index++;

			continue;
		}

		if (currentChar != ',')
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

Room *Load(Room *rooms, int &n, Room room)
{
	Room *newRooms = new Room[n + 1];

	if (n == 0)
	{
		newRooms[0] = room;
		n++;
		delete[] rooms;
		rooms = nullptr;

		return newRooms;

	}

	for (int i = 0; i < n; i++)
	{
		newRooms[i] = rooms[i];
	}
	newRooms[n] = room;

	n++;
	delete[] rooms;
	rooms = nullptr;

	return newRooms;
}

void PrintRoom(Room room)
{
	string textToBePrinted = "Room: " + to_string(room.RoomNumber) + 
		" located on " + to_string(room.Floor) + 
		". floor has capacity of : " + to_string(room.CapacitySeats) + 
		" seats. Costs : " + to_string(room.Price) + 
		" CZK. Its ID is : " + to_string(room.Id) + "\n";

    PrintDelay(textToBePrinted);
}

void PrintRooms(Room *rooms, int n)
{
	for (int i = 0; i < n; i++)
	{
		PrintRoom(rooms[i]);
	}

	cout << endl;
}

Room *GetAllRooms(string filename, int &n)
{
	n = 0;
	Room *roomsArray = new Room[1];
	string line;
	ifstream rooms(filename);

	if (!rooms.is_open())
	{
		return NULL;
	}

	getline(rooms, line);

	while (rooms.good())
	{
		getline(rooms, line);

		if (line != "")
		{
			string *data = GetRoomData(line);
			Room currentRoom = LoadRoom(data);
			roomsArray = Load(roomsArray, n, currentRoom);
		}

	}

	rooms.close();

	return roomsArray;
}

bool PrintAllRooms()
{
	int n = 0;

	Room *rooms = GetAllRooms(FILENAME, n);
	
	PrintRooms(rooms, n);

	delete[] rooms;
	rooms = nullptr;

	

	return true;
}

/// <summary>
/// Deciding due to choice what to do
/// </summary>
/// <param name="choice">Choice according to criteria numbers</param>
void ChooseCriteria(int choice)
{
	switch (choice)
	{
		case 1:
			SelectPrice();
			break;

		case 2:
			//
			break;

		case 3:
			// TODO: Print all rooms by the price
			break;
	}
}

bool GetRoomsByPrice(Room *&rooms, int &n, int price)
{
	int index = 0;
	Room *roomsPrice = new Room[1];
	bool roomFound = false;
	for (int i = 0; i < n; i++)
	{
		if (rooms[i].Price <= price)
		{
			roomsPrice = Load(roomsPrice, index, rooms[i]);
			roomFound = true;
		}
	}

	if (roomFound)
	{
		delete[] rooms;
		rooms = nullptr;

		n = index;
		rooms = roomsPrice;
	}

	else
	{
		delete[] roomsPrice;
		roomsPrice = nullptr;

		delete[] rooms;
		rooms = nullptr;
	}

	return roomFound;
}

void PrintRoomsByPrice(int price)
{
	int n = 0;
	Room *rooms = GetAllRooms(FILENAME, n);
	
	if (GetRoomsByPrice(rooms, n, price))
	{
		PrintRooms(rooms, n);
	}

	else
	{
		cout << "No room was found." << endl;
	}
}

void SelectPrice()
{
	cout << "Choose a price: ";

	int price = VerifyInput();

	PrintRoomsByPrice(price);
}

void PrintMenuCriteria(string criteria)
{
	PrintCriteria();

	int choice = VerifyInput(4);

	while (choice != 4)
	{
		ChooseCriteria(choice);
		PrintCriteria();
		choice = VerifyInput(4);
	}

	cout << endl << "Choice cancelled." << endl << endl;
}

#pragma endregion

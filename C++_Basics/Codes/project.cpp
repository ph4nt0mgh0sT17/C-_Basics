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
	string Date = "";
};

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

const string FILENAME_MAIN = "rooms.csv";

const string FILENAME_DATE = "dates.csv";

const string NO_ROOM_FOUND = "No room found.";

const int DELAY = 10;

#pragma endregion

#pragma region Function headers
void PrintDelay(string text, int delay = DELAY);
void PrintTitle();
void PrintMenu();
void PrintCriteria();
void ChooseMenu(int choice);
int VerifyInput(int peak);
int VerifyInput();
bool IsNumberValid(string number);
string *GetRoomData(string roomData, int n);
Room LoadRoom(string *data);
Room *Load(Room *rooms, int &n, Room room);
bool PrintAllRooms();
void PrintMenuCriteria();
void PrintRoomsByPrice(int price);
void SelectPrice();
void SelectDate();

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

	ifstream rooms("END.txt");

	if (!rooms.is_open())
	{
		return NULL;
	}

	string line;

	while (rooms.good())
	{
		getline(rooms, line);

		PrintDelay(line, 5);
		cout << endl;

	}

#ifndef __PROGTEST__
	system("pause");
#endif /* __PROGTEST__ */

	return 0;
}


#pragma region Functions

/// <summary>
/// Prints given text in delays. Just visual feature.
/// </summary>
/// <param name="text">Text to be printed</param>
void PrintDelay(string text, int delay)
{
	for (unsigned int i = 0; i < text.length(); i++)
	{
		cout << text.at(i);
		Sleep(delay);
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
			PrintMenuCriteria();
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

	if (IsNumberValid(input) == false)
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

/// <summary>
/// Verifies input if it's number...
/// </summary>
/// <returns>Input number</returns>
int VerifyInput()
{
	string input;
	int choice;
	getline(cin, input);

	if (IsNumberValid(input) == false)
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

int *VerifyDate(string date)
{
	//string *dates
	bool startedNumber = false;

	for (unsigned int i = 0; i < date.length(); i++)
	{
		if (((int)date.at(i) < 48 || (int)date.at(i) > 57))
		{

		}
	}
	return 0;
}

/// <summary>
/// Checks if given text is valid -> if it's number
/// </summary>
/// <param name="text">Given number</param>
/// <returns>True of false</returns>
bool IsNumberValid(string number)
{
	bool start_number = false; 
	bool end_number = false;
	for (unsigned int i = 0; i < number.length(); i++)
	{
		int charAscii = (int)number.at(i);
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

/// <summary>
/// Splits Room data into array due to commas in .csv file
/// </summary>
/// <param name="roomData">Data obtained from .csv file</param>
/// <returns>string array</returns>
string *GetRoomData(string roomData, int n)
{
	string *data = new string[n];
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
/// <summary>
/// Gets from data array information into Room struct
/// </summary>
/// <param name="data">Array data about given Room</param>
/// <returns>Room</returns>
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

/// <summary>
/// Expands room array of 1 element -> function for loading given room into given array of rooms
/// </summary>
/// <param name="rooms">Given array of rooms</param>
/// <param name="n">Given length of the array - must be defined before calling this function -> n is incrementing</param>
/// <param name="room">Room to be added to array</param>
/// <returns>Array</returns>
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

/// <summary>
/// Print current room
/// </summary>
/// <param name="room">Current room</param>
void PrintRoom(Room room)
{
	string textToBePrinted = "";
	if (room.Date == "")
	{
		textToBePrinted = "Room: " + to_string(room.RoomNumber) +
			"\t located on " + to_string(room.Floor) +
			". floor has capacity of : " + to_string(room.CapacitySeats) +
			" seats.\t Costs : " + to_string(room.Price) +
			" CZK.\t Its ID is : " + to_string(room.Id) + "\n";
	}

	else
	{
		textToBePrinted = "Room: " + to_string(room.RoomNumber) +
			"\t located on " + to_string(room.Floor) +
			". floor has capacity of : " + to_string(room.CapacitySeats) +
			" seats.\t Costs : " + to_string(room.Price) +
			" CZK.\t Its ID is : " + to_string(room.Id) + "\t Reservation: " + room.Date + "\n";
	}

    cout << textToBePrinted;
	Sleep(40);
}

/// <summary>
/// Print all rooms of the rooms array
/// </summary>
/// <param name="rooms">Given array</param>
/// <param name="n">Length of the array</param>
void PrintRooms(Room *rooms, int n)
{
	for (int i = 0; i < n; i++)
	{
		PrintRoom(rooms[i]);
	}

	cout << endl;
}

/// <summary>
/// Get all rooms into Room array
/// </summary>
/// <param name="n">Length of the array, not known at the end of the function is known</param>
/// <returns></returns>
Room *GetAllRooms(int &n)
{
	n = 0;
	Room *roomsArray = new Room[1];
	string line;
	ifstream rooms(FILENAME_MAIN);

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
			string *data = GetRoomData(line, 6);
			Room currentRoom = LoadRoom(data);
			roomsArray = Load(roomsArray, n, currentRoom);
		}

	}

	rooms.close();

	rooms.open(FILENAME_DATE);

	if (!rooms.is_open())
	{
		return NULL;
	}

	getline(rooms, line);

	while (rooms.good())
	{
		bool foundId = false;
		getline(rooms, line);
		if (line != "")
		{
			string *data = GetRoomData(line, 2);
			for (int i = 0; i < n; i++)
			{
				if (roomsArray[i].Id == stoi(data[0]))
				{
					roomsArray[i].Date = data[1];
					foundId = true;
				}

			}

			if (!foundId)
			{
				cout << "Wrong ID in .csv file.";
				return NULL;
			}
		}
	}

	rooms.close();

	return roomsArray;
}

/// <summary>
/// Print all rooms from the .csv file
/// </summary>
/// <returns></returns>
bool PrintAllRooms()
{
	int n = 0;

	Room *rooms = GetAllRooms(n);

	if (rooms == NULL)
	{
		return false;
	}
	
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
			SelectDate();
			break;

		case 3:
			// TODO: Print all rooms by the price
			break;
	}
}

#pragma region Rooms by price

/// <summary>
/// Get all rooms by the given price
/// </summary>
/// <param name="rooms">Array which is during this function changed</param>
/// <param name="n">Length of the array</param>
/// <param name="price">Maximal price which can be allowed</param>
/// <returns>If any room was found</returns>
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

	// Sort rooms array - BubbleSort
	bool exchangeDone = false;

	do
	{
		exchangeDone = false;

		for (int i = 0; i < index-1; i++)
		{
			if (roomsPrice[i].Price > roomsPrice[i + 1].Price)
			{
				swap(roomsPrice[i], roomsPrice[i + 1]);
				exchangeDone = true;
			}
		}
	}
	while (exchangeDone);

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

/// <summary>
/// Prints all rooms that was found. (If they were found)
/// </summary>
/// <param name="price">Maximal price of the room</param>
void PrintRoomsByPrice(int price)
{
	int n = 0;
	Room *rooms = GetAllRooms(n);

	if (GetRoomsByPrice(rooms, n, price))
	{
		PrintRooms(rooms, n);
	}

	else
	{
		cout << NO_ROOM_FOUND << endl;
	}
}

/// <summary>
/// Choosing price by the user
/// </summary>
void SelectPrice()
{
	cout << "Choose a price: ";

	int price = VerifyInput();

	PrintRoomsByPrice(price);
}


#pragma endregion

#pragma region Rooms by date

void PrintRoomsByDate(string date)
{
	int length = 0;

	Room *roomsDate = GetAllRooms(length);

	bool foundRoom = false;
	for (int i = 0; i < length; i++)
	{
		if (roomsDate[i].Date == date)
		{
			PrintRoom(roomsDate[i]);
			foundRoom = true;
		}
	}

	if (!foundRoom)
	{
		cout << endl;
		PrintDelay(NO_ROOM_FOUND);
		cout << endl << endl;
	}

	delete[] roomsDate;
	roomsDate = nullptr;
}

bool isLeapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				return true;
			}

			else
			{
				return false;
			}
		}

		else
		{
			return true;
		}
	}

	else
	{
		return false;
	}
}

bool CheckDate(int day, int month, int year)
{
	int *daysMonth = new int[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };

	if (month == 2)
	{
		if (isLeapYear(year))
		{
			if (day <= 29)
			{
				return true;
			}

			else
			{
				return false;
			}
		}

		else 
		{
			if (day <= 28)
			{
				return true;
			}

			else
			{
				return false;
			}
		}
	}

	if (day <= daysMonth[month - 1])
	{
		return true;
	}

	else
	{
		return false;
	}

	if (month < 1 || month > 12)
	{
		return false;
	}
	
}

bool VerifyDateInput(string &date)
{
	string year, month, day;
	year = month = day = "";
	
	bool isGap = false;
	bool isDot = false;

	bool isDay = true;
	bool isMonth = false;
	bool isYear = false;

	for (unsigned int i = 0; i < date.length(); i++)
	{
		if ((int)date.at(i) >= 48 && (int)date.at(i) <= 57)
		{
			if (isDay)
			{
				day += date.at(i);
			}

			if (isMonth)
			{
				month += date.at(i);
			}

			if (isYear)
			{
				year += date.at(i);
			}

			isDot = false;
		}

		else if (date.at(i) == ' ')
		{
			if (isGap)
			{
				cout << endl;
				PrintDelay("Wrong input.");
				cout << endl << endl;
				return false;
			}
			isGap = true;
		}

		else if (date.at(i) == '.')
		{
			if (isYear)
			{
				cout << endl;
				PrintDelay("Wrong input.");
				cout << endl << endl;
				return false;
			}

			if (isDot)
			{
				cout << endl;
				PrintDelay("Wrong input.");
				cout << endl << endl;
				return false;
			}
			isDot = true;

			if (isDay)
			{
				isDay = false;
				isMonth = true;
			}

			else if (isMonth)
			{
				isMonth = false;
				isYear = true;
			}

			isGap = false;
		}

		else
		{
			cout << endl;
			PrintDelay("Wrong input.");
			cout << endl << endl;
			return false;
		}

		

	}

	if (day == "" || month == "" || year == "")
	{
		cout << endl;
		PrintDelay("Wrong input.");
		cout << endl << endl;
		return false;
	}

	if (!CheckDate(stoi(day), stoi(month), stoi(year)))
	{
		cout << endl;
		PrintDelay("Wrong date.");
		cout << endl << endl;
		return false;
	}
	
	date = to_string(stoi(day)) + ". " + to_string(stoi(month)) + ". " + to_string(stoi(year));

	return true;
}

void SelectDate()
{
	PrintDelay("Select a date (dd.mm.yyyy) or (dd. mm. yyyy): ");
	string date;
	getline(cin, date);

	if (!VerifyDateInput(date))
	{
		cin.clear();
		return;
	}

	cin.clear();

	PrintRoomsByDate(date);

}

#pragma endregion



/// <summary>
/// Prints criteria into console
/// </summary>
void PrintMenuCriteria()
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

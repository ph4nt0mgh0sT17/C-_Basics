#pragma once

#include <string>

class Client
{
private:
	static int objectsCount;
	int code;
	std::string name;

public:
	static int GetObjectsCount();


	/// <summary>
	/// Initialization of the Client class using code and name parameter
	/// </summary>
	/// <param name="code">Code of the client</param>
	/// <param name="name">Name of the client</param>
	Client(int code, std::string name);

	~Client();

	/// <summary>
	/// Method that gets Code of current Client instance 
	/// </summary>
	/// <returns>Code of current client</returns>
	int GetCode();

	//// <summary>
	/// Method that gets Name of current Client instance 
	/// </summary>
	/// <returns>Name of current client</returns>
	std::string GetName();

};


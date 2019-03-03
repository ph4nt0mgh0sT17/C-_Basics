#pragma once

#include <string>

class InvoiceItem
{
private:
	std::string name;
	int price;

public:
	InvoiceItem(std::string name, int price);
	int GetPrice();
	std::string GetName();
};


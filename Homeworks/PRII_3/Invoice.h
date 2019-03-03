#pragma once

#include "Person.h"
#include "InvoiceItem.h"

#include <string>

class Invoice
{
private:
	
	static int ID;
	Person* owner;
	InvoiceItem** items;
	int itemsCount;
	const int currentID;

	void Resize();

public:
	Invoice(Person* owner, InvoiceItem itemStart);
	Invoice(std::string nameOwner, std::string addressOwner, std::string nameItem, int priceItem);
	~Invoice();
	bool AddItem(std::string name, int price);
	int CalculatePrice();
	std::string GetData();
};



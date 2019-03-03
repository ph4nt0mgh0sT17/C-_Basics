#include "InvoiceItem.h"



InvoiceItem::InvoiceItem(std::string name, int price)
{
	this->name = name;
	this->price = price;
}

int InvoiceItem::GetPrice()
{
	return this->price;
}

std::string InvoiceItem::GetName()
{
	return this->name;
}
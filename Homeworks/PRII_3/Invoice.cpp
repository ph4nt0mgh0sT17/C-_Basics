#include "Invoice.h"
#include "Person.h"

/// <summary>
/// Always must be in .cpp file, not .h file!!!
/// </summary>
int Invoice::ID = 0;

Invoice::Invoice(Person* owner, InvoiceItem itemStart) : currentID(ID++)
{
	
	this->owner = owner;
	this->itemsCount = 1;
	this->items = new InvoiceItem*[1];
}

Invoice::Invoice(std::string nameOwner, std::string addressOwner, std::string nameItem, int priceItem) : currentID(ID++)
{
	this->owner = new Person(nameOwner, addressOwner);
	this->itemsCount = 1;
	this->items = new InvoiceItem*[this->itemsCount];
}


Invoice::~Invoice()
{
}

void Invoice::Resize()
{
	this->itemsCount++;
	InvoiceItem** newArray = new InvoiceItem*[this->itemsCount];

	for (int i = 0; i < this->itemsCount - 1; i++)
	{
		newArray[i] = this->items[i];
	}

	this->items = newArray;
}

bool Invoice::AddItem(std::string name, int price)
{
	InvoiceItem* item = new InvoiceItem(name, price);

	this->items[this->itemsCount-1] = item;

	this->Resize();

	return true;
}

int Invoice::CalculatePrice()
{
	int totalPrice = 0;

	for (int i = 0; i < this->itemsCount-1; i++)
	{
		totalPrice += this->items[i]->GetPrice();
	}

	return totalPrice;
}

std::string Invoice::GetData()
{
	std::string result = "Invoice - ID: " + std::to_string(this->currentID) + "; Owner: " + this->owner->GetOwnerData() + "\n\nItems:\n";

	for (int i = 0; i < this->itemsCount - 1; i++)
	{
		result += "\t" + this->items[i]->GetName() + "; Price: " + std::to_string(this->items[i]->GetPrice()) + " Czech Crowns\n";
	}

	result += "\nTotal price: " + std::to_string(this->CalculatePrice()) + " Czech Crowns.";

	return result;
}

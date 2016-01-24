#include "Session.h"
#include "Item.h"
#include "Person.h"


Session::Session()
{
}


Session::~Session()
{
}

std::vector<Item*> Session::getItemList()
{
	return itemList;
}

void Session::addAnotherItem(Item *newItem)
{
	itemList.push_back(std::move(newItem));
}

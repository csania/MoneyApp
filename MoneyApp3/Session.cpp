#include "Session.h"
#include "Item.h"
#include "Person.h"


Session::Session()
{
}


Session::~Session()
{
}

void Session::addAnotherItem(Item *newItem)
{
	itemList.push_back(std::move(newItem));
}

void Session::addPersonToList(Person* newPerson)
{
	listOfPeople.push_back(newPerson);
}

void Session::updatePeopleList(std::vector<Person*> newList)
{
	listOfPeople.clear();
	listOfPeople = newList;
}

std::vector<Item*> Session::getItemList()
{
	return itemList;
}

std::vector <Person*> Session::getPeopleList()
{
	return listOfPeople;
}

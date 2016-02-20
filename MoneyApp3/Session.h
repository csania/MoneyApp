#pragma once

#include <vector>
#include <string>


class Item;
class Person;

class Session
{
public:
	Session();
	~Session();

	std::vector <Item*> getItemList();
	std::vector <Person> getPeopleList();
	void addAnotherItem(Item *newItem);
	void addPersonToList(Person newPerson);
	void updatePeopleList(std::vector<Person> newList);

protected:
	std::vector<Item*> itemList;
	std::vector<Person> listOfPeople;

};


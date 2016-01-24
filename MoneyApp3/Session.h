#pragma once

#include <vector>
#include <string>


class Item;

class Session
{
public:
	Session();
	~Session();

	std::vector <Item*> getItemList();
	void addAnotherItem(Item *newItem);

protected:
	std::vector<Item*> itemList;

};


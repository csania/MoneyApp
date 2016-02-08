#pragma once

#include <string>
#include <vector>

class Item
{
public:
	Item(std::string date, std::string time, std::string value, std::string currency = "Pounds");
	~Item();

	std::string getType();
	std::string getAmmount();
	std::string getDate();
	std::string getCurrency();

protected:

	//enum{Food, Drinks, Rent, Flight, Misc};
	std::string type_;
	std::string date_;
	std::string time_;
	std::string ammount_;
	std::string currency_;
	int numberOfPeople_;
	long int itemID_;

};


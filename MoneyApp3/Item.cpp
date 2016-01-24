#include "Item.h"

Item::Item(std::string date, std::string time, std::string value, std::string currency)
{
	date_ = date;
	time_ = time;
	ammount_ = value;
	currency_ = currency;
}

Item::~Item()
{

}
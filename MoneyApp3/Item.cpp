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

std::string Item::getType()
{
	return type_;
}

std::string Item::getAmmount()
{
	return ammount_;
}

std::string Item::getDate()
{
	return date_;
}

std::string Item::getCurrency()
{
	return currency_;
}
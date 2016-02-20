#include "Person.h"

Person::Person(std::string name)
{
	name_ = name;
	float ammountPaid_ = 0;
	float ammountOwes_ = 0;
}


Person::~Person()
{
}

void Person::addTransaction(long int transaction)
{
	purchaseList.push_back(std::move(transaction));
}

std::string Person::getPersonName()
{
	return name_;
}

float Person::getAmmountPaid()
{
	return ammountPaid_;
}

float Person::getAmmountOwes()
{
	return ammountOwes_;
}

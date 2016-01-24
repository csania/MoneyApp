#include "Person.h"


Person::Person(std::string name)
{
	name_ = name;
}


Person::~Person()
{
}

void Person::addTransaction(long int transaction)
{
	purchaseList.push_back(std::move(transaction));
}

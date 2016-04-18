#include "Person.h"

Person::Person(std::string name)
{
	name_ = name;
	ammountPaid_ = 0;
	ammountOwes_ = 0;
}


Person::~Person()
{
}

void Person::addTransaction(long int transaction)
{
	purchaseList.push_back(std::move(transaction));
}

void Person::setDate(QDate date)
{
	addedDate_ = date;
}

void Person::setTime(QTime time)
{
	addedTime_ = time;
}

void Person::setIsSelectedForEdit(bool value)
{
	isSelectedForEdit = value;
}

bool Person::getIsSelectedForEdit()
{
	return isSelectedForEdit;
}

QString Person::getAddedDate()
{
	return addedDate_.toString("d MM");
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

void Person::changeAmmountPaid(float val)
{
	ammountPaid_ += val;
}

void Person::changeAmmountOwes(float val)
{
	ammountOwes_ += val;
}

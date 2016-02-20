#pragma once

#include <string>
#include <vector>

class Person
{
public:
	Person(std::string name);
	~Person();

	void addTransaction(long int transaction);

	float getAmmountPaid();
	float getAmmountOwes();
	std::string getPersonName();

	std::vector<long int> getPurchaseList();

private:

	std::string name_;
	float ammountPaid_;
	float ammountOwes_;
	std::vector<long int> purchaseList;

};


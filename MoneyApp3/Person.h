#pragma once

#include <string>
#include <vector>

class Person
{
public:
	Person(std::string name);
	~Person();

	void addTransaction(long int transaction);
	std::vector<long int> getPurchaseList();

private:

	std::string name_;
	std::vector<long int> purchaseList;

};


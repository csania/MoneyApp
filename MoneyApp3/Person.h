#pragma once

#include <string>
#include <vector>
#include <QtCore\qdatetime.h>

class Person
{
public:
	Person(std::string name);
	~Person();

	void addTransaction(long int transaction);
	void setDate(QDate date);
	void setTime(QTime time);
	void setIsSelectedForEdit(bool value);
	void changeAmmountPaid(float val);
	void changeAmmountOwes(float val);

	bool getIsSelectedForEdit();
	float getAmmountPaid();
	float getAmmountOwes();
	QString getAddedDate();
	std::string getPersonName();

	std::vector<long int> getPurchaseList();

private:

	std::string name_;
	bool isSelectedForEdit;
	float ammountPaid_;
	float ammountOwes_;
	std::vector<long int> purchaseList;

	QDate addedDate_;
	QTime addedTime_;

};


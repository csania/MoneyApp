#pragma once

#include <QtWidgets\QDialog>
#include <vector>

class QCheckBox;
class QLineEdit;
class Person;

class GenericSelectionDialog : public QDialog
{
	Q_OBJECT
public:

	GenericSelectionDialog();
	~GenericSelectionDialog();

	void choosePeopleDialog(const std::vector<Person*> peopleList);

	std::string getCheckedPersonName(int index);
	float getAmmountPaid(int index);
	std::vector<int> getCheckedBoxes();

private:
	QDialog *genericDialog;
	std::vector<QCheckBox*> checkBoxList;
	std::vector<QLineEdit*> lineEditList;
	std::vector<int> checkedBoxes;

private slots:
	void checked(int state);
	void okPressed();
};


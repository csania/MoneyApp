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

private:
	QDialog *genericDialog;
	std::vector<QCheckBox*> checkBoxList;
	std::vector<QLineEdit*> lineEditList;

private slots:
	void checked(int state);
};


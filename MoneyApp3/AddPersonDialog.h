#pragma once

#include <QtWidgets\QDialog>
#include <QtCore\qstring.h>
#include <vector>

class QLineEdit;
class QDialogButtonBox;
class QSignalMapper;
class QListWidget;
class Person;

class AddPersonDialog : public QDialog
{
	Q_OBJECT
public:
	AddPersonDialog();
	~AddPersonDialog();

	void populateListWidget();
	void createDialogeComponents(std::vector<Person> &listOfPeople);
	bool shouldModify();
	std::vector<Person> getNewList();

private:
	bool savePeopleModification;
	std::vector<Person> localListOfPeople;

	void cleanPeopleListDialog();
	void addPersonToPeopleDialog(Person newPerson);

	QListWidget *peopleSummaryDialog;
	QLineEdit* newPersonName;
	QDialogButtonBox* buttonBox;
	
private slots:
	void addPersonToList();
	void saveChanges();
	void cancelChanges();
	//void editDate();

};


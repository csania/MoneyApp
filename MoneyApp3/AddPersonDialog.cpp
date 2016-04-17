#include "AddPersonDialog.h"
#include "Person.h"
#include <math.h>

#include <QtWidgets\QVBoxLayout>
#include <QtWidgets\QHBoxLayout>
#include <QtWidgets\QListWidget.h>
#include <QtWidgets\QLineEdit.h>
#include <QtWidgets\QLabel.h>
#include <QtWidgets\QToolbutton.h>
#include <QtWidgets\QDialogbuttonbox.h>
#include <QtWidgets\QMessagebox.h>
#include <QtWidgets\QTableWidget.h>


#include <QtGui\qimage.h>
#include <QtGui\qbitmap.h>
#include <QtCore\qfile.h>


AddPersonDialog::AddPersonDialog()
{
	savePeopleModification = false;
	newPersonName = new QLineEdit;
	buttonBox = nullptr;
	peopleSummaryDialog = nullptr;
}


AddPersonDialog::~AddPersonDialog()
{
	if(buttonBox) {
		delete buttonBox;
		buttonBox = nullptr;
	}
	cleanPeopleListDialog();
}

void AddPersonDialog::createDialogeComponents(std::vector<Person*> &listOfPeople)
{
	localListOfPeople = listOfPeople;

	QVBoxLayout* mainLayoyt;
	setLayout(mainLayoyt = new QVBoxLayout());

	QHBoxLayout *nameLayout = new QHBoxLayout();
	mainLayoyt->addLayout(nameLayout);

	QLabel nameLabel;
	nameLayout->addWidget(&nameLabel);
	nameLabel.setText("Name");
	nameLayout->addWidget(newPersonName);

	QToolButton *addPerson = new QToolButton(this);
	addPerson->setToolButtonStyle(Qt::ToolButtonIconOnly);

	QBitmap iconBitMap;
	iconBitMap.load("addIcon.jpg");
	QIcon addIcon = QIcon(iconBitMap);
	addPerson->setIcon(addIcon);

	nameLayout->addWidget(addPerson);

	peopleSummaryDialog = new QTableWidget(this);
	peopleSummaryDialog->setColumnCount(3);
	peopleSummaryDialog->setRowCount(0);

	QStringList stringList;
	stringList << "Date " << "Name " << "Balance";
	peopleSummaryDialog->setHorizontalHeaderLabels(stringList);
	peopleSummaryDialog->resizeColumnsToContents();

	mainLayoyt->addWidget(peopleSummaryDialog);

	buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
	mainLayoyt->addWidget(buttonBox);

	populateListWidget();

	connect(buttonBox, SIGNAL(accepted()), this, SLOT(saveChanges()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(cancelChanges()));
	connect(addPerson, SIGNAL(clicked()), this, SLOT(addPersonToList()));


	this->exec();
}

void AddPersonDialog::populateListWidget()
{
	int rowToUse = 0;
	for(auto it = localListOfPeople.begin(); it != localListOfPeople.end(); ++it) {

		auto balance = (**it).getAmmountPaid() - (**it).getAmmountOwes();
		QString balanceString = int((balance * 100)/100);

		peopleSummaryDialog->insertRow(rowToUse);
		peopleSummaryDialog->setItem(rowToUse,0,new QTableWidgetItem((**it).getAddedDate()));
		peopleSummaryDialog->setItem(rowToUse,1,new QTableWidgetItem(str((**it).getPersonName())));
		peopleSummaryDialog->setItem(rowToUse,2,new QTableWidgetItem(balanceString));
		++rowToUse;
	}
}

std::vector<Person*> AddPersonDialog::getNewList()
{
	return localListOfPeople;
}

void AddPersonDialog::saveChanges()
{
	savePeopleModification = true;
	close();
}

void AddPersonDialog::cancelChanges()
{
	savePeopleModification = false;
	close();
}

void AddPersonDialog::addPersonToList()
{
	if(newPersonName->text() != "") {
		Person *addedPerson =  new Person(newPersonName->text().toStdString());
		QDate nowDate = QDate::currentDate();
		QString date = nowDate.toString("d MM");
		QTime nowTime = QTime::currentTime();
		QString time = nowTime.toString("hh:mm");

		addedPerson->setDate(nowDate);
		addedPerson->setTime(nowTime);
		localListOfPeople.push_back(addedPerson);

		addPersonToPeopleDialog(addedPerson);
		newPersonName->clear();
	}
}

bool AddPersonDialog::shouldModify()
{
	return savePeopleModification;
}

void AddPersonDialog::addPersonToPeopleDialog(Person* newPerson)
{
	int rowToUse = 0;
	if(localListOfPeople.size() > 0) {
		rowToUse = localListOfPeople.size() - 1;
	}

	auto balance = newPerson->getAmmountPaid() - newPerson->getAmmountOwes();
	QString balanceString = int((balance * 100)/100);

	peopleSummaryDialog->insertRow(rowToUse);
	peopleSummaryDialog->setItem(rowToUse,0,new QTableWidgetItem(newPerson->getAddedDate()));
	peopleSummaryDialog->setItem(rowToUse,1,new QTableWidgetItem(str(newPerson->getPersonName())));
	peopleSummaryDialog->setItem(rowToUse,2,new QTableWidgetItem(balanceString));
}

void AddPersonDialog::cleanPeopleListDialog()
{
	peopleSummaryDialog->clear();
}

QString AddPersonDialog::str(std::string stringToConvert)
{
	return QString::fromStdString(stringToConvert);
}
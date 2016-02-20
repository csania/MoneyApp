#include "AddPersonDialog.h"
#include "Person.h"

#include <QtWidgets\QVBoxLayout>
#include <QtWidgets\QHBoxLayout>
#include <QtWidgets\QListWidget.h>
#include <QtWidgets\QLineEdit.h>
#include <QtWidgets\QLabel.h>
#include <QtWidgets\qtoolbutton.h>
#include <QtWidgets\qdialogbuttonbox.h>
#include <QtWidgets\qmessagebox.h>

#include <QtGui\qimage.h>
#include <QtGui\qbitmap.h>
#include <QtCore\qfile.h>


AddPersonDialog::AddPersonDialog()
{
	savePeopleModification = false;
	newPersonName = new QLineEdit;
	buttonBox = nullptr;
}


AddPersonDialog::~AddPersonDialog()
{
	if(buttonBox) {
		delete buttonBox;
		buttonBox = nullptr;
	}
	cleanPeopleListDialog();
}

void AddPersonDialog::createDialogeComponents(std::vector<Person> &listOfPeople)
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


	peopleSummaryDialog = new QListWidget(this);
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
	for(auto it = localListOfPeople.begin(); it != localListOfPeople.end(); ++it) {
		QListWidgetItem* qListItem = new QListWidgetItem();
		qListItem->setText(QString::fromStdString((*it).getPersonName()));
		peopleSummaryDialog->addItem(qListItem);
	}
}

std::vector<Person> AddPersonDialog::getNewList()
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
		Person addedPerson(newPersonName->text().toStdString());
		localListOfPeople.push_back(addedPerson);
		addPersonToPeopleDialog(addedPerson);
	}
}

bool AddPersonDialog::shouldModify()
{
	return savePeopleModification;
}

void AddPersonDialog::addPersonToPeopleDialog(Person newPerson)
{
	QListWidgetItem* qListItem = new QListWidgetItem();
	qListItem->setText(QString::fromStdString((newPerson).getPersonName()));
	peopleSummaryDialog->addItem(qListItem);
}

void AddPersonDialog::cleanPeopleListDialog()
{
	peopleSummaryDialog->clear();
}
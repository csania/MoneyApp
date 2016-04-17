#include <ctime>
#include <algorithm>

#include "Session.h"
#include "Interface.h"
#include "Item.h"
#include "Person.h"
#include "AddTransactionDialog.h"
#include "AddPersonDialog.h"

#include <QtWidgets\QVBoxLayout>
#include <QtWidgets\QHBoxLayout>
#include <QtWidgets\QDialog>
#include <QtWidgets\QToolButton>

#include <QtWidgets\QListWidget.h>
#include <QtWidgets\qpushbutton.h>
#include <QtCore\qdatetime.h>

#include "add.xpm"

Interface::Interface(Session* currentSession)
{
	thisSession = currentSession;
	QVBoxLayout* mainLayoyt;
	setLayout(mainLayoyt = new QVBoxLayout(this));

	peopleButton = new QToolButton(this);
	createPeopleWidget();
	mainLayoyt->addWidget(peopleButton);


	transactionData = new QListWidget(this);
	mainLayoyt->addWidget(transactionData);

	QHBoxLayout *buttonsLayout = new QHBoxLayout();
	createButtonsLayout(buttonsLayout);

	mainLayoyt->addLayout(buttonsLayout);
}

void Interface::createPeopleWidget()
{
	peopleButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	QPixmap pMap((const char **) add_user);
	peopleButton->setIcon(QIcon(pMap));

	populatePeopleWidget();

	connect(peopleButton, SIGNAL(clicked()), this, SLOT(addPersonToSession()));
}

void Interface::addPersonToSession()
{
	AddPersonDialog addPerson;
	addPerson.createDialogeComponents(thisSession->getPeopleList());
	if(addPerson.shouldModify()) {
		auto newList = addPerson.getNewList();
		thisSession->updatePeopleList(newList);
		populatePeopleWidget();
	}
}

void Interface::populatePeopleWidget(std::string newName)
{
	auto listOfPeople = thisSession->getPeopleList();
	if(listOfPeople.size() == 0) {
		peopleButton->setText("Session has no people");
	}
	else {
		std::string allNames;
		std::for_each(listOfPeople.begin(), listOfPeople.end(), [&allNames](Person *current) {
			allNames += current->getPersonName() + " ";
		});
		peopleButton->setText(QString::fromStdString(allNames));
	}
}

void Interface::createButtonsLayout(QHBoxLayout *buttonsLayout)
{
	QPushButton *addItem = new QPushButton(this);
	QPushButton *removeItem = new QPushButton(this);
	QPushButton *analyze = new QPushButton(this);

	addItem->setText("Add");
	removeItem->setText("Remove");
	analyze->setText("Analyze");

	buttonsLayout->addWidget(addItem);
	buttonsLayout->addWidget(removeItem);
	buttonsLayout->addWidget(analyze);

	connect(addItem, SIGNAL(clicked()), this, SLOT(addTransaction()));
}

void Interface::addTransaction()
{
	QDate nowDate = QDate::currentDate();
	QString date = nowDate.toString("d MM");
	QTime nowTime = QTime::currentTime();
	QString time = nowTime.toString("hh:mm");

	AddTransactionDialog transactionDialog;
	transactionDialog.createDialogComponenets(thisSession->getPeopleList());
	if(transactionDialog.getAcceptedDialog()) {

		std::string outS = transactionDialog.getItemType() + " " + transactionDialog.getItemPrice();
		QString qStr = QString::fromUtf8(outS.c_str());

		QListWidgetItem* qListItem = new QListWidgetItem;
		qListItem->setText(date + " " + time + " " + qStr);
		transactionData->addItem(qListItem);

		Item *newItem = new Item( date.toStdString(), time.toStdString(), "10");
		thisSession->addAnotherItem(newItem);
	}
}
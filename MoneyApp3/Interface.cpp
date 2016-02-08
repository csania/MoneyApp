#include <ctime>
#include <algorithm>

#include "Session.h"
#include "Interface.h"
#include "Item.h"
#include "AddTransactionDialog.h"

#include <QtWidgets\QVBoxLayout>
#include <QtWidgets\QHBoxLayout>
#include <QtWidgets\QDialog>

#include <QtWidgets\QListWidget.h>
#include <QtWidgets\qpushbutton.h>
#include <QtCore\qdatetime.h>


Interface::Interface(Session* currentSession)
{
	addTransactionWidget = nullptr;

	thisSession = currentSession;
	QVBoxLayout* mainLayoyt;
	setLayout(mainLayoyt = new QVBoxLayout);

	transactionData = new QListWidget;
	mainLayoyt->addWidget(transactionData);

	QHBoxLayout *buttonsLayout = new QHBoxLayout;
	createButtonsLayout(buttonsLayout);

	mainLayoyt->addLayout(buttonsLayout);
}

void Interface::createButtonsLayout(QHBoxLayout *buttonsLayout)
{
	QPushButton *addItem = new QPushButton;
	QPushButton *removeItem = new QPushButton;
	QPushButton *analyze = new QPushButton;

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
	QString date = nowDate.toString("d MMMM yy");
	QTime nowTime = QTime::currentTime();
	QString time = nowTime.toString("hh:mm");

	AddTransactionDialog transactionDialog;
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
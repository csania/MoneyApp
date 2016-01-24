#include <ctime>

#include "Session.h"
#include "Interface.h"
#include "Item.h"
#include "algorithm"

#include <QtWidgets\QVBoxLayout>
#include <QtWidgets\QHBoxLayout>
#include <QtWidgets\QDialog>
#include <QtWidgets\QListWidget.h>
#include <QtWidgets\qpushbutton.h>
#include <QtCore\qdatetime.h>
#include <QtWidgets\qlabel.h>
#include <QtWidgets\qlineedit.h>

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

	Item *newItem = new Item( date.toStdString(), time.toStdString(), "10");
	thisSession->addAnotherItem(newItem);
	QListWidgetItem* qListItem = new QListWidgetItem;
	qListItem->setText(date + " " + time);

	createAddTransactionDialogue();

	transactionData->addItem(qListItem);
}

void Interface::createAddTransactionDialogue()
{
	QVBoxLayout* widgetLayout = new QVBoxLayout;
	addTransactionWidget = new QDialog;

	addTransactionWidget->setLayout(widgetLayout);

	QHBoxLayout nameLayout;
	QLabel nameLabel;
	nameLabel.setText("Item Name");
	QLineEdit nameLine;
	nameLayout.addWidget(&nameLabel);
	nameLayout.addWidget(&nameLine);
	widgetLayout->addLayout(&nameLayout);

	QHBoxLayout priceLayout;
	QLabel priceLabel;
	priceLabel.setText("Item Price");
	QLineEdit priceLine;
	priceLayout.addWidget(&priceLabel);
	priceLayout.addWidget(&priceLine);
	widgetLayout->addLayout(&priceLayout);

	QHBoxLayout infoLayout;
	QLabel infoLabel;
	infoLabel.setText("Addiotional Information");
	QLineEdit infoLine;
	infoLayout.addWidget(&infoLabel);
	infoLayout.addWidget(&infoLine);
	widgetLayout->addLayout(&infoLayout);

	QPushButton *okButton = new QPushButton;
	okButton->setText("Ok");
	widgetLayout->addWidget(okButton);

	connect(okButton, SIGNAL(clicked()), this, SLOT(addTransactionDetailsIntoList()));

	addTransactionWidget->exec();
}

void Interface::addTransactionDetailsIntoList()
{
	auto infoList = addTransactionWidget->children();
}
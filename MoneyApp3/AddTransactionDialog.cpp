#include "AddTransactionDialog.h"
#include "GenericSelectionDialog.h"
#include "Person.h"

#include <QtWidgets\QVBoxLayout>
#include <QtWidgets\QHBoxLayout>
#include <QtWidgets\QDialogButtonBox>
#include <QtWidgets\qlineedit.h>
#include <QtWidgets\qlabel.h>
#include <QtWidgets\qplaintextedit.h>
#include <QtWidgets\qpushbutton.h>


AddTransactionDialog::AddTransactionDialog()
{
	itemTypeLine = new QLineEdit;
	priceLine = new QLineEdit;
	infoLine = new QPlainTextEdit;


	buttonBox = nullptr;
	acceptDialog = false;
}


AddTransactionDialog::~AddTransactionDialog()
{
	if(buttonBox != nullptr) {
		delete buttonBox;
	}
	if (itemTypeLine != nullptr) {
		delete itemTypeLine;
	}
	if (itemTypeLine != nullptr) {
		delete priceLine;
	}
	if (itemTypeLine != nullptr) {
		delete infoLine;
	}
}

void AddTransactionDialog::createDialogComponenets(std::vector<Person*> &listOfPeople)
{
	locallistOfPeople = listOfPeople;
	QVBoxLayout* widgetLayout = new QVBoxLayout;
	this->setLayout(widgetLayout);

	QHBoxLayout nameLayout;
	QLabel nameLabel;
	nameLabel.setText("Item Name");
	nameLayout.addWidget(&nameLabel);
	nameLayout.addWidget(itemTypeLine);
	widgetLayout->addLayout(&nameLayout);

	QHBoxLayout priceLayout;
	QLabel priceLabel;
	priceLabel.setText("Item Price");
	priceLayout.addWidget(&priceLabel);
	priceLayout.addWidget(priceLine);
	widgetLayout->addLayout(&priceLayout);
	
	QLabel *infoLabel = new QLabel(this);
	infoLabel->setText("Additional Information");
	widgetLayout->addWidget(infoLabel);
	infoLine->setFixedHeight(100);
	widgetLayout->addWidget(infoLine);

	QHBoxLayout buyerLayot;
	QLabel *buyerLabel = new QLabel(this);
	QPushButton *buyerButton = new QPushButton(this);
	buyerButton->setText("Choose");
	buyerLabel->setText("Who Paid ?");
	buyerLayot.addWidget(buyerLabel);
	buyerLayot.addWidget(buyerButton);
	widgetLayout->addLayout(&buyerLayot);


	buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
	widgetLayout->addWidget(buttonBox);

	QPushButton *editPeopleNum = new QPushButton(this);
	editPeopleNum->setText("Everyone is involved in this transaction");
	widgetLayout->addWidget(editPeopleNum);
	editPeopleNum->hide();

	connect(buttonBox, SIGNAL(accepted()), this, SLOT(pressedOk()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(pressedCancel()));
	connect(buyerButton, SIGNAL(clicked()), this, SLOT(clickedOnPeople()));

	this->exec();
}

void AddTransactionDialog::clickedOnPeople()
{
	GenericSelectionDialog selectPeopleDialog;
	selectPeopleDialog.choosePeopleDialog(locallistOfPeople);
	auto checkedList = selectPeopleDialog.getCheckedBoxes();

	if(checkedList.size() == 1) {
		auto currentName = selectPeopleDialog.getCheckedPersonName(checkedList.front());
		float paid = std::stof(priceLine->text().toStdString());
		findPersonByName(currentName)->changeAmmountPaid(paid);
	}
	else {
		for(auto it = checkedList.begin(); it != checkedList.end(); ++it) {
			auto currentName = selectPeopleDialog.getCheckedPersonName(*it);
			float paid = selectPeopleDialog.getAmmountPaid(*it);
			findPersonByName(currentName)->changeAmmountPaid(paid);
		}
	}
	
}

Person* AddTransactionDialog::findPersonByName(std::string name)
{
	for(auto it = locallistOfPeople.begin(); it != locallistOfPeople.end(); ++it) {
		if((*it)->getPersonName() == name) {
			return (*it);
		}
	}
	return nullptr;
}

void AddTransactionDialog::pressedOk()
{
	setDialogValues();
	acceptDialog = true;
	close();
}

void AddTransactionDialog::pressedCancel()
{
	acceptDialog = false;
	close();
}

void AddTransactionDialog::setDialogValues()
{
	itemType_ = itemTypeLine->text().toStdString();
	itemPrice_ = priceLine->text().toStdString();
	itemDetails_ = infoLine->toPlainText().toStdString();
}

std::list<std::string> AddTransactionDialog::getAllTransactionData()
{
	std::list<std::string> itemList;
	if(acceptDialog) {
		itemList.push_back(itemTypeLine->text().toStdString());
		itemList.push_back(priceLine->text().toStdString());
		itemList.push_back(infoLine->toPlainText().toStdString());
	}

	return itemList;
}

std::string AddTransactionDialog::getItemType()
{
	return itemType_;
}

std::string AddTransactionDialog::getItemPrice()
{
	return itemPrice_;
}

std::string AddTransactionDialog::getItemDetails()
{
	return itemDetails_;
}

bool AddTransactionDialog::getAcceptedDialog()
{
	return acceptDialog;
}
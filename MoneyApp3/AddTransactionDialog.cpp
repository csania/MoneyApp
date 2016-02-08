#include "AddTransactionDialog.h"

#include <QtWidgets\QVBoxLayout>
#include <QtWidgets\QHBoxLayout>
#include <QtWidgets\QDialogButtonBox>
#include <QtWidgets\qlineedit.h>
#include <QtWidgets\qlabel.h>


AddTransactionDialog::AddTransactionDialog()
{
	itemTypeLine = new QLineEdit;
	priceLine = new QLineEdit;
	infoLine = new QLineEdit;


	buttonBox = nullptr;
	acceptDialog = false;
	createDialogComponenets();
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

void AddTransactionDialog::createDialogComponenets()
{
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

	QHBoxLayout infoLayout;
	QLabel infoLabel;
	infoLabel.setText("Addiotional Information");
	infoLayout.addWidget(&infoLabel);
	infoLayout.addWidget(infoLine);
	widgetLayout->addLayout(&infoLayout);

	buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
	widgetLayout->addWidget(buttonBox);

	connect(buttonBox, SIGNAL(accepted()), this, SLOT(pressedOk()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(pressedCancel()));

	this->exec();
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
	itemDetails_ = infoLine->text().toStdString();
}

std::list<std::string> AddTransactionDialog::getAllTransactionData()
{
	std::list<std::string> itemList;
	if(acceptDialog) {
		itemList.push_back(itemTypeLine->text().toStdString());
		itemList.push_back(priceLine->text().toStdString());
		itemList.push_back(infoLine->text().toStdString());
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
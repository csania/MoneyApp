#pragma once

#include <QtWidgets\QDialog>

class QDialogButtonBox;
class QLineEdit;
class QPlainTextEdit;
class Person;

class AddTransactionDialog : public QDialog
{
	Q_OBJECT
public:
	AddTransactionDialog();
	~AddTransactionDialog();

	void setDialogValues();
	void createDialogComponenets(std::vector<Person*> &listOfPeople);
	bool getAcceptedDialog();

	std::string getItemType();
	std::string getItemPrice();
	std::string getItemDetails();

	Person* findPersonByName(std::string name);

	std::list<std::string> getAllTransactionData();

private:
	QLineEdit* itemTypeLine;
	QLineEdit* priceLine;
	QPlainTextEdit* infoLine;
	QDialogButtonBox* buttonBox;

	bool acceptDialog;
	std::string itemType_;
	std::string itemPrice_;
	std::string itemDetails_;
	std::vector<Person*> locallistOfPeople;

signals:
	void peopleClicked();
	
private slots:
	void pressedOk();
	void pressedCancel();
	void clickedOnPeople();
};


#pragma once

#include <QtWidgets\QDialog>

class QDialogButtonBox;
class QLineEdit;

class AddTransactionDialog : public QDialog
{
	Q_OBJECT
public:
	AddTransactionDialog();
	~AddTransactionDialog();

	void setDialogValues();
	bool getAcceptedDialog();

	std::string getItemType();
	std::string getItemPrice();
	std::string getItemDetails();

	std::list<std::string> getAllTransactionData();

private:
	QLineEdit* itemTypeLine;
	QLineEdit* priceLine;
	QLineEdit* infoLine;
	QDialogButtonBox* buttonBox;

	void createDialogComponenets();

	bool acceptDialog;
	std::string itemType_;
	std::string itemPrice_;
	std::string itemDetails_;
	
private slots:
	void pressedOk();
	void pressedCancel();
};


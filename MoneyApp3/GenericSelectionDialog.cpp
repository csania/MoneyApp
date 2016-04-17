#include "GenericSelectionDialog.h"
#include "person.h"
#include <string>

#include <QtWidgets\QVBoxLayout>
#include <QtWidgets\qcheckbox.h>
#include <QtWidgets\QLabel>
#include <QtWidgets\qlineedit.h>
#include <QtWidgets\qpushbutton.h>

GenericSelectionDialog::GenericSelectionDialog()
{
	genericDialog = new QDialog(this);
}


GenericSelectionDialog::~GenericSelectionDialog()
{
	if(genericDialog) {
		delete genericDialog;
		genericDialog = nullptr;
	}
	/*genericDialog->close();
	this will have to be linked up with ok/cancel buttons in slots
	*/
}

void GenericSelectionDialog::choosePeopleDialog(const std::vector<Person*> peopleList)
{
	if(peopleList.size() > 0) {
		QVBoxLayout* widgetLayout = new QVBoxLayout;
		genericDialog->setLayout(widgetLayout);

		QPushButton *okButton = new QPushButton();
		okButton->setText("Ok");

		for(auto it = peopleList.begin(); it != peopleList.end(); ++it) {

			QHBoxLayout *nameLayout = new QHBoxLayout;
			QLineEdit *priceTag = new QLineEdit;
			QCheckBox *cBox = new QCheckBox;
			cBox->setText(QString::fromStdString((*it)->getPersonName()));

			nameLayout->addWidget(cBox);
			nameLayout->addWidget(priceTag);
			widgetLayout->addLayout(nameLayout);

			checkBoxList.push_back(cBox);
			lineEditList.push_back(priceTag);
			priceTag->hide();

			connect(cBox, SIGNAL(stateChanged(int)), this, SLOT(checked(int)));
		}

		connect(okButton, SIGNAL(clicked()), this, SLOT(okPressed()));
		widgetLayout->addWidget(okButton);
		genericDialog->exec();
	}
}

void GenericSelectionDialog::checked(int state)
{
	checkedBoxes.clear();
	int counter = 0;
	for(auto it = checkBoxList.begin(); it != checkBoxList.end(); ++it) {
		if((*it)->isChecked()) {
			checkedBoxes.push_back(counter);
		}
		++counter;
	}

	if(checkedBoxes.size() > 1) {
		for(auto itr = checkedBoxes.begin(); itr != checkedBoxes.end(); ++itr) {
			lineEditList[(*itr)]->show();
		}
	}
	else {
		for(auto it = lineEditList.begin(); it != lineEditList.end(); ++it) {
			(*it)->hide();
		}
	}
}
std::string GenericSelectionDialog::getCheckedPersonName(int index)
{
	return checkBoxList[index]->text().toStdString();
}

float GenericSelectionDialog::getAmmountPaid(int index)
{
	return std::stof(lineEditList[index]->text().toStdString());
}

std::vector<int> GenericSelectionDialog::getCheckedBoxes()
{
	return checkedBoxes;
}

void GenericSelectionDialog::okPressed()
{
	genericDialog->close();
}
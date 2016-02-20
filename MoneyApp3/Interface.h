#pragma once

#include <QtWidgets\qwidget>
#include <list>

class Session;
class QListWidget;
class QHBoxLayout;
class QWidget;
class QToolButton;

class Interface : public QWidget
{
	Q_OBJECT
public:
	Interface(Session *session);

private:
	Session* thisSession;
	QListWidget *transactionData;
	QToolButton* peopleButton;

	void createButtonsLayout(QHBoxLayout *buttonsLayout);
	void createPeopleWidget();
	void populatePeopleWidget(std::string newName = "");

private slots:

	void addTransaction();
	void addPersonToSession();

};


#pragma once

#include <QtWidgets\qwidget>
#include <list>

class Session;
class QListWidget;
class QHBoxLayout;
class QVBoxLayout;
class QWidget;
class QDialog;

class Interface : public QWidget
{
	Q_OBJECT
public:
	Interface(Session *session);

private:
	Session* thisSession;
	QListWidget *transactionData;
	QDialog* addTransactionWidget;

	void createButtonsLayout(QHBoxLayout *buttonsLayout);

private slots:

	void addTransaction();

};


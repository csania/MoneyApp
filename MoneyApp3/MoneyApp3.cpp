//#include "stdafx.h"

#include "Session.h"
#include "Interface.h"

#include <QtWidgets\qapplication.h>


int main(int argc, char* argv[])
{
	Session *currentSession = new Session;

	QApplication app(argc, argv);

	Interface visualDesigner(currentSession);
	visualDesigner.show();

	return app.exec();

}

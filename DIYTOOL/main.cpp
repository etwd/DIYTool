#include "diytool.h"
#include <QtWidgets/QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QFile qssfile("diytool.css");
	qssfile.open(QFile::ReadOnly);
	if (qssfile.isOpen())
	{
		QString qss = QLatin1String(qssfile.readAll());
		qApp->setStyleSheet(qss);
	}
	DIYTOOL w;
	w.show();
	return a.exec();
}

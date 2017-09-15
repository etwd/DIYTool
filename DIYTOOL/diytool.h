#ifndef DIYTOOL_H
#define DIYTOOL_H

#include <QtWidgets/QMainWindow>
#include <QTimer>
#include "ui_diytool.h"
#include "MsgBox.h"
#include "BaseWidget.h"

#define REMINDTIME 1000*60*45

class DIYTOOL : public QMainWindow
{
	Q_OBJECT

public:
	DIYTOOL(QWidget *parent = 0);
	~DIYTOOL();

protected slots:
	void btnTimeTaskSlot();
	void btnTestQmlSlot();
	void taskTimerSlot();
	void windowMin();
	void windowClose();

protected:
	void mouseMoveEvent(QMouseEvent * event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void keyPressEvent(QKeyEvent *event);

private:
	void init();
	void sysConnect();
	void getScreenInfo();

private:
	Ui::DIYTOOLClass		ui;
	MsgBox					msgBox;
	QTimer					*taskTimer;
	QPoint					m_mousePoint;			//鼠标拖动自定义标题栏时的坐标
	bool					m_bmousePressed;			//鼠标是否按下
	int						screenX;
	int						screenY;
};

#endif // DIYTOOL_H

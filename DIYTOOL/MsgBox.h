#pragma once
#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include "BaseWidget.h"
#include "ui_MsgBox.h"

class MsgBox :	public BaseWidget
{
	Q_OBJECT
public:
	MsgBox(QWidget *parent = 0);
	~MsgBox(void);
	void setTips(QString tip);
	void setWndPosition(int x, int y);
	void setBtnorLabShow(bool,QString);

protected slots:
	void btnOKSlot();

private:
	Ui::Form_MsgBox		ui;
	QPoint m_mousePoint;			//鼠标拖动自定义标题栏时的坐标
	bool m_bmousePressed;			//鼠标是否按下
};


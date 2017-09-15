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
	QPoint m_mousePoint;			//����϶��Զ��������ʱ������
	bool m_bmousePressed;			//����Ƿ���
};


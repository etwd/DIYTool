#include "MsgBox.h"
#include <QDebug>
MsgBox::MsgBox(QWidget *parent):BaseWidget()
{
	ui.setupUi(this);	
	setWindowFlags(Qt::FramelessWindowHint);
	setBtnorLabShow(false,NULL);
}


MsgBox::~MsgBox(void)
{
}

void MsgBox::btnOKSlot()
{
	this->close();
}

void MsgBox::setTips( QString tip )
{
	ui.label_tips->setText(tip);
	ui.label_tips->setAlignment(Qt::AlignCenter);
}

void MsgBox::setWndPosition( int x, int y )
{
	this->setGeometry(x - this->width(),y - this->height(),this->width(),this->height());
}

void MsgBox::setBtnorLabShow( bool flag,QString tips)
{
	if (flag)
	{
		ui.pushButton_ok->hide();
		ui.label_tips_2->show();
		ui.label_tips_2->setText(tips);
		ui.label_tips_2->setAlignment(Qt::AlignCenter);
	}
	else
	{
		ui.label_tips_2->hide();
	}
}

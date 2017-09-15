#include "diytool.h"
#include <QQmlContext>
#include <QQuickView>
#include <QDesktopWidget>
#include <QDebug>

DIYTOOL::DIYTOOL(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	init();
	getScreenInfo();
	sysConnect();
}

DIYTOOL::~DIYTOOL()
{

}

void DIYTOOL::init()
{
	taskTimer = new QTimer(this);
}

void DIYTOOL::sysConnect()
{
	connect(taskTimer, SIGNAL(timeout()), this, SLOT(taskTimerSlot()));
}

void DIYTOOL::btnTimeTaskSlot()
{
	QString str = ui.btn_timeTask->text();
	if (str.contains(QStringLiteral("启动定时弹框")))
	{
		taskTimer->start(REMINDTIME);
		ui.btn_timeTask->setText(QStringLiteral("取消定时弹框"));
		this->showMinimized();
	} 
	else
	{
		taskTimer->stop();
		ui.btn_timeTask->setText(QStringLiteral("启动定时弹框"));		
	}
	
}

void DIYTOOL::taskTimerSlot()
{
	msgBox.setTips("think for a while");
	msgBox.setWndPosition(screenX,screenY);
	msgBox.show();
}

void DIYTOOL::windowMin()
{
	this->showMinimized();
}

void DIYTOOL::windowClose()
{
	this->close();
}

void DIYTOOL::btnTestQmlSlot()
{
	QQuickView* view = new QQuickView();
	view->rootContext()->setContextProperty("_controller", this);
	view->setSource(QUrl("test.qml"));
	view->show();
}

void DIYTOOL::mouseMoveEvent( QMouseEvent * event )
{
	if (m_bmousePressed &&( event->buttons() && Qt::LeftButton))
	{
		this->move(event->globalPos() - m_mousePoint);
		event->accept();
	}
}

void DIYTOOL::mousePressEvent( QMouseEvent *event )
{
	if (event->button() == Qt::LeftButton)
	{
		m_bmousePressed =  true;
		m_mousePoint = event->globalPos() - this->pos();
		event->accept();
	}

}

void DIYTOOL::mouseReleaseEvent( QMouseEvent *event )
{
	m_bmousePressed = false;
}

void DIYTOOL::keyPressEvent( QKeyEvent *event )
{
	switch(event->key())
	{
	case Qt::Key_Escape:
		this->close();
		break;
	default:
		QWidget::keyPressEvent(event);
	}
}

void DIYTOOL::getScreenInfo()
{
	QDesktopWidget *desktopWidget = QApplication::desktop();
	QRect deskRect = desktopWidget->availableGeometry();
	QRect screenRect = desktopWidget->screenGeometry();
	screenX = deskRect.width();
	screenY = deskRect.height();
	qDebug()<<deskRect.width()<<deskRect.height();
	qDebug()<<screenRect.width()<<screenRect.height();
}

#include "BaseWidget.h"


BaseWidget::BaseWidget():QWidget() 
{
	m_bmousePressed = false;
}


BaseWidget::~BaseWidget()
{
}

void BaseWidget::mouseMoveEvent( QMouseEvent * event )
{
	if (m_bmousePressed &&( event->buttons() && Qt::LeftButton))
	{
		this->move(event->globalPos() - m_mousePoint);
		event->accept();
	}
}

void BaseWidget::mousePressEvent( QMouseEvent *event )
{
	if (event->button() == Qt::LeftButton)
	{
		m_bmousePressed =  true;
		m_mousePoint = event->globalPos() - this->pos();
		event->accept();
	}
	
}

void BaseWidget::mouseReleaseEvent( QMouseEvent *event )
{
	m_bmousePressed = false;
}

void BaseWidget::keyPressEvent( QKeyEvent *event )
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



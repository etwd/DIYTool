#pragma once
#include <QWidget>
#include <QMouseEvent>
class BaseWidget :	public QWidget
{
	Q_OBJECT
public:
	BaseWidget();
	virtual ~BaseWidget();

protected:
	void mouseMoveEvent(QMouseEvent * event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void keyPressEvent(QKeyEvent *event);


protected:
	QPoint m_mousePoint;			//鼠标拖动自定义标题栏时的坐标
	bool m_bmousePressed;			//鼠标是否按下

};


#include "delegate.h"
#include <QStyle>
#include <QMessageBox>

//静态成员变量需要在程序代码中进行实例化，分配空间

Delegate::Delegate(QObject *parent)
	: QItemDelegate(parent),
	m_OperDirButton(new QPushButton())
{
	//设置按钮样式
	m_OperDirButton->setStyleSheet("");
}

void Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option, 
	const QModelIndex &index) const
{
	QPair<QStyleOptionButton*, QStyleOptionButton*>* buttons = m_btns.value(index);
	if (!buttons)
	{
		QStyleOptionButton* button1 = new QStyleOptionButton();
		button1->text = ("open dir");
		button1->state |= QStyle::State_Enabled;

		QStyleOptionButton* button2 = new QStyleOptionButton();
		button2->text = ("open file");
		button2->state |= QStyle::State_Enabled;

		buttons = new QPair<QStyleOptionButton *, QStyleOptionButton *>(button1, button2);
		(const_cast<Delegate *>(this))->m_btns.insert(index, buttons);
	}

	//调整大小
	buttons->first->rect = option.rect.adjusted(4, 4, -(option.rect.width() + 4), -4);
	buttons->second->rect = option.rect.adjusted((buttons->first->rect.width() + 4), 4, -4, -4);

	painter->save();
	if (option.state & QStyle::State_Selected)
	{
		painter->fillRect(option.rect, option.palette.highlight());
	}
	painter->restore();

	//QWidget pwidget = (i == 0) ? m_OperDirButton.data() : m_OperFileButton.data();
	//当按钮QSS效果放入无效时，可以尝试：pWidget->style()->drawControl() 代替
	//	QApplication::style()
	QApplication::style()->drawControl(QStyle::CE_PushButton, buttons->first, 
		painter, m_OperDirButton.data());
	QApplication::style()->drawControl(QStyle::CE_PushButton, buttons->second,
		painter, m_OperDirButton.data());
}

bool Delegate::editorEvent(QEvent *evnet, QAbstractItemModel *model,
	const QStyleOptionViewItem &option, const QModelIndex &index)
{
	if (event->type() == QEvent::MouseButtonPress) {

		QMouseEvent* e = (QMouseEvent*)event;

		if (m_btns.contains(index)) 
		{
			if (e->button() == Qt::LeftButton)
			{
				QPair<QStyleOptionButton*, QStyleOptionButton*>* btns = m_btns.value(index);
				if (btns->first->rect.contains(e->x(), e->y())) {
					btns->first->state |= QStyle::State_Sunken;
				}
				else if (btns->second->rect.contains(e->x(), e->y())) {
					btns->second->state |= QStyle::State_Sunken;
				}
			}
		}
	}

	if (event->type() == QEvent::MouseButtonRelease) {
		QMouseEvent* e = (QMouseEvent*)event;

		if (m_btns.contains(index)) {
			if (e->button() == Qt::LeftButton)
			{
				QPair<QStyleOptionButton*, QStyleOptionButton*>* btns = m_btns.value(index);
				if (btns->first->rect.contains(e->x(), e->y())) {
					btns->first->state &= (~QStyle::State_Sunken);
					showMsg(tr("btn1 column %1").arg(index.column()));
				}
				else if (btns->second->rect.contains(e->x(), e->y())) {
					btns->second->state &= (~QStyle::State_Sunken);
					showMsg(tr("btn2 row %1").arg(index.row()));
				}
			}
		}
	}
	return true;
}

void Delegate::showMsg(QString str)
{
	QMessageBox msg;
	msg.setText(str);
	msg.exec();
}


Delegate::~Delegate(void)
{

}
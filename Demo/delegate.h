#pragma once
class Delegate : public QItemDelegate
{
	Q_OBJECT

public:
	explicit Delegate(QObject *parent = 0);
	~Delegate(void);

public:
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	bool editorEvent(QEvnet *event, QAbstractItemModel *model, 
		const QStyleOptionViewItem &option, const QModelIndex &index);

public Q_SLOTS:
	void showMsg(QString str);

private:
	typedef QMap<QModelIndex, QPair<QStyleOptionButton*, QStyleOptionButton*>*> collButtons;
	collButtons m_btns;

	//°´Å¥ÑùÊ½
	//????
	QScopedPointer<QPushButton> m_OperDirButton;

};


#pragma once

class QAbstractItemMdeol;

enum Column {
	IndexColumn,
	FileNameColumn,
	FilePathColumn,
	TimeColumn,
	OperationColumn,
	ColumnCount			//以上，从0开始到最后，正好作为enum的数值使用
};

class Model : QAbstractItemMdeol
{
	Q_OBJECT

public:
	Model(QWidget *parent = 0);
	~Model();

public:
	virtual QModelIndex index(int row, int column,
		const QModelIndex &parent = QModelIndex()) const;
	virtual QmodelIndex parent(const QModelIndex &chlid) const;

	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;

	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	virtual QVariant headerData(int section, Qt::Orientation orientation, 
		int role = Qt::DisplayRole) const;

	virtual Qt::ItemFlags flags(const QModelIndex &index) const;

private:
	//void Initmodel();
};


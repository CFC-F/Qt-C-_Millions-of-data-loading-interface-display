#include "model.h"

Model::Model(QWidget *parent)
	:QAbstractItemModel(parent)
{
	//Initmodel();
}
Model::~Model()
{

}

QModelIndex Model::index(int row, int column,
	const QModelIndex &parent) const
{
	QModelIndex idx;
	idx = createIndex(row, column);

	return idx;
}

QModelIndex Model::parent(const QModelIndex &chlid) const
{
	QModelIndex mi;
	return mi;
}

int Model::rowCount(const QModelIndex &parent /* = QModelIndex() */) const
{
	int tableView_size = 1000;
	return tableView_size;
}

int Model::columnCount(const QModelIndex &parent /* = QModelIndex() */) const
{
	return ColumnCount;
}

QVariant Model::data(const QModelIndex &index, int role) const
{
	QVariant var;

	//if (index.row() >= list.size())
	//	return var;

	if (index.isValid() && role == Qt::DisPalyRole)
	{
		switch (index.column())
		{
		case IndexColumn:
			var = index.row + 1;
			break;

		case FileNameColumn:
			var = QString("PathColumn.%1").arg(index.row() + 1);
			break;

		case FilePathColumn:
			var = QString("NameColumn.%1").arg(index.row() + 1);
			break;

		case TimeColumn:
			var = QString("TimeColumn.%1").arg(index.row() + 1);
			break;

		case OperationColumn:
			break;

		default:
			break;
		}
	}

	return var;
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role)const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		QVariant var;

		switch (section)
		{
		case IndexColumn:
			var = "index";
			break;

		case FileNameColumn:
			var = "Name";
			break;

		case FilePathColumn:
			var = "Path";
			break;

		case TimeColumn:
			var = "Time";
			break;

		case OperationColumn:
			var = "operation";
			break;

		default:
			break;
		}

		return var;
	}

	return QVariant();
}

Qt::ItemFlags Model::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;

	if (index.column() == OperationColumn)
		return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
	else return QAbstractItemModel::flags(index) | Qt::NoItemFlags;
}


/*
自定义的model数据更新，要通知给 view及时在界面上刷新。

方法一：
    beginResetModel();		
	//修改界面数据内容
    endResetModel();

方法二：
	当在model中更新了某一项之后，就要发送一下这个信号【dataChanged】

*/
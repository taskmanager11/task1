#include "taskmodel.h"

TaskModel::TaskModel()
{
}

QModelIndex TaskModel::index(int row, int column, const QModelIndex & parent) const
{
    return this->createIndex(row, column);
}

QModelIndex TaskModel::parent(const QModelIndex & index) const
{
    return QModelIndex();
}

int TaskModel::rowCount(const QModelIndex & parent) const
{
    if (!parent.isValid()) {
        return this->tasks.count();
    }

    return 0;
}

int TaskModel::columnCount(const QModelIndex & parent) const
{
    return 3;
}

QVariant TaskModel::data(const QModelIndex & index, int role) const
{
    if (index.isValid() && role == Qt::DisplayRole) {
        if (index.column() == 0) {
            return this->tasks.at(index.row())->title;
        }
        return QString("test");
    }

    return QVariant();
}

void TaskModel::addTaskEntity(CTask_Entity *task)
{
    int rowNum = this->tasks.count();
    beginInsertRows(QModelIndex(), rowNum, rowNum);
    this->tasks.append(task);
    endInsertRows();
}

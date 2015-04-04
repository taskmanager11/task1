#include "taskmodel.h"
#include <QStringList>

TaskModel::TaskModel()
{
    this->setHeaderData(1,Qt::Horizontal,QString::fromUtf8("Task"));
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
    return 4;
}
QVariant TaskModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return ("State");

            case 1:
                return ("Task");
            case 2:
                return ("Details");
               case 3:
            return ("Persent");

            default:
                return QVariant();
        }
    }
    return QVariant();
}

QVariant TaskModel::data(const QModelIndex & index, int role) const
{ if(index.isValid() && role == Qt::DisplayRole)

        switch  (index.column()) {
        case 0:
            return this->tasks.at(index.row())->getState();

        case 1:
            return this->tasks.at(index.row())->getTitle();

        case 2:

        return this->tasks.at(index.row())->getDetail();

        case 3:
            return this->tasks.at(index.row())->getPercent();
        default:
            return QString("test");
            break;
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

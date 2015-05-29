#include "taskmodel.h"
#include <QStringList>
#include <QTableView>

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
            return ("Percent");

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

CTask_Entity *TaskModel::getTaskEntity(QModelIndex &index)
{
 return this->tasks.at(index.row());

}

void TaskModel::removeTaskEntity(QModelIndex index)
{
            int row = index.row();
            beginRemoveRows(QModelIndex(),row,row);
            CTask_Entity *C = this->tasks.takeAt(row);
            delete(C);
            endRemoveRows();
}
//void TaskModel::editEntry()
//{
//    QTableView *temp = static_cast<QTableView*>(currentWidget());
//   QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
//   QItemSelectionModel *selectionModel = temp->selectionModel();

//    QModelIndexList indexes = selectionModel->selectedRows();
//    QString name;
//    QString address;
//    int row = -1;

//    foreach (QModelIndex index, indexes) {
//        row = proxy->mapToSource(index).row();
//        QModelIndex nameIndex = table->index(row, 0, QModelIndex());
//        QVariant varName = table->data(nameIndex, Qt::DisplayRole);
//        name = varName.toString();

//        QModelIndex addressIndex = table->index(row, 1, QModelIndex());
//        QVariant varAddr = table->data(addressIndex, Qt::DisplayRole);
//        address = varAddr.toString();
//    }
//}

void TaskModel::updateTaskEntity(QModelIndex index, CTask_Entity *entity)
{
    int row = index.row();
    this->tasks.replace(row, entity);
}

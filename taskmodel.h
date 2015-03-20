#ifndef TASKMODEL_H
#define TASKMODEL_H

#include <QAbstractItemModel>
#include "Task_entity.h"

class TaskModel : public QAbstractItemModel
{
public:
    TaskModel();

    QModelIndex index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex & index) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    int columnCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    void addTaskEntity(CTask_Entity *task);

protected:
    QList<CTask_Entity *> tasks;
};

#endif // TASKMODEL_H

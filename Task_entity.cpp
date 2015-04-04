#include "Task_entity.h"

quint8 CTask_Entity::getPercent()
{
    return this->percent;
}

void CTask_Entity::setPercent(quint8 p)
{
    this->percent = p;
}

QString CTask_Entity::getTitle()
{
    return this->title;
}

void CTask_Entity::setTitle(QString t)
{
    this->title = t;
}

QString CTask_Entity::getState()
{
    return this->state;
}

void CTask_Entity::setState(QString s)
{
    this->state = s;
}

QString CTask_Entity::getDetail()
{
    return this->detail;
}

void CTask_Entity::setDetail(QString d)
{
    this->detail = d;
}

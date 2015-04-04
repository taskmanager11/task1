#ifndef TASK_ENTITY_H
#define TASK_ENTITY_H
#include <QString>

 class CTask_Entity{
  protected:
     quint8 percent;
     QString title;
     QString state;
     QString detail;


  public:
     CTask_Entity()
  {}
     quint8 getPercent();
     void setPercent(quint8);
     QString getTitle();
     void setTitle(QString);
     QString getState();
     void setState(QString);
     QString getDetail();
     void setDetail(QString);


 };



#endif // TASK_ENTITY_H

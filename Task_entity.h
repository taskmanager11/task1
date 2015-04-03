#ifndef TASK_ENTITY_H
#define TASK_ENTITY_H

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


 };



#endif // TASK_ENTITY_H

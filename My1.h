#ifndef My1_H
#define My1_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QSlider>
#include  <QRadioButton>
#include "Task_entity.h"

class My1: public QDialog
{
    Q_OBJECT
public:
    My1(QWidget *parent=0);

    void setTask(CTask_Entity *);
    void resetTask();
    CTask_Entity *task();

    int exec();

private:
    QLabel *lbl;
    QLabel *lbl2;
    QLineEdit *line;
     QLineEdit *text2;
      QPushButton *ok;
      QRadioButton *galochka1;
      QRadioButton *galochka2;
      QRadioButton *galochka3;
    QPushButton *close;
    QSpinBox *vaga;
    QSlider *slid;

    CTask_Entity *m_task;
private slots:
    void okCl();
    void TextChanged(QString str);

public slots:
    void AddEntity();
    void EditEntity(CTask_Entity*);


signals:
    void taskSaved(CTask_Entity*);
};


#endif // My1_H

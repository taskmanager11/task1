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
private slots:
    void okCl();
    void TextChanged(QString str);


signals:
    void taskSaved(CTask_Entity*);
};


#endif // My1_H

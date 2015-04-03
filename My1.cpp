#include "My1.h"

My1::My1(QWidget *parent) : QDialog(parent)
{
    lbl = new QLabel("&Task");
    line =new QLineEdit;
     lbl->setBuddy(line);
     lbl2 = new QLabel("&Details");
     text2 =new QLineEdit;
     lbl2->setBuddy(text2);
    galochka1= new QRadioButton("Well done!");
     galochka2= new QRadioButton("I`m doing");
      galochka3= new QRadioButton("Do it");
  ok = new QPushButton("Ok");
    ok->setDefault(true);
    ok->setEnabled(false);
    close = new QPushButton("&Close");
    vaga =new QSpinBox;
    slid =new QSlider(Qt::Horizontal);
    vaga->setMaximum(100);
    slid->setMaximum(100);
    QObject::connect(vaga, SIGNAL(valueChanged(int)), slid, SLOT(setValue(int)));
    QObject::connect(slid, SIGNAL(valueChanged(int)), vaga, SLOT(setValue(int)));

    QVBoxLayout *lay =new QVBoxLayout;
   lay->addWidget(galochka1);
   lay->addWidget(galochka2);
   lay->addWidget(galochka3);

   QVBoxLayout *layout5 =new QVBoxLayout;
   layout5->addWidget(lbl);
   layout5->addWidget(lbl2);

    QVBoxLayout *l =new QVBoxLayout;
    l->addWidget(line);
    l->addWidget(text2);

 QHBoxLayout *layout =new QHBoxLayout;
 layout->addLayout(lay);
 layout->addLayout(layout5);
 layout->addLayout(l);
 layout->addWidget(vaga);


 QVBoxLayout *layout2 =new QVBoxLayout;
 layout2->addWidget(slid);
 layout2->addWidget(ok);
 layout2->addWidget(close);

 QHBoxLayout *layout3 =new QHBoxLayout;
 layout3->addLayout(layout);
 layout3->addLayout(layout2);

 connect(line, SIGNAL(textChanged(QString)), this, SLOT(TextChanged(QString)));
 connect(text2, SIGNAL(textChanged(QString)), this, SLOT(TextChanged(QString)));
connect(close, SIGNAL(clicked()), SLOT(close()));
 setLayout(layout3);

 connect(ok, SIGNAL(clicked()), this, SLOT(okCl()));

  setWindowTitle("Add Task");
}



void My1::TextChanged(QString str)
{
    ok->setEnabled(!str.isEmpty());
}

void My1::okCl()
{
    CTask_Entity *task= new CTask_Entity;
    task->setPercent(vaga->value());
    if(galochka1->isChecked())
    {task->state="Well done!"; }
    else if(galochka2->isChecked())
    {task->state="I`m doing it!"; }
    else if(galochka3->isChecked())
    {task->state="Do it!"; }
    task->title=line->text();
    CTask_Entity *text=new CTask_Entity;
    text->title=line->text();
    task->detail=text2->text();
    emit taskSaved(task);
    CTask_Entity *details=new CTask_Entity;
    text->detail=text2->text();
    CTask_Entity *stan=new CTask_Entity;
    stan->state=slid->value();
}

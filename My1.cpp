#include "My1.h"

My1::My1(QWidget *parent) : QDialog(parent)
{
    lbl = new QLabel("&Enter");
    line =new QLineEdit;
     lbl->setBuddy(line);
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

 QHBoxLayout *layout =new QHBoxLayout;
 layout->addLayout(lay);
 layout->addWidget(lbl);
 layout->addWidget(line);
 layout->addWidget(vaga);


 QVBoxLayout *layout2 =new QVBoxLayout;
 layout2->addWidget(slid);
 layout2->addWidget(ok);
 layout2->addWidget(close);

 QHBoxLayout *layout3 =new QHBoxLayout;
 layout3->addLayout(layout);
 layout3->addLayout(layout2);

 connect(line, SIGNAL(textChanged(QString)), this, SLOT(TextChanged(QString)));
connect(close, SIGNAL(clicked()), SLOT(close()));
 setLayout(layout3);

 connect(ok, SIGNAL(clicked()), this, SLOT(okCl()));


}



void My1::TextChanged(QString str)
{
    ok->setEnabled(!str.isEmpty());
}
void My1::okCl()
{
CTask_Entity *task= new CTask_Entity;
task->percent=vaga->value();
if(galochka1->isChecked())
{task->state="done"; }
else if(galochka2->isChecked())
{task->state="doing"; }
else if(galochka3->isChecked())
{task->state="do_it"; }
task->title=line->text();
emit taskSaved(task);
}

#include "My1.h"

My1::My1(QWidget *parent) : QDialog(parent)
{
    m_task = NULL;

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
connect(close, SIGNAL(clicked()), SLOT(reject()));
 setLayout(layout3);

 connect(ok, SIGNAL(clicked()), this, SLOT(okCl()));

  setWindowTitle("Add Task");
}

void My1::AddEntity()
{
    m_task = NULL;
    this->exec();
}

void My1::EditEntity(CTask_Entity *entity)
{
    m_task = entity;

    line->setText(entity->getTitle());
    text2->setText(entity->getDetail());
    slid->setValue(entity->getPercent());
    galochka1->setChecked(entity->getState() == "Well done!");
    galochka2->setChecked(entity->getState() == "I`m doing it!");
    galochka3->setChecked(entity->getState() == "Do it!");

    this->exec();
}

void My1::TextChanged(QString str)
{
    ok->setEnabled(!str.isEmpty());
}

void My1::okCl()
{
    m_task->setPercent(vaga->value());
    if(galochka1->isChecked())
    {m_task->setState("Well done!"); }
    else if(galochka2->isChecked())
    {m_task->setState("I`m doing it!"); }
    else if(galochka3->isChecked())
    {m_task->setState("Do it!"); }
    m_task->setTitle(line->text());
    CTask_Entity *text=new CTask_Entity;
    text->setTitle(line->text());
    m_task->setDetail(text2->text());
    this->accept();
//    emit taskSaved(task);
//    CTask_Entity *details=new CTask_Entity;
//    text->setDetail(text2->text());
   /*CTask_Entity *stan=new CTask_Entity;
    stan-> setState ( slid->value());*/
}

void My1::setTask(CTask_Entity *entity)
{
    m_task = entity;
}

void My1::resetTask()
{
    m_task = new CTask_Entity();
}

CTask_Entity *My1::task()
{
    return m_task;
}

int My1::exec() {
    if (m_task) {
        line->setText(m_task->getTitle());
        text2->setText(m_task->getDetail());
        slid->setValue(m_task->getPercent());
        galochka1->setChecked(m_task->getState() == "Well done!");
        galochka2->setChecked(m_task->getState() == "I`m doing it!");
        galochka3->setChecked(m_task->getState() == "Do it!");
    }

    QDialog::exec();
}

#include "My1.h"
#include <QApplication>
#include "mainwindow.h"
/*#include <QPushButton>
#include <QSpinBox>//Счетчик
#include <QSlider>
#include <QHBoxLayout>*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    My1 *window = new My1();

    MainWindow *window2=new MainWindow();

    QObject::connect(window2, SIGNAL(addInvoked()), window, SLOT(exec()));
    QObject::connect(window, SIGNAL(taskSaved(CTask_Entity*)), window2, SLOT(addTaskEntity(CTask_Entity*)));

    window2->show();

    return a.exec();
}

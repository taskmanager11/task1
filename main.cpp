#include "My1.h"
#include <QApplication>
/*#include <QPushButton>
#include <QSpinBox>//Счетчик
#include <QSlider>
#include <QHBoxLayout>*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    My1 *window = new My1();
    window->show();

    return a.exec();
}

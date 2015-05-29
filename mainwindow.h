#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "taskmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    TaskModel *model;

public slots:
//    void addTaskEntity(CTask_Entity *task);

private slots:
    //void on_pushButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

signals:
    void addInvoked();
    void editInvoked(CTask_Entity*);
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->model = new TaskModel();

    this->ui->tableView->setModel(this->model);
    setWindowTitle("Task Manager");
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_pushButton_clicked()
{

window->show();
}
*/

void MainWindow::on_pushButton_clicked()
{
    emit addInvoked();
}

void MainWindow::addTaskEntity(CTask_Entity *task)
{
    this->model->addTaskEntity(task);
}



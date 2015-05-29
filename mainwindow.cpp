#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "My1.h"
#include <QMessageBox>

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
//    emit addInvoked();
    My1 *dialog = new My1(this);
    dialog->setModal(true);
    dialog->resetTask();
    if (dialog->exec()) {
        this->model->addTaskEntity(dialog->task());
    }
}

//void MainWindow::addTaskEntity(CTask_Entity *task)
//{
//    this->model->addTaskEntity(task);
//}



void MainWindow::on_pushButton_3_clicked()
{
    QModelIndex index = ui->tableView->selectionModel()->currentIndex();

    if (!index.isValid()) {
        return;
    }
//    emit editInvoked(this->model->getTaskEntity(index));

    My1 *dialog = new My1(this);
    dialog->setModal(true);
    dialog->setTask(this->model->getTaskEntity(index));

    if (dialog->exec()) {

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if (QMessageBox::question(this, tr("Remove?"), tr("Remove?"), QMessageBox::Yes, QMessageBox::No) == QMessageBox::No) {
        return;
    }

    QModelIndex Index = ui->tableView->selectionModel()->currentIndex();
       if(Index.isValid())
       model->removeTaskEntity(Index);
}

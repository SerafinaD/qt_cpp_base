#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "qmath.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double a = ui->line_a->text().toDouble();
    double b = ui->line_b->text().toDouble();
    double c = ui->line_c->text().toDouble();
    double x1, x2, discr;

    if (a == 0)
    {
        if (b != 0)
        {
            x1 = -c / b;
            ui->line_x1->setText(QString::number(x1, 'f'));
        }
        else
        {
            ui->line_x1->setText("It's not an equation!");
        }
        ui->line_x2->setText("It's not quadratic");
        return ;
    }
    discr = qPow(b, 2) - 4 * a * c;
    if (discr >= 0)
    {
    x1 = (qPow(b, 2) + qSqrt(discr)) / (4 * a);
    x2 = (qPow(b, 2) - qSqrt(discr)) / (4 * a);
    ui->line_x1->setText(QString::number(x1, 'f'));
    ui->line_x2->setText(QString::number(x2, 'f'));
    }
    else
    {
        QString* res1 = new(QString);
        *res1 = QString::number(qPow(b,2) / (4 * a)) + " + i * " + QString::number(qSqrt(-discr) / (4 * a));
        ui->line_x1->setText(*res1);
        QString* res2 = new(QString);
        *res2 = QString::number(qPow(b,2) / (4 * a)) + " - i * " + QString::number(qSqrt(-discr) / (4 * a));
        ui->line_x2->setText(*res2);
        delete(res1);
        delete(res2);
    }
}

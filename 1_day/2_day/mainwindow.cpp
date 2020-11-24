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
    double alpha = ui->line_alpha->text().toDouble();

    if (!(ui->CheckisRad->isChecked()))
    {
        alpha = qDegreesToRadians(alpha);
    }
    ui->line_c->setText(QString::number(qSqrt(a * a + b * b - a * b * qCos(alpha))));
}

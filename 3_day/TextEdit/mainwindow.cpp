#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QTextStream>

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

void MainWindow::on_openButton_clicked()
{
    QString filter = "All (*)";
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "/home",  filter, &filter, QFileDialog::DontUseNativeDialog);
    if (filename.length())
    {
        int index = filename.indexOf(".txt");
        QFile file (filename);
        if ((index != -1) && (filename.length() - 4 == index) && file.open(QFile::ReadOnly))
        {
            QByteArray byteArray = file.readAll();
            ui->textEdit->setPlainText(tr(byteArray.data()));
            file.close();
        }
    }
}

void MainWindow::on_saveButton_clicked()
{
    QString filter = "All (*)";
    QString filename = QFileDialog::getSaveFileName(this, tr("Save file"), "/home", filter, &filter, QFileDialog::DontUseNativeDialog);
       if (filename.length() > 0)
       {
          QString ext = QString(&(filename.data()[filename.length() - 4]));
          if (ext == ".txt")
           {
               QFile file(filename);
               if (file.open(QFile::WriteOnly))
               {
                   QTextStream stream(&file);
                   stream << ui->textEdit->toPlainText();
                   file.close();
               }
           }
       }
}

void MainWindow::on_helpButton_clicked()
{
    Q_INIT_RESOURCE(rname);
    QString helpstring;
       QFile helpfile(":/help.txt");
       if (helpfile.open(QIODevice::ReadOnly))
       {
           QTextStream stream(&helpfile);
           helpstring = stream.readAll();
           helpfile.close();
       }
    QMessageBox *dialog = new QMessageBox;
    dialog->setWindowTitle("Dialog");
    dialog->setText(helpstring);
    dialog->show();
}

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QEvent>
#include <QKeyEvent>
#include <QObject>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    switchLanguage(QLocale::system().name());
    connect(ui->rusB, SIGNAL(clicked()), this, SLOT(clickSwitch()));
    connect(ui->enB, SIGNAL(clicked()), this, SLOT(clickSwitch()));
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
        if (ui->RDONLYchBox)
            ui->textEdit->setReadOnly(true);
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

void MainWindow::switchLanguage(QString language)
{
   translater.load("QtLanguage_" + language, ".");
   qApp->installTranslator(&translater);
   ui->retranslateUi(this);
   ui->rusB->setText("Русский");
   ui->enB->setText("English");
}

void MainWindow::clickSwitch()
{
   QObject *obj = sender(); // узнаём, от какого виджета пришел сигнал
   if (obj == ui->rusB)switchLanguage("ru");
   if (obj == ui->enB)switchLanguage("en");
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

void MainWindow::changeEvent(QEvent *event)
{
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->modifiers()==Qt::ControlModifier && event->key()==Qt::Key_O)
    {
        MainWindow::on_openButton_clicked();
    }
    if (event->modifiers()==Qt::ControlModifier && event->key()==Qt::Key_S)
    {
        MainWindow::on_saveButton_clicked();
    }
    if (event->modifiers()==Qt::ControlModifier && event->key()==Qt::Key_N)
    {
        ui->textEdit->setText("");
    }
    if (event->modifiers()==Qt::ControlModifier && event->key()==Qt::Key_Q)
    {
        qApp->quit();
    }
}

void MainWindow::on_enB_clicked()
{
}

void MainWindow::on_rusB_clicked()
{
}


void MainWindow::on_DarkRB_clicked()
{
    if(ui->DarkRB->isChecked())
         qApp->setStyleSheet("QPushButton{background-color: grey; color:white} QMainWindow{background-color:black; color:white} QRadioButton{color:white} QTextEdit{background-color:grey; color:white} QCheckBox{color:white}");
    else
         qApp->setStyleSheet("QPushButton{background-color: white; color:black} QMainWindow{background-color:grey; color:black} QRadioButton{color:black} QTextEdit{background-color:white; color:black} QCheckBox{color:black}");
}


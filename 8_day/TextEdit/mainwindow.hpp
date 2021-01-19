#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QMdiArea>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QTranslator>

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
    void changeEvent(QEvent * event) override;

    virtual void keyPressEvent(QKeyEvent *event);
private slots:
    void on_openButton_clicked();

    void on_saveButton_clicked();

    void on_helpButton_clicked();

    void clickSwitch();

    void on_enB_clicked();

    void on_rusB_clicked();

    void on_DarkRB_clicked();

    void on_printButton_clicked();

private:
    Ui::MainWindow *ui;
    QMdiArea *mdiArea;

    QTranslator translater;

    void switchLanguage(QString language);
};

#endif // MAINWINDOW_HPP

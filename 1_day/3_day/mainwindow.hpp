#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pButton_add_clicked();

    void on_pButton_replace_clicked();

    void on_pButton_html_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP

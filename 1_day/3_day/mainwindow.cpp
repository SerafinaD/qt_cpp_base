#include "mainwindow.hpp"
#include "ui_mainwindow.h"

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

void MainWindow::on_pButton_add_clicked()
{
    ui->pTextEdit_left->setPlainText(ui->pTextEdit_left->toPlainText() + ui->pTextEdit_right->toPlainText());
}

void MainWindow::on_pButton_replace_clicked()
{
    ui->pTextEdit_right->setPlainText(ui->pTextEdit_left->toPlainText());
}

void MainWindow::on_pButton_html_clicked()
{
    QTextEdit *html_te = new(QTextEdit);
    html_te->setHtml("<html>"
                     "<head>"
                         "<title>Example</title>"
                     "</head>"
                     "<hr>"
                     "<body>"
                     "<h1>document</h1>"
                     "<p><a name = \"backtable1\">the</a>"
                     "<a href = \"#table1\">table</a></p>"
                     "<p>.</p><p>.</p><p>.</p><p>.</p><p>.</p><p>.</p><p>.</p><p>.</p>"
                     "<p>.</p>"
                     "<p>Table</p>"
                     "<table box-sizing = border-box border-color = silver >"
                         "<caption text-align= center >"
                             "<a name = \"table1\">chartype</a>"
                             "</caption>"
                         "<tr display = table-row>"
                             "<td display= table-cell>character\type</td>"
                             "<td display= table-cell>yandere</td>"
                             "<td display= table-cell>tsundere</td>"
                             "<td display= table-cell>dandere</td>"
                         "</tr>"
                         "<tr display = table-row>"
                             "<td display= table-cell>Luisa</td>"
                             "<td display= table-cell>O</td>"
                             "<td display= table-cell>X</td>"
                             "<td display= table-cell>O</td>"
                         "</tr>"
                         "<tr display = table-row>"
                             "<td display = table-cell>Gasai</td>"
                             "<td display = table-cell>X</td>"
                             "<td display= table-cell>O</td>"
                             "<td display= table-cell>O</td>"
                         "</tr>"
                         "<tr display = table-row>"
                             "<td display= table-cell>Riel</td>"
                             "<td display= table-cell>O</td>"
                             "<td display= table-cell>O</td>"
                             "<td display= table-cell>X</td>"
                         "</tr>"
                     "</table>"
                     "</body>"
                 "</html>");
    ui->pTextEdit_right->setPlainText(html_te->toPlainText());
    delete(html_te);
}

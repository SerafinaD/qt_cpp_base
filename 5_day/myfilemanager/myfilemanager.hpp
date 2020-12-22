#ifndef MYFILEMANAGER_HPP
#define MYFILEMANAGER_HPP

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QTreeView>
#include <QComboBox>
#include <QPushButton>
#include <QStandardItemModel>
#include <QApplication>
#include <QFileInfo>

Q_PROPERTY(QStandardItemModel *model READ getCurrentModel WRITE setNewModel)

class myfilemanager : public QMainWindow
{
    Q_OBJECT
public:
    explicit myfilemanager(QWidget *parent = nullptr);
    void clearTree();
    QStandardItemModel *getCurrentModel()const
    {
        return model;
    }
       void setNewModel(QStandardItemModel *newmodel);
       void rebuildModel(QString str);
    private:
       QGridLayout *gridLay;
       QTreeView *tree;
       QPushButton *mainPath;
       QComboBox *disckSelBox;
    private slots:
       void chgDisk(int index);
       void goMainPath();
    private:
       QStandardItemModel *model;
       QString curretnPath;
    protected:
};

#endif // MYFILEMANAGER_HPP

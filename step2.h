#ifndef STEP2_H
#define STEP2_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QTableView>
#include <QtCore>
#include <QtGui>
#include <QtSql>

#include "enhancedsqltablemodel.h"

namespace Ui {
class Step2;
}

class Step2 : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Step2(QWidget *parent = 0);
    ~Step2();
    
private:
    Ui::Step2 *ui;
    QSqlDatabase dbContainer, testDbF, testDbS;
    EnhancedSqlTableModel *dbtFirstTab, *dbtSecondTab, *dbtCont;
//    QSqlQueryModel *dbtCont1, *dbtCont2;

private slots:
    void checkTableF(int row);
    void checkTableS(int row);

};

class TabView : public QTableView
{
    Q_OBJECT

public:
    explicit TabView(QWidget *parent = 0);
    ~TabView();

    void refresh();
private slots:
    void makeDrag(QModelIndex index);

protected:
    void dropEvent(QDropEvent *de);
    void dragMoveEvent(QDragMoveEvent *de);
    void dragEnterEvent(QDragEnterEvent *event);
};

#endif // STEP2_H

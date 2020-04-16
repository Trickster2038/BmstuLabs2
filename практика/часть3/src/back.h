#ifndef BACK_H_
#define BACK_H_
#include <QDialog>
#include <QLineEdit>
#include <QSignalMapper>
#include <QTextEdit>
#include <QString>
#include <QComboBox>
#include <QSpinBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPainter>

//#include "que.h"
/// Класс, реализующий редактор
class CDrawer : public QWidget {
 
  public:
    CDrawer(QWidget *parent = 0);
    //QPainter qp;

protected:
	void paintEvent(QPaintEvent *event);
};

class FormDialog: public QDialog
{
    Q_OBJECT
public:
    FormDialog( QWidget * parent = 0);
    virtual ~FormDialog(){};

protected:    
	int i1;
	CDrawer *drawer1;
	QTableWidget *table;
	QSpinBox *spin1,*spin2,*spin3;
	QComboBox *combo1;
    //QLineEdit *lineEdit1;
    //QTextEdit *field1;
    bool lower, isOut;

    
private slots:
    void adder();
    void i1refr(int x);
    void outer();
    void grapher();
//     void poper();
//     void sorter();
//     void outer();
};
#endif
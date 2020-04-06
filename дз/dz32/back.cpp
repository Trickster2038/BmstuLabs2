#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <iostream>
#include <QString>
#include <QFrame>
#include <QPoint>
#include <QTimer>
#include "back.h"
#include "drawer.h"
#include "que.h"

#include <QPainter>
using namespace std;

//void FormDialog::newQs(bool& outId);
//void FormDialog::swapper(bool& caseId, bool& outId);
CSmartQ qobj;
bool startb = true;
QTimer *timer1;

FormDialog::FormDialog(QWidget * parent){
	timer1 = new QTimer(this);
	QVBoxLayout *mainLayout = new QVBoxLayout();
	lineEdit1 = new QLineEdit();
	//QPainter painter1(this);
	QPushButton *button1 = new QPushButton("Push");
	QPushButton *button2 = new QPushButton("Pop");
	QPushButton *button3 = new QPushButton("Sort");
	QPushButton *button4 = new QPushButton("Out");
	CDrawer* drawer1 = new CDrawer(this);
	field1 = new QTextEdit();
	field1->setReadOnly(true);
	//QString str1;
	bool lower = true, isOut = false;
	
	// painter1.setWindow(5,5,300,300);
	// painter1.drawPoint(QPoint(5,5));
	// painter1.drawPoint(QPoint(5,300));
	// painter1.drawPoint(QPoint(300,5));
	// painter1.drawPoint(QPoint(300,300));

	connect(button1, SIGNAL(clicked()), this, SLOT(pusher()));
	connect(button2, SIGNAL(clicked()), this, SLOT(poper()));
	connect(button3, SIGNAL(clicked()), this, SLOT(sorter()));
	connect(button4, SIGNAL(clicked()), this, SLOT(repaint()));
	connect(timer1, SIGNAL(timeout()), this, SLOT(repaint()));
	//connect(lineEdit1, SIGNAL(textEdited(QString)), this, SLOT(newQs()));
	mainLayout->addWidget(lineEdit1);
	mainLayout->addWidget(drawer1);
	mainLayout->addWidget(button1);
	mainLayout->addWidget(button2);
	mainLayout->addWidget(button3);
	mainLayout->addWidget(button4);
	mainLayout->addWidget(field1);
	setLayout(mainLayout);
};

// void FormDialog::newQs(){
// 	//isOut = false;
// 	field1->setText("");
// 	field1->append("input: " + lineEdit1->text());
// };

void FormDialog::pusher(){
	if(startb)
	{
		timer1->start(150);
	}
	else{
		timer1->stop();
	}
	startb = !(startb);
};

void FormDialog::poper(){
	if(qobj.getlng()>0){
		qobj.rm();
	field1->append("last elem removed");
	}
	else{
		field1->append("queue is empty");
	}
};

void FormDialog::sorter(){
	qobj.sort();
	field1->append("sorted");
};

void FormDialog::outer(){
	qobj.reset();
	field1->setText("");
	field1->append("Queue:");
	for(int i=0; i < qobj.getlng(); i++){
		char *ch;
		*ch = qobj.gett();
		field1->append(QString::fromLocal8Bit(ch,1));
		//field1->append("^");
	}
};
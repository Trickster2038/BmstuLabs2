#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <iostream>
#include <QString>
#include "back.h"
#include "que.h"
using namespace std;

//void FormDialog::newQs(bool& outId);
//void FormDialog::swapper(bool& caseId, bool& outId);
CSmartQ qobj;

FormDialog::FormDialog(QWidget * parent){
	QVBoxLayout *mainLayout = new QVBoxLayout();
	lineEdit1 = new QLineEdit();
	QPushButton *button1 = new QPushButton("Push");
	QPushButton *button2 = new QPushButton("Pop");
	QPushButton *button3 = new QPushButton("Sort");
	QPushButton *button4 = new QPushButton("Out");
	field1 = new QTextEdit();
	field1->setReadOnly(true);
	//QString str1;
	bool lower = true, isOut = false;
	


	connect(button1, SIGNAL(clicked()), this, SLOT(pusher()));
	// connect(button2, SIGNAL(clicked()), this, SLOT(poper()));
	// connect(button3, SIGNAL(clicked()), this, SLOT(sorter()));
	// connect(button4, SIGNAL(clicked()), this, SLOT(outer()));
	//connect(lineEdit1, SIGNAL(textEdited(QString)), this, SLOT(newQs()));
	mainLayout->addWidget(lineEdit1);
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
	QString str = lineEdit1->text();
    QByteArray a= str.toUtf8(); // to....
    char* d=  a.data();
	qobj.add(*d);
};
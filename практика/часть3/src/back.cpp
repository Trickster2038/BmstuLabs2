#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <iostream>
#include <QString>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>
#include "back.h"
//#include "que.h"
using namespace std;

//void FormDialog::newQs(bool& outId);
//void FormDialog::swapper(bool& caseId, bool& outId);
//CSmartQ qobj;

FormDialog::FormDialog(QWidget * parent){
	QHBoxLayout *mainLayout = new QHBoxLayout();
	QVBoxLayout *layout1 = new QVBoxLayout();
	QVBoxLayout *layout2 = new QVBoxLayout();
	QVBoxLayout *layout3 = new QVBoxLayout();
	QVBoxLayout *layout4 = new QVBoxLayout();
	QLabel *l11 = new QLabel("Select by", this);
	QLabel *l12 = new QLabel("Uses all params", this);
	QLabel *l21 = new QLabel("Filter parametres", this);
	QLabel *l22 = new QLabel("(also used as input)", this);
	QComboBox *combo1 = new QComboBox(this);
	QSpinBox *spin1 = new QSpinBox(this);
	spin1->setMaximum(10000);
	spin1->setMinimum(0);
	QSpinBox *spin2 = new QSpinBox(this);
	spin2->setMaximum(10000);
	spin2->setMinimum(0);
	QSpinBox *spin3 = new QSpinBox(this);
	spin3->setMaximum(10000);
	spin3->setMinimum(0);
	//lineEdit1 = new QLineEdit();
	QPushButton *buttonS1 = new QPushButton("max cost");
	QPushButton *buttonS2 = new QPushButton("min ram");
	QPushButton *buttonS3 = new QPushButton("all params");
	QPushButton *buttonS4 = new QPushButton("output all");
	QPushButton *buttonM1 = new QPushButton("add");
	QPushButton *buttonM2 = new QPushButton("remove");
	//field1 = new QTextEdit();
	//field1->setReadOnly(true);
	//QString str1;
	bool lower = true, isOut = false;
	


	// connect(button1, SIGNAL(clicked()), this, SLOT(pusher()));
	// connect(button2, SIGNAL(clicked()), this, SLOT(poper()));
	// connect(button3, SIGNAL(clicked()), this, SLOT(sorter()));
	// connect(button4, SIGNAL(clicked()), this, SLOT(outer()));
	//connect(lineEdit1, SIGNAL(textEdited(QString)), this, SLOT(newQs()));
	//mainLayout->addWidget(lineEdit1);
	layout1->addWidget(l11);
	layout1->addWidget(buttonS1);
	layout1->addWidget(buttonS2);
	layout1->addWidget(buttonS3);
	layout1->addWidget(buttonS4);
	layout1->addWidget(l12);
	layout1->addWidget(buttonM1);
	layout1->addWidget(buttonM2);

layout2->addWidget(l21);
layout2->addWidget(l22);
layout2->addWidget(spin1);
layout2->addWidget(combo1);
layout2->addWidget(spin2);
layout2->addWidget(spin3);

	mainLayout->addLayout(layout1);
	mainLayout->addLayout(layout2);
	//mainLayout->addWidget(layout1);
	//mainLayout->addWidget(field1);
	setLayout(mainLayout);
};

// void FormDialog::newQs(){
// 	//isOut = false;
// 	field1->setText("");
// 	field1->append("input: " + lineEdit1->text());
// };

// void FormDialog::pusher(){
// 	QString str = lineEdit1->text();
//     QByteArray a= str.toUtf8(); // to....
//     char* d=  a.data();
// 	qobj.add(*d);

// 	//QString str2(QChar(*d));
// 	field1->append("added " + QString::fromLocal8Bit(d,1));
// 	//field1->append(str2);
// };

// void FormDialog::poper(){
// 	if(qobj.getlng()>0){
// 		qobj.rm();
// 	field1->append("last elem removed");
// 	}
// 	else{
// 		field1->append("queue is empty");
// 	}
// };

// void FormDialog::sorter(){
// 	qobj.sort();
// 	field1->append("sorted");
// };

// void FormDialog::outer(){
// 	qobj.reset();
// 	field1->setText("");
// 	field1->append("Queue:");
// 	for(int i=0; i < qobj.getlng(); i++){
// 		char *ch;
// 		*ch = qobj.gett();
// 		field1->append(QString::fromLocal8Bit(ch,1));
// 		//field1->append("^");
// 	}
// };
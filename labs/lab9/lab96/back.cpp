#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <iostream>
#include <QString>
#include "back.h"

//void FormDialog::newQs(bool& outId);
//void FormDialog::swapper(bool& caseId, bool& outId);

FormDialog::FormDialog(QWidget * parent){
	QVBoxLayout *mainLayout = new QVBoxLayout();
	lineEdit1 = new QLineEdit();
	QPushButton *button1 = new QPushButton("Convert");
	field1 = new QTextEdit();
	field1->setReadOnly(true);
	//QString str1;
	bool lower = true, isOut = false;


	connect(button1, SIGNAL(clicked()), this, SLOT(swapper()));
	connect(lineEdit1, SIGNAL(textEdited(QString)), this, SLOT(newQs()));
	mainLayout->addWidget(lineEdit1);
	mainLayout->addWidget(button1);
	mainLayout->addWidget(field1);
	setLayout(mainLayout);
};

void FormDialog::newQs(){
	//isOut = false;
	field1->setText("");
	field1->append("input: " + lineEdit1->text());
};

void FormDialog::swapper(){
	/*if(!(isOut)){
		field1->setText("");
		field1->append("input: " + lineEdit1->text());
	}*/
	//field1->append("_test_");
	if(lower){
		field1->append("lower case string: " + lineEdit1->text().toLower());
		
	}
	else{
		field1->append("UPPER CASE STRING: " + lineEdit1->text().toUpper());
	}
	lower = !(lower);
	//isOut = true;
};
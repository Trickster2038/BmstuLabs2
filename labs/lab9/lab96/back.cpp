#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <iostream>
#include "back.h"

FormDialog::FormDialog(QWidget * parent){
	QVBoxLayout *mainLayout = new QVBoxLayout();
	QLineEdit *lineEdit1 = new QLineEdit(this);
	QPushButton *button1 = new QPushButton("Convert");
	QTextEdit *field1 = new QTextEdit();
	field1->setReadOnly(true);
	QString str1;
	bool lower = true, isOut = false;


	connect(button1, SIGNAL(clicked()), this, SLOT(swapper(&lower, &isOut)));
	connect(field1, SIGNAL(textEdited(QString)), this, SLOT(newQs(&isOut)));
	mainLayout->addWidget(lineEdit1);
	mainLayout->addWidget(button1);
	mainLayout->addWidget(field1);
	setLayout(mainLayout);
};

void FormDialog::newQs(bool& outId){
	outId = false;
};

void FormDialog::swapper(bool& caseId, bool& outId){
	if(!(outId)){
		//field1->setText("");
		field1->append("input: " + lineEdit1->text());
	}

	if(caseId){
		field1->append("lower case string: " + lineEdit1->text().toLower());
		field1->append("_test_");
	}
	else{
		field1->append("UPPER CASE STRING: " + lineEdit1->text().toUpper());
	}
	caseId = !(caseId);
	outId = true;
};
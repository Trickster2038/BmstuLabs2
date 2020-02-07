#include "findForm.h"
#include "bookFile.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextCodec>
#define RUS(str) codec->toUnicode(str)

findForm::findForm()
{
    QTextCodec *codec = 
         QTextCodec::codecForName("Windows-1251"); 
	this->setWindowTitle(RUS("Поиск записей"));
     QVBoxLayout *layoutV1 = new QVBoxLayout();
	family=new QLabel(RUS("Фамилия"), this);
	name=new QLabel(RUS("Имя"), this);
	layoutV1->addWidget(family);  
	layoutV1->addWidget(name);
	QVBoxLayout *layoutV2 = new QVBoxLayout();
	familyEdit=new QLineEdit(RUS(""), this);
	nameEdit=new QLineEdit(RUS(""), this);
	layoutV2->addWidget(familyEdit);  
	layoutV2->addWidget(nameEdit);
     QHBoxLayout *layoutG1 = new QHBoxLayout();
	layoutG1->addLayout(layoutV1);
	layoutG1->addLayout(layoutV2);
     QHBoxLayout *layoutG2 = new QHBoxLayout();
	btnFind=new QPushButton(RUS("Найти"), this);
	btnExit=new QPushButton(RUS("Назад"), this);
	layoutG2->addWidget(btnFind);
     layoutG2->addWidget(btnExit);
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addLayout(layoutG1);
	layout->addLayout(layoutG2);
	connect(btnFind, SIGNAL(clicked(bool)),
              this,SLOT(findRecs()));
	connect(btnExit, SIGNAL(clicked(bool)),
              this,SLOT(close()));
}
void findForm::findRecs()
{
	recType r;  // параметры поиска
	r.fam=familyEdit->text();
	r.name=nameEdit->text();
	winPrint.showResults(r);
}

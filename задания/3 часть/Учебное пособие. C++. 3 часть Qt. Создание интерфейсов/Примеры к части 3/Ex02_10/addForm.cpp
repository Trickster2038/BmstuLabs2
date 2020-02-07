#include "addForm.h"
#include "bookFile.h"
#include "mainForm.h"
#include <QVBoxLayout>

addForm::addForm()
{
    QTextCodec *codec = 
        QTextCodec::codecForName("Windows-1251"); 
	this->setWindowTitle(RUS("Добавление записей"));
	QVBoxLayout *layoutV1 = new QVBoxLayout();
	family=new QLabel(RUS("Фамилия"), this);
	name=new QLabel(RUS("Имя"), this);
	nomer=new QLabel(RUS("Телефон"), this);
	layoutV1->addWidget(family);  
	layoutV1->addWidget(name);
	layoutV1->addWidget(nomer);
	QVBoxLayout *layoutV2 = new QVBoxLayout();
	familyEdit=new QLineEdit(RUS(""), this);
	nameEdit=new QLineEdit(RUS(""), this);
	nomerEdit=new QLineEdit(RUS(""), this);
	layoutV2->addWidget(familyEdit);  
	layoutV2->addWidget(nameEdit);
	layoutV2->addWidget(nomerEdit);
     QHBoxLayout *layoutG1 = new QHBoxLayout();
	layoutG1->addLayout(layoutV1);
	layoutG1->addLayout(layoutV2);
     QHBoxLayout *layoutG2 = new QHBoxLayout();
	btnAdd=new QPushButton(RUS("Добавить"), this);
	btnExit=new QPushButton(RUS("Назад"),this);
	layoutG2->addWidget(btnAdd);
     layoutG2->addWidget(btnExit);
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addLayout(layoutG1);
	layout->addLayout(layoutG2);
     connect(btnAdd, SIGNAL(clicked(bool)),
            this,SLOT(addRecord()));
	connect(btnExit, SIGNAL(clicked(bool)),
            this,SLOT(close()));
}
void addForm::addRecord()
{
	bookFile book;
	recType r;
	r.fam=familyEdit->text();
	r.name=nameEdit->text();
	r.nom=nomerEdit->text();
	familyEdit->clear();
	nameEdit->clear();
	nomerEdit->clear();
	book.addRec(r);
}

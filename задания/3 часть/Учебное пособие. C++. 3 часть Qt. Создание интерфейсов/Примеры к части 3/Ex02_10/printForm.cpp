#include "printForm.h"
#include "mainForm.h"
#include <QHBoxLayout>
#include <QMessageBox>

printForm::printForm()
{
     codec = QTextCodec::codecForName("Windows-1251"); 
     this->setWindowTitle(RUS("Результат"));
     QStringList strlist; // объект Список строк
     strlist << RUS("Фамилия")<< RUS("Имя")
             << RUS("Телефон"); // записываем строки заголовка
     table = new QTableWidget(10,3,this); // создаем таблицу
     table->setHorizontalHeaderLabels(strlist);// включаем
                                                                                                   //  заголовок
     QHBoxLayout *layoutG2 = new QHBoxLayout();
     btnExit=new QPushButton(RUS("Назад"), this);
     layoutG2->addWidget(btnExit);
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(table);
	layout->addLayout(layoutG2);
     connect(btnExit, SIGNAL(clicked(bool)),
             this,SLOT(close()));
}
void printForm::showRow(int i,recType r)
{
	QTableWidgetItem *item; // элемент таблицы
     item = new QTableWidgetItem(); // создаем элемент
	item->setFlags(Qt::NoItemFlags);//запрещаем 
                                                                                         // выделение 
	item->setText(r.fam);   // записываем текст
	table->setItem(i,0,item);// привязываем элемент 
                                                                         // к таблице
	item = new QTableWidgetItem();// создаем элемент
	item->setFlags(Qt::NoItemFlags); //запрещаем 
                                                                                         // выделение 
	item->setText(r.name);
	table->setItem(i,1,item); // привязываем элемент
	item = new QTableWidgetItem();// создаем элемент
	item->setFlags(Qt::NoItemFlags); //запрещаем 
                                                                                         // выделение 
	item->setText(r.nom); // записываем текст
	table->setItem(i,2,item); // привязываем элемент
}
void printForm::showAll()
{
	bookFile book;
	if (!book.readRec()) 
	{    // если файл пустой , то создаем сообщение
		QMessageBox msg(QMessageBox::Critical, 
                RUS("Нет данных"), 
                RUS("База пуста"),
                QMessageBox::Ok,0);
		msg.exec(); // выводим сообщение
	}
	else 
     {   // иначе - выводим таблицу по строкам
         showRow(0,book.r);
	    int i=0;
	    while (book.readRec())
		   showRow(++i,book.r);
	    table->setRowCount(i+1);
	    resize(350,330);
	    show();
     }
}
void printForm::showResults(recType r1)
{
	bookFile book;
	book.f->reset();
	if (!book.findFirst(r1))
	{   // если данные не найдены, то создаем сообщение
		QMessageBox msg(QMessageBox::Critical, 
              RUS("Нет данных"), 
              RUS("Данные не найдены"),
              QMessageBox::Ok,0);
		msg.exec();
	}
	else 
     {   // иначе - выводим результаты  по строкам
         showRow(0,book.r);
	    int i=0;
	    while (book.findNext(r1))
	         showRow(++i,book.r);
	    table->setRowCount(i+1);
	    resize(350,200);
	    show();
     }
}

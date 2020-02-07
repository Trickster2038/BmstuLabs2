#include "printForm.h"
#include "mainForm.h"
#include <QHBoxLayout>
#include <QMessageBox>

printForm::printForm()
{
     codec = QTextCodec::codecForName("Windows-1251"); 
     this->setWindowTitle(RUS("���������"));
     QStringList strlist; // ������ ������ �����
     strlist << RUS("�������")<< RUS("���")
             << RUS("�������"); // ���������� ������ ���������
     table = new QTableWidget(10,3,this); // ������� �������
     table->setHorizontalHeaderLabels(strlist);// ��������
                                                                                                   //  ���������
     QHBoxLayout *layoutG2 = new QHBoxLayout();
     btnExit=new QPushButton(RUS("�����"), this);
     layoutG2->addWidget(btnExit);
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(table);
	layout->addLayout(layoutG2);
     connect(btnExit, SIGNAL(clicked(bool)),
             this,SLOT(close()));
}
void printForm::showRow(int i,recType r)
{
	QTableWidgetItem *item; // ������� �������
     item = new QTableWidgetItem(); // ������� �������
	item->setFlags(Qt::NoItemFlags);//��������� 
                                                                                         // ��������� 
	item->setText(r.fam);   // ���������� �����
	table->setItem(i,0,item);// ����������� ������� 
                                                                         // � �������
	item = new QTableWidgetItem();// ������� �������
	item->setFlags(Qt::NoItemFlags); //��������� 
                                                                                         // ��������� 
	item->setText(r.name);
	table->setItem(i,1,item); // ����������� �������
	item = new QTableWidgetItem();// ������� �������
	item->setFlags(Qt::NoItemFlags); //��������� 
                                                                                         // ��������� 
	item->setText(r.nom); // ���������� �����
	table->setItem(i,2,item); // ����������� �������
}
void printForm::showAll()
{
	bookFile book;
	if (!book.readRec()) 
	{    // ���� ���� ������ , �� ������� ���������
		QMessageBox msg(QMessageBox::Critical, 
                RUS("��� ������"), 
                RUS("���� �����"),
                QMessageBox::Ok,0);
		msg.exec(); // ������� ���������
	}
	else 
     {   // ����� - ������� ������� �� �������
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
	{   // ���� ������ �� �������, �� ������� ���������
		QMessageBox msg(QMessageBox::Critical, 
              RUS("��� ������"), 
              RUS("������ �� �������"),
              QMessageBox::Ok,0);
		msg.exec();
	}
	else 
     {   // ����� - ������� ����������  �� �������
         showRow(0,book.r);
	    int i=0;
	    while (book.findNext(r1))
	         showRow(++i,book.r);
	    table->setRowCount(i+1);
	    resize(350,200);
	    show();
     }
}

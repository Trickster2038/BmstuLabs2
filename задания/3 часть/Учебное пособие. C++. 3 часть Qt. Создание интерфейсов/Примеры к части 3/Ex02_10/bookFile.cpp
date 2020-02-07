#include "bookFile.h"
#include "mainForm.h"
#include <QMessageBox>

bookFile::bookFile()  // �����������
{
     QTextCodec *codec = 
         QTextCodec::codecForName("Windows-1251");
	f=new QFile("book.txt");// ������� ������-����
	if(!f->exists()) // ���� ���� �� ����������, �� 
	{      // ������������ ���������
		QMessageBox msg(QMessageBox::Critical, 
               RUS("���� �� ������"),
               RUS("���� book.txt ������"),
               QMessageBox::Ok,0);
		msg.exec();// ������� ��������� �� �����
	}
	f->open(QFile::ReadWrite); // ��������� ���� 
                                                                        // ��� �����-������
 }
bookFile::~bookFile()   // ����������
{
	f->close();        // ��������� ����
	delete f;                        // ����������� ������
}
bool bookFile::addRec(recType r)
{
	f->seek(f->size()); // ��������� �� ����� �����
	QDataStream out(f); // ��������� � ������ ����� ������
	out<<r.fam<<r.name<<r.nom;// ������� ������ � ����
	return true;
}
bool bookFile::readRec()
{
	QDataStream in(f); // ��������� � ������ ����� �����
	if (in.atEnd())return false;
	else 
	{
		in>>r.fam>>r.name>>r.nom;
		return true;
	}
}
bool bookFile::findFirst(const recType r1)
{
	k1=(r1.fam=="");   // ������������� ��� ����� ������
     k2=(r1.name=="");
     ff=false;   // ������������� ���� ������ ������� �� �������
   	f->reset();
	bool fff = readRec();
	while(fff &&(!ff)) 
	{
		k3=(r1.fam==r.fam);  //������ ��� ��� ����� ������
          k4=(r1.name==r.name);
          if ((!k1 && !k2 && k3 && k4)||
             (!k1 && k2 && k3)||
             (k1 && !k2 && k4)) 
			ff=true; // ���� ������ ������� ������� 
		else fff=readRec();
	}
	return ff; // ���������� ���� ������
}
bool bookFile::findNext(const recType r1)
{
	ff=false;   // ���� ������ ������� �� �������
	bool fff = readRec();
	while((!ff) && fff) 
	{
		k3=(r1.fam==r.fam);//������ ��� ��� ����� ������
          k4=(r1.name==r.name);
          if ((!k1 && !k2 && k3 && k4)||
              (!k1 && k2 && k3)||
              (k1 && !k2 && k4)) 
			ff=true;     // ���� ������ ������� �������
		else fff=readRec();
	}
	return ff; // ���������� ���� ������
}

#include "bookFile.h"
#include "mainForm.h"
#include <QMessageBox>

bookFile::bookFile()  // конструктор
{
     QTextCodec *codec = 
         QTextCodec::codecForName("Windows-1251");
	f=new QFile("book.txt");// создаем объект-файл
	if(!f->exists()) // если файл не существует, то 
	{      // формирмируем сообщение
		QMessageBox msg(QMessageBox::Critical, 
               RUS("Файл не найден"),
               RUS("Файл book.txt создан"),
               QMessageBox::Ok,0);
		msg.exec();// выводим сообщение на экран
	}
	f->open(QFile::ReadWrite); // открываем файл 
                                                                        // для ввода-вывода
 }
bookFile::~bookFile()   // деструктор
{
	f->close();        // закрываем файл
	delete f;                        // освобождаем память
}
bool bookFile::addRec(recType r)
{
	f->seek(f->size()); // переходим на конец файла
	QDataStream out(f); // связываем с файлом поток вывода
	out<<r.fam<<r.name<<r.nom;// выводим данные в файл
	return true;
}
bool bookFile::readRec()
{
	QDataStream in(f); // связываем с файлом поток ввода
	if (in.atEnd())return false;
	else 
	{
		in>>r.fam>>r.name>>r.nom;
		return true;
	}
}
bool bookFile::findFirst(const recType r1)
{
	k1=(r1.fam=="");   // устанавливаем два ключа поиска
     k2=(r1.name=="");
     ff=false;   // устанавливаем ключ поиска «запись не найдена»
   	f->reset();
	bool fff = readRec();
	while(fff &&(!ff)) 
	{
		k3=(r1.fam==r.fam);  //строим еще два ключа поиска
          k4=(r1.name==r.name);
          if ((!k1 && !k2 && k3 && k4)||
             (!k1 && k2 && k3)||
             (k1 && !k2 && k4)) 
			ff=true; // ключ поиска «запись найдена» 
		else fff=readRec();
	}
	return ff; // возвращаем ключ поиска
}
bool bookFile::findNext(const recType r1)
{
	ff=false;   // ключ поиска «запись не найдена»
	bool fff = readRec();
	while((!ff) && fff) 
	{
		k3=(r1.fam==r.fam);//строим еще два ключа поиска
          k4=(r1.name==r.name);
          if ((!k1 && !k2 && k3 && k4)||
              (!k1 && k2 && k3)||
              (k1 && !k2 && k4)) 
			ff=true;     // ключ поиска «запись найдена»
		else fff=readRec();
	}
	return ff; // возвращаем ключ поиска
}

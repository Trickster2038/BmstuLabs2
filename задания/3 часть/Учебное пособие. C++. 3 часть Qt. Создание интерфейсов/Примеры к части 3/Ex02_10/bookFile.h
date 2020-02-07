#ifndef bookFile_h
#define bookFile_h
#include <QFile>

struct recType   // структура записи дл€ одного абонента
{	QString fam,name,nom;   };

class bookFile 
{	
	bool k1,k2,k3,k4,ff; // ключи поиска
public:
	QFile * f;    // указатель на объект класса QFile
	recType r;  // буфер ввода-вывода
	bookFile();  // конструктор
	~bookFile(); // деструктор
	bool addRec(recType r); // добавление записи в файл
	bool readRec();	    // чтение записи из файда
	bool findFirst(const recType r1); // поиск первой 
                                                         // записи, удовлетвор€ющей условию
	bool findNext(const recType r1);
                       // поиск следующей записи
};
#endif

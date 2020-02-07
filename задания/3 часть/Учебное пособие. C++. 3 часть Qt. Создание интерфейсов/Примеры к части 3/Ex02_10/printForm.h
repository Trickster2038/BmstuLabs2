#ifndef printForm_h
#define printForm_h
#include "bookFile.h"
#include <QTableWidget>
#include <QPushButton>

class printForm : public QWidget
{	
    	QTextCodec *codec; 
	QTableWidget *table;  // таблица
	QPushButton *btnExit;
	void showRow(int i,recType r);// вывод строки таблицы
public:
	printForm();    // конструктор
	void showAll(); // показать все записи
	void showResults(recType r1); // показать результаты поиска
};
#endif

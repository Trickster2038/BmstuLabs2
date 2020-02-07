#ifndef mainForm_h
#define mainForm_h
#include <QWidget>
#include <QPushButton>
#include <QTextCodec>
#define RUS(str) codec->toUnicode(str)
#include "addForm.h"
#include "findForm.h"
#include "printForm.h"

class Window : public QWidget
{	
	Q_OBJECT
	QPushButton * btnAdd,* btnPrint, 
                * btnFind, * btnExit;
	addForm winAdd;      // форма Добавления
	printForm winPrint;     // форма Отображение всех
	findForm winFind;          // форма Поиска
public: 
	Window();         // конструктор
public slots:
	void showAdd();   // показать форму Добавления
	void showPrint(); // показать форму Отображения всех
	void showFind();  // показать форму Поиска
};
#endif

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
	addForm winAdd;      // ����� ����������
	printForm winPrint;     // ����� ����������� ����
	findForm winFind;          // ����� ������
public: 
	Window();         // �����������
public slots:
	void showAdd();   // �������� ����� ����������
	void showPrint(); // �������� ����� ����������� ����
	void showFind();  // �������� ����� ������
};
#endif

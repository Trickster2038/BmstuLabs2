#ifndef printForm_h
#define printForm_h
#include "bookFile.h"
#include <QTableWidget>
#include <QPushButton>

class printForm : public QWidget
{	
    	QTextCodec *codec; 
	QTableWidget *table;  // �������
	QPushButton *btnExit;
	void showRow(int i,recType r);// ����� ������ �������
public:
	printForm();    // �����������
	void showAll(); // �������� ��� ������
	void showResults(recType r1); // �������� ���������� ������
};
#endif

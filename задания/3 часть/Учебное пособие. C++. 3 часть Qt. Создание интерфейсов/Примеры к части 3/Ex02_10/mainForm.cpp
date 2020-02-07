#include "mainForm.h"
#include <QVBoxLayout>
Window::Window() 
{
     QTextCodec *codec = 
         QTextCodec::codecForName("Windows-1251"); 
     this->setWindowTitle(RUS("�������� ������"));
     // ������� ������
	btnAdd = new QPushButton(RUS("��������"),this);
	btnFind = new QPushButton(RUS("�����"),this);
	btnPrint = new QPushButton(RUS("��������"),this);
	btnExit = new QPushButton(RUS("�����"),this);
	// ������� ����������� � �������� ��� ������
     QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(btnAdd);
	layout->addWidget(btnFind);
	layout->addWidget(btnPrint);
     layout->addWidget(btnExit);
     // ������������� ������� ����
	resize(180,150);
     // ��������� ������� �� ������� ������ �� ������� 
	connect(btnExit, SIGNAL(clicked(bool)),
             this,SLOT(close()));
	connect(btnAdd,SIGNAL(clicked(bool)),
             this,SLOT(showAdd()));
	connect(btnFind,SIGNAL(clicked(bool)),
             this,SLOT(showFind()));
	connect(btnPrint, SIGNAL(clicked(bool)),
             this,SLOT(showPrint()));
}
void Window::showAdd()
{	winAdd.show();  }
void Window::showFind()
{	winFind.show();  }
void Window::showPrint()
{	winPrint.showAll();  }

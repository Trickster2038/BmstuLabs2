#include "mainForm.h"
#include <QVBoxLayout>
Window::Window() 
{
     QTextCodec *codec = 
         QTextCodec::codecForName("Windows-1251"); 
     this->setWindowTitle(RUS("Записная книжка"));
     // создаем кнопки
	btnAdd = new QPushButton(RUS("Добавить"),this);
	btnFind = new QPushButton(RUS("Найти"),this);
	btnPrint = new QPushButton(RUS("Показать"),this);
	btnExit = new QPushButton(RUS("Выход"),this);
	// создаем компоновщик и передаем ему кнопки
     QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(btnAdd);
	layout->addWidget(btnFind);
	layout->addWidget(btnPrint);
     layout->addWidget(btnExit);
     // устанавливаем размеры окна
	resize(180,150);
     // связываем сигналы от нажатия кнопок со слотами 
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

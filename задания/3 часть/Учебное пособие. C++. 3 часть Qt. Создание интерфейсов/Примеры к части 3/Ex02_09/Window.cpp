#include "window.h"
#include <QVBoxLayout>
#include <QTextCodec>
Window::Window()
{
    codec = QTextCodec::codecForName("Windows-1251"); 
    this->setWindowTitle(codec->toUnicode("Обработка событий"));
    area = new Area( this );
    btn = new QPushButton(codec->toUnicode("Завершить"),this );
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(btn);	
    connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));
};

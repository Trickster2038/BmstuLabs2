#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <iostream>
#include <QString>
#include <QFrame>
#include <QPoint>
#include <QTimer>
#include "back.h"
#include "drawer.h"
#include "que.h"

#include <QPainter>
using namespace std;

CSmartQ qobj;
bool startb = true;
QTimer *timer1;

FormDialog::FormDialog(QWidget * parent){
	timer1 = new QTimer(this);
	QVBoxLayout *mainLayout = new QVBoxLayout();
	QPushButton *button1 = new QPushButton("Start / Stop");
	CDrawer* drawer1 = new CDrawer(this);
	bool lower = true, isOut = false;


	connect(button1, SIGNAL(clicked()), this, SLOT(starter()));
	connect(timer1, SIGNAL(timeout()), this, SLOT(repaint()));
	mainLayout->addWidget(drawer1);
	mainLayout->addWidget(button1);
	setLayout(mainLayout);
};

void FormDialog::starter(){
	if(startb)
	{
		timer1->start(150);
	}
	else{
		timer1->stop();
	}
	startb = !(startb);
};

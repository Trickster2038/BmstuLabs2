#ifndef addForm_h
#define addForm_h
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
class addForm : public QWidget
{	
	Q_OBJECT
	QLabel * family,* name,* nomer;
	QLineEdit * familyEdit,* nameEdit,* nomerEdit;
	QPushButton * btnAdd, * btnExit;
public:
	addForm();
public slots:
	void addRecord();
};
#endif 

#ifndef findForm_h
#define findForm_h
#include <QLabel>
#include "printForm.h"
class findForm : public QWidget
{	
	Q_OBJECT
	QLabel * family,* name;
	QLineEdit * familyEdit,* nameEdit;
	QPushButton * btnFind, * btnExit;
	printForm winPrint;
public:
	findForm();        // конструктор
public slots:
	void findRecs();  // метод поиска записей
};
#endif

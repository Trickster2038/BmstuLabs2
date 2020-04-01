#ifndef BACK_H_
#define BACK_H_
#include <QDialog>
#include <QLineEdit>
#include <QSignalMapper>
#include <QTextEdit>
/// Класс, реализующий редактор
class FormDialog: public QDialog
{
    Q_OBJECT
public:
    FormDialog( QWidget * parent = 0);
    virtual ~FormDialog(){};

protected:    
    QLineEdit *lineEdit1;
    QTextEdit *field1;
    bool lower, isOut;

    
private slots:
    void swapper(bool& caseId, bool& outId);
    void newQs(bool& outId);
};
#endif
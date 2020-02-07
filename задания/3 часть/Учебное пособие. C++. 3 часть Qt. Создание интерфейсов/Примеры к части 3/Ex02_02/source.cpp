#include <QApplication>
#include <QWidget>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("Main Window");
    window.setObjectName("window");
    QLineEdit *edit1=new QLineEdit("Edit1",&window);
    QLineEdit *edit2=new QLineEdit("Edit2",&window);
    edit1->setGeometry(20,20,60,60);
    edit2->setGeometry(120,20,60,60);
    window.show();
    return app.exec();
}

#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("Main Window");
    window.setObjectName("window");
    QLineEdit *edit1=new QLineEdit("Edit1",&window);
    QLineEdit *edit2=new QLineEdit("Edit2",&window);
    QVBoxLayout *layout = new QVBoxLayout;	 
    layout->addWidget(edit1);
    layout->addWidget(edit2);
    layout->addStretch();
    window.setLayout(layout);  // связываем layout с виджетом окна
    window.show();
    return app.exec();
}


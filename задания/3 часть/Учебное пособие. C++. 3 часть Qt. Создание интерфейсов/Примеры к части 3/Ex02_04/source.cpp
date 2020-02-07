#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("Main Window");
    window.setObjectName("window");
    QLineEdit *edit1=new QLineEdit("Edit1",&window);
    QLineEdit *edit2=new QLineEdit("Edit2",&window);
    QLineEdit *edit3=new QLineEdit("Edit3",&window);
    QGridLayout *layout = new QGridLayout; // ������������ �� �����
    layout->setContentsMargins(5,5,5,5); // ������������� ������� ���� 
    layout->setSpacing(5); // ������������� �������� ����� ��������� 
    window.setLayout(layout);  // ��������� layout � �������� ����
    layout->addWidget(edit1,0,0,1,2);
    layout->addWidget(edit2,1,0,1,1);
    layout->addWidget(edit3,1,1,1,1);
    window.show();
    return app.exec();
}


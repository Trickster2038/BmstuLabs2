#include <QApplication>
#include <QSplitter>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QSplitter splitter(Qt::Horizontal);
    splitter.setWindowTitle("Main Window");
    QLineEdit *edit1=new QLineEdit("Edit1",&splitter);
    QLineEdit *edit2=new QLineEdit("Edit2",&splitter);
    splitter.show();
    return app.exec();
}



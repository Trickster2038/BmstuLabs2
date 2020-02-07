#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
int main(int argc, char *argv[])
{
     QApplication app(argc, argv);
     QWidget window;
     window.setWindowTitle("Main Window");
     window.setObjectName("window");
     QLineEdit *edit1=new QLineEdit("Edit1",&window);
     QLineEdit *edit2=new QLineEdit("Edit2",&window);
     QHBoxLayout *layout = new QHBoxLayout; // выравнивание по           
                                                                                                     // горизонтали
     layout->setContentsMargins(5,5,5,5);  // внешние пол€ окна
     layout->setSpacing(5);                // просвет между виджетами   
     window.setLayout(layout); // св€зывание layout с виджетом окна
     // задание пор€дка следовани€ элементов
     layout->addWidget(edit1);
     layout->addWidget(edit2);
     window.show();
     return app.exec();
 }

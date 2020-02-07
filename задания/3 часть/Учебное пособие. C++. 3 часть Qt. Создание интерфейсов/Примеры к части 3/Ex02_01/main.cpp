#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv); // создаем объект-приложение
	QWidget window;               // создаем корневой виджет
	QRect rect = window.geometry(); // читаем размер окна по умолчанию
	window.setGeometry(20, 20, 100, 100); // устанавливаем размер окна
	window.resize(300, 100);             // меняем ширину и высоту окна
	window.setWindowTitle("Main Window");// устанавливаем заголовок
	window.setObjectName("window");      // сохраняем имя объекта
	window.show();             // визуализируем окно
	return app.exec();         // запускаем цикл обработки сообщений
}


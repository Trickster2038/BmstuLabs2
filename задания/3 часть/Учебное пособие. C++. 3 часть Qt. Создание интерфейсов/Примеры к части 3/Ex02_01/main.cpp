#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv); // ������� ������-����������
	QWidget window;               // ������� �������� ������
	QRect rect = window.geometry(); // ������ ������ ���� �� ���������
	window.setGeometry(20, 20, 100, 100); // ������������� ������ ����
	window.resize(300, 100);             // ������ ������ � ������ ����
	window.setWindowTitle("Main Window");// ������������� ���������
	window.setObjectName("window");      // ��������� ��� �������
	window.show();             // ������������� ����
	return app.exec();         // ��������� ���� ��������� ���������
}


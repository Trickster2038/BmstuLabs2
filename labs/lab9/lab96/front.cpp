#include <QApplication>
#include "back.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FormDialog *dialog = new FormDialog();
    dialog->show(); // отображаем окно
    return app.exec(); // запускаем цикл обработки сообщений
}
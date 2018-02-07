#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    w.setWindowTitle("主菜单");
    w.setWindowIcon(QIcon(":/image/Main.png"));
    w.setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/image/bg.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    w.setPalette(palette);

    return a.exec();
}

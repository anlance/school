#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"dialog.h"
#include <QFileDialog>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_inFormatBtn_clicked();

    void on_fileInBtn_clicked();

    void on_handInBtn_clicked();

    void on_detailBtn_clicked();

    void on_exitBtn_clicked();


private:
    Ui::Widget *ui;
    Dialog *d;
};

#endif // WIDGET_H

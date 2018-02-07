#include "widget.h"
#include "ui_widget.h"
#include"dialog.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->detailBtn->setStyleSheet(tr("background-image: url(:/image/bt.png);"));
    ui->exitBtn->setStyleSheet(tr("background-image: url(:/image/bt.png);"));
    ui->fileInBtn->setStyleSheet(tr("background-image: url(:/image/bt.png);"));
    ui->handInBtn->setStyleSheet(tr("background-image: url(:/image/bt.png);"));
    ui->inFormatBtn->setStyleSheet(tr("background-image: url(:/image/bt.png);"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_inFormatBtn_clicked()
{
    d = new Dialog(this);
    d->setWindowTitle(tr("格式说明"));
    d->setWindowIcon(QIcon(":/image/explain.png"));
    d->setLabel("<html>"+tr("1.文件格式:")+"</html>"
        "<html>"+"<br>"+tr(". 顶点个数：n")+"</html>"
        "<html>"+"<br>"+tr(". 所有顶点名称：a,b,c,d ")+"</html>"
        "<html>"+"<br>"+tr(". 边的个数：m")+"</html>"
        "<html>"+"<br>"+tr(". 每条边的两个顶点,权值：a b 1")+"</html>"
        "<html>"+"<br>"+tr(". 每条边的两个顶点,权值：b c 3")+"</html>"
        "<html>"+"<br>"+tr("**注意：只需输入字符即可")+"</html>"
        "<html>"+"<br>"+tr("")+"</html>"
        "<html>"+"<br>"+tr("2.手动输入:")+"</html>"
        "<html>"+"<br>"+tr(". 同文件差不多，按照步骤输入即可")+"</html>", 40, 10);
    //d->exec();  //模态
    if(d->exec() == QDialog::Accepted)
        this->show();
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    //画笔颜色
    painter.setPen(QColor(0,160,250));
    //painter.setPen(QColor(0,160,230));

    // 设置字体：微软雅黑、点大小50
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(30);
    painter.setFont(font);

    // 绘制文本
    painter.drawText(QPoint(80, 100), QStringLiteral("图的基本运算"));
    //painter.drawText(rect(), Qt::AlignHCenter, "图的基本运算");
}

void Widget::on_fileInBtn_clicked()
{   
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("打开文本文件"));
    fileDialog->setDirectory(".");
    fileDialog->setNameFilter(tr("File(*.txt)"));
    //fileDialog->setFileMode(QFileDialog::ExistingFiles);
    fileDialog->setViewMode(QFileDialog::Detail);
    QStringList fileName;
    if(fileDialog->exec())
    {
        fileName = fileDialog->selectedFiles();
        QString qpath = fileName.join(",");
        qDebug()<<qpath<<endl;
        d = new Dialog(this);
        d->fileInput(qpath);
        d->close();
    }
}

void Widget::on_handInBtn_clicked()
{
    this->close();
    d = new Dialog(this);
    d->setWindowTitle(tr("手动输入"));
    d->setWindowIcon(QIcon(":/image/handInput.png"));
    d->setNextBtn("下一步", 10, 260, 60, 23, tr("background-image: url(:/image/bt.png);"));
    d->setReInputBtn("重新输入", 150, 260,75, 23, tr("background-image: url(:/image/bt.png);"));
    d->setReturnBtn("返回主菜单", 290, 260,80, 23, tr("background-image: url(:/image/bt.png);"));
    d->setVertexNumLe("顶点个数", 160,20,60,20);
    d->setVertexNameLe("顶点名字，空格隔开", 120, 60, 150, 20);
    d->setEdgeNumLe("边的数目", 160, 100, 60, 20);
    d->setEveryEdge("顶点1 顶点2 权值 换行",120, 140, 140, 100);
    if(d->exec() == QDialog::Accepted)
        this->show();
}

void Widget::on_detailBtn_clicked()
{
    d = new Dialog(this);
    d->setWindowTitle(tr("about us"));
    d->setWindowIcon(QIcon(":/image/about.png"));
    d->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/image/usBg.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    d->setPalette(palette);
    d->setLabel("<html>"+tr("   制作成员 ：")+"</html>"
        "<html>"+"<br>"+tr("    ")+"</html>"
        "<html>"+"<br>"+tr(".CDUT16级6班小组：")+"</html>"
        "<html>"+"<br>"+tr(". 龙海洋 ")+"</html>"
        "<html>"+"<br>"+tr(". 李颜")+"</html>"
        "<html>"+"<br>"+tr(". 周强")+"</html>"
        "<html>"+"<br>"+tr(". 宋亚思")+"</html>"
        "<html>"+"<br>"+tr("-----------------")+"</html>"
        "<html>"+"<br>"+tr("Version 1.0, 没有后续版本")+"</html>", 80, 60);
    if(d->exec() == QDialog::Accepted)
        this->show();
}

void Widget::on_exitBtn_clicked()
{
    close();
}


#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QTextBrowser>
#include <QPushButton>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QApplication>
#include <QDebug>
#include <QIcon>
#include <QPalette>
#include "graph.h"
#include "qpainter.h"
using namespace std;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    /*--------按钮设置-------*/
    void setNextBtn (QString text, int x, int y, int width, int hight, QString image);
    void setReInputBtn (QString text, int x, int y, int width, int hight, QString image);
    void setReturnBtn (QString text, int x, int y, int width, int hight, QString image);
    void setMatrixOutputBtn(QString text, int x, int y, int width, int hight, QString image);
    void setEdgeOutputBtn(QString text, int x, int y, int width, int hight, QString image);
    void setDfsBtn(QString text, int x, int y, int width, int hight, QString image);
    void setBfsBtn(QString text, int x, int y, int width, int hight, QString image);
    void setIsConnectBtn(QString text, int x, int y, int width, int hight, QString image);
    void setFindConnectBtn(QString text, int x, int y, int width, int hight, QString image);
    void setFloydBtn(QString text, int x, int y, int width, int hight, QString image);
    void setConnectMatrixBtn(QString text, int x, int y, int width, int hight, QString image);
    void setConnectEdgeBtn(QString text, int x, int y, int width, int hight, QString image);

    /*------输入输出设置--------*/
    void setLabel (QString text, int x, int y);
    void fileInput(QString qpath);
    void setVertexNumLe (QString echoText, int x, int y,int width, int hight);
    void setVertexNameLe (QString echoText, int x, int y, int width, int hight);
    void setEdgeNumLe (QString echoText, int x, int y,int width, int hight);
    void setEveryEdge (QString echoText, int x, int y,int width, int hight);
    void setV1 (QString echoText, int x, int y, int width, int hight);
    void setV2 (QString echoText, int x, int y, int width, int hight);
    void setOutput (QString outputText, int x, int y, int width, int hight);

    /*------辅助函数-------*/
    QString getText();

private slots:
    /*-------槽函数-------*/
    void return_clicked();
    void reInput_clicked();
    void next_clicked();
    void last_clicked();
    void matrixOutput_clicked();
    void edgeOutput_clicked();
    void bfs_clicked();
    void bfsOutput_clicked();
    void dfs_clicked();
    void dfsOutput_clicked();
    void isConnect_clicked();
    void findConnect_clicked();
    void connectMatrix_clicked();
    void connectEdge_clicked();
    void floyd_clicked();
    void floydOutput_clicked();

private:
    Ui::Dialog *ui;
    /*----按钮组件-----*/
    QPushButton *nextBtn;
    QPushButton *reInputBtn;
    QPushButton *returnBtn;
    QPushButton *matrixOutputBtn;
    QPushButton *edgeOutputBtn;
    QPushButton *dfsBtn;
    QPushButton *bfsBtn;
    QPushButton *isConnectBtn;
    QPushButton *findConnectBtn;
    QPushButton *floydBtn;
    QPushButton *connectMatrix;
    QPushButton *connectEdge;

    /*---读取、显示组件---*/
    QLabel *label;
    QLineEdit * vertexNumLe;
    QLineEdit * vertexNameLe;
    QLineEdit * edgeNumLe;
    QLineEdit * v1;
    QLineEdit * v2;
    QPlainTextEdit * everyEdge;
    QTextBrowser *output;

};

#endif // DIALOG_H

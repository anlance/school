#include "dialog.h"
#include "ui_dialog.h"


adjacencyWGraph *text = NULL;
adjacencyWGraph *temps = NULL;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    label = new QLabel(this);
    this->label->setText("");
    this->label->move(60,60);
    this->setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/image/bg.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
}

Dialog::~Dialog()
{
    delete ui;
}

//---------------槽----------------//

void Dialog::return_clicked()
{
    accept();
}

//重新输入
void Dialog::reInput_clicked()
{
    if(this->v1 && (!this->v2))
        this->v1->clear();
    else if(this->v2 && (!this->v1))
        this->v2->clear();
    else if(this->v1 && this->v2)
    {
        this->v1->clear();
        this->v2->clear();
    }
    else
    {
        if(this->label)
            this->label->clear();
        if(this->vertexNumLe)
            this->vertexNumLe->clear();
        if(this->vertexNameLe)
            this->vertexNameLe->clear();
        if(this->edgeNumLe)
            this->edgeNumLe->clear();
        if(this->everyEdge)
            this->everyEdge->clear();
    }
}

//下一步
void Dialog::next_clicked()
{
    //顶点个数读取
    QString Num = vertexNumLe->text();
    int vtNum = Num.toInt();
    text = new adjacencyWGraph(vtNum);

    //顶点名字读取
    QString Name = vertexNameLe->text();
    string vtName = Name.toStdString();
    text->inputV(vtName);

    //边的个数以及边的集合读取
    Num = edgeNumLe->text();
    int eNum = Num.toInt();
    Name = everyEdge->toPlainText();
    string edgeName = Name.toStdString();
    text->inputE(eNum, edgeName);
    text->getMaxLength();

    Dialog *outPut = new Dialog(this);
    outPut->setWindowTitle(tr("功能菜单"));
    outPut->setWindowIcon(QIcon(":/image/fire.png"));
    outPut->setMatrixOutputBtn("以矩阵形式输出图", 120, 30, 150, 20, tr("background-image: url(:/image/bt.png);"));
    outPut->setEdgeOutputBtn("以边的形式输出图", 120, 60, 150, 20, tr("background-image: url(:/image/bt.png);"));
    outPut->setDfsBtn("深度优先算法遍历该图", 120, 90, 150, 20, tr("background-image: url(:/image/bt.png);"));
    outPut->setBfsBtn("广度优先算法遍历该图", 120, 120, 150, 20, tr("background-image: url(:/image/bt.png);"));
    outPut->setIsConnectBtn("判断图的连通性", 120, 150, 150, 20, tr("background-image: url(:/image/bt.png);"));
    outPut->setFindConnectBtn("求该图的连通分支", 120, 180, 150, 20, tr("background-image: url(:/image/bt.png);"));
    outPut->setFloydBtn("求任意两点间的最短距离", 120, 210, 150, 20, tr("background-image: url(:/image/bt.png);"));
    outPut->setNextBtn("上一步", 10, 260, 60, 23, tr("background-image: url(:/image/bt.png);"));
    outPut->exec();
}


void Dialog::fileInput(QString qpath)
{
    string path = qpath.toStdString();

    ifstream file;
    file.open(path);
    int vtNum = 0;
    file >> vtNum;
    text = new adjacencyWGraph(vtNum);
    file.close();
    text->inputFile(path);
    text->getMaxLength();

    Dialog *outPut = new Dialog(this);
    outPut->setWindowTitle(tr("功能菜单"));
    outPut->setWindowIcon(QIcon(":/image/fire.png"));
    outPut->setGeometry(QRect(484,213,400,300));
    outPut->setMatrixOutputBtn("以矩阵形式输出图", 120, 30, 150, 20, tr("background-image: url(:/image/bt.png);"));
    outPut->setEdgeOutputBtn("以边的形式输出图", 120, 60, 150, 20, tr("background-image: url(:/image/bt.png);"));
    outPut->setDfsBtn("深度优先算法遍历该图", 120, 90, 150, 20, tr("background-image: url(:/image/bt.png);"));
    outPut->setBfsBtn("广度优先算法遍历该图", 120, 120, 150, 20, tr("background-image: url(:/image/bt.png);"));
    outPut->setIsConnectBtn("判断图的连通性", 120, 150, 150, 20, tr("background-image: url(:/image/bt.png);"));
    outPut->setFindConnectBtn("求该图的连通分支", 120, 180, 150, 20, tr("background-image: url(:/image/bt.png);"));
    outPut->setFloydBtn("求任意两点间的最短距离", 120, 210, 150, 20, tr("background-image: url(:/image/bt.png);"));
    //outPut->setNextBtn("上一步", 10, 260, 60, 23);
    outPut->setReturnBtn("返回主菜单", 290, 260,80, 23, tr("background-image: url(:/image/bt.png);"));
    outPut->show();
}

//上一步
void Dialog::last_clicked()
{
    this->close();
}

//以矩阵形式输出图
void Dialog::matrixOutput_clicked()
{
    Dialog *martrixDlg = new Dialog(this);
    martrixDlg->setWindowTitle(tr("以矩阵形式输出图"));
    martrixDlg->setWindowIcon(QIcon(":/image/output1.png"));
    martrixDlg->setGeometry(QRect(885,210,400,300));
    string s;
    text->outputWithAdjacency(s);
    QString outputText = QString::fromStdString(s);
    martrixDlg->setOutput(outputText,10, 10, 380, 280);
    martrixDlg->show();

}

//以边的形式输出图
void Dialog::edgeOutput_clicked()
{
    Dialog *edgeDlg = new Dialog(this);
    edgeDlg->setWindowTitle(tr("以边的形式输出图"));
    edgeDlg->setWindowIcon(QIcon(":/image/output2.png"));
    edgeDlg->setGeometry(QRect(885,240,400,300));
    string s;
    text->outputGraph(s);
    QString outputText = QString::fromStdString(s);
    edgeDlg->setOutput(outputText,10, 10, 380, 280);
    edgeDlg->show();
}

//广度优先遍历输入
void Dialog::bfs_clicked()
{
    Dialog *bfsDlg = new Dialog(this);
    bfsDlg->setWindowTitle(tr("广度优先遍历输入"));
    bfsDlg->setWindowIcon(QIcon(":/image/bfs.png"));
    bfsDlg->setGeometry(QRect(85, 310, 400, 70));
    bfsDlg->setV1("广度优先起点", 150,10,80,20);
    bfsDlg->setNextBtn("bfs显示", 10, 40, 60, 23, tr("background-image: url(:/image/bt.png);"));
    bfsDlg->setReInputBtn("重新输入bfs起点", 140, 40,100, 23, tr("background-image: url(:/image/bt.png);"));
    bfsDlg->setReturnBtn("返回功能菜单", 290, 40,80, 23, tr("background-image: url(:/image/bt.png);"));
    bfsDlg->show();

}

//广度优先算法遍历该图
void Dialog::bfsOutput_clicked()
{
    Dialog *bfsDlgOutput = new Dialog(this);
    bfsDlgOutput->setWindowTitle(tr("广度优先算法遍历该图"));
    bfsDlgOutput->setWindowIcon(QIcon(":/image/output4.png"));
    bfsDlgOutput->setGeometry(QRect(885,300,400,300));
    QString Name = v1->text();
    string v = Name.toStdString();
    string s;
    text->bfs(v,s);
    QString outputText = QString::fromStdString(s);
    bfsDlgOutput->setOutput(outputText,10, 10, 380, 280);
    bfsDlgOutput->show();
}

//深度优先遍历输入
void Dialog::dfs_clicked()
{
    Dialog *dfsDlg = new Dialog(this);
    dfsDlg->setWindowTitle(tr("深度优先遍历输入"));
    dfsDlg->setWindowIcon(QIcon(":/image/dfs.png"));
    dfsDlg->setGeometry(QRect(85, 210, 400, 70));
    dfsDlg->setV2("深度优先起点", 150,10,80,20);
    dfsDlg->setNextBtn("dfs显示", 10, 40, 60, 23, tr("background-image: url(:/image/bt.png);"));
    dfsDlg->setReInputBtn("重新输入dfs起点", 140, 40,100, 23, tr("background-image: url(:/image/bt.png);"));
    dfsDlg->setReturnBtn("返回功能菜单", 290, 40,80, 23, tr("background-image: url(:/image/bt.png);"));
    dfsDlg->show();

}

//深度优先算法遍历该图
void Dialog::dfsOutput_clicked()
{

    Dialog *dfsDlgOutput = new Dialog(this);
    dfsDlgOutput->setWindowTitle(tr("深度优先算法遍历该图"));
    dfsDlgOutput->setWindowIcon(QIcon(":/image/output3.png"));
    dfsDlgOutput->setGeometry(QRect(885,270,400,300));
    QString Name = v2->text();
    string v = Name.toStdString();
    string s;
    text->initReach();
    text->dfs(text->indexOfV(v),s);
    QString outputText = QString::fromStdString(s);
    dfsDlgOutput->setOutput(outputText,10, 10, 380, 280);
    dfsDlgOutput->show();
}

//判断图的连通性
void Dialog::isConnect_clicked()
{

    Dialog *isConnectDlg = new Dialog(this);
    isConnectDlg->setWindowTitle(tr("判断图的连通性"));
    isConnectDlg->setWindowIcon(QIcon(":/image/output5.png"));
    isConnectDlg->setGeometry(QRect(885,330,400,300));
    string s;
    if(text->isConnect())
        s = "该图是连通图";
    else
        s = "该图不是连通图";
    QString outputText = QString::fromStdString(s);
    isConnectDlg->setLabel(outputText,100,100);
    isConnectDlg->show();
}

//输出连通分支
void Dialog::findConnect_clicked()
{

    Dialog *findConnectDlg = new Dialog(this);
    findConnectDlg->setWindowTitle(tr("输出连通分支"));
    findConnectDlg->setWindowIcon(QIcon(":/image/connect.png"));
    findConnectDlg->setGeometry(QRect(85, 410, 400, 70));
    //findConnectDlg->setLabel(tr("请选择输出连通分支的方式"),100,200);
    temps = text->findConnect();
    findConnectDlg->setConnectMatrixBtn("邻接矩阵", 150,10,80,20, tr("background-image: url(:/image/bt.png);"));
    findConnectDlg->setConnectEdgeBtn("邻接链表(边和权值)",110,40,160,20, tr("background-image: url(:/image/bt.png);"));
    findConnectDlg->show();
}

//1 矩阵输出 连通分支
void Dialog::connectMatrix_clicked()
{

    Dialog *connectMatrixDlg = new Dialog(this);
    connectMatrixDlg->setWindowTitle(tr("以矩阵输出形式连通分支"));
    connectMatrixDlg->setWindowIcon(QIcon(":/image/output6.png"));
    connectMatrixDlg->setGeometry(QRect(885,360,400,300));
    string s;
    string temp;
    stringstream ss;
    qDebug()<<stn<<endl;
    for (int i = 0; i < stn; i++)
    {
        s += "该图的第";
        ss.clear();
        ss << i+1;
        ss >> temp;
        s += temp;
        s += "个连通分支为：";
        s += "\r";
        s += "\r";
        temps[i].getMaxLength();
        temps[i].outputWithAdjacency(s);
        s += "\r";
        s += "\r";
    }
    QString outputText = QString::fromStdString(s);
    connectMatrixDlg->setOutput(outputText,10, 10, 380, 280);
    connectMatrixDlg->show();
}

//2 邻接链表输出 连通分支
void Dialog::connectEdge_clicked()
{

    Dialog *connectEdgeDlg = new Dialog(this);
    connectEdgeDlg->setWindowTitle(tr("以邻接链表形式输出连通分支"));
    connectEdgeDlg->setWindowIcon(QIcon(":/image/output7.png"));
    connectEdgeDlg->setGeometry(QRect(885,390,400,300));
    string s;
    string temp;
    stringstream ss;
    for (int i = 0; i < stn; i++)
    {
        s += "该图的第";
        ss.clear();
        ss << i+1;
        ss >> temp;
        s += temp;
        s += "个连通分支为：";
        s += "\r";
        s += "\r";
        s += "图中的节点集合有：";

        temps[i].outputVertex(s);
        int num = temps[i].getEdgeNum();
        if(num<1){
            s += "图中无边";
            s += "\r";
        }
        else{
            s += "图中的边有：";
            s += "\r";
            temps[i].outputGraph(s);
        }
        s += "\r";
        s += "\r";
    }
    //text->outputGraph(s);
    QString outputText = QString::fromStdString(s);
    connectEdgeDlg->setOutput(outputText,10, 10, 380, 280);
    connectEdgeDlg->show();
}

//使用Floyd最短路径算法
void Dialog::floyd_clicked()
{
    //this->close();
    Dialog *dfsDlg = new Dialog(this);
    dfsDlg->setWindowTitle(tr("输入两个顶点"));
    dfsDlg->setWindowIcon(QIcon(":/image/short.png"));
    dfsDlg->setGeometry(QRect(85, 510, 400, 70));
    dfsDlg->setV1("顶点1", 80,10,80,20);
    dfsDlg->setV2("顶点2", 220,10,80,20);
    dfsDlg->setNextBtn("显示距离", 10, 40, 60, 23, tr("background-image: url(:/image/bt.png);"));
    dfsDlg->setReInputBtn("重新输入顶点", 140, 40,100, 23, tr("background-image: url(:/image/bt.png);"));
    dfsDlg->setReturnBtn("返回功能菜单", 290, 40,80, 23, tr("background-image: url(:/image/bt.png);"));
    dfsDlg->show();

}

//最短距离输出
void Dialog::floydOutput_clicked()
{
    Dialog *floydOutput = new Dialog(this);
    floydOutput->setWindowTitle(tr("两点间的最短距离"));
    floydOutput->setWindowIcon(QIcon(":/image/output8.png"));
    floydOutput->setGeometry(QRect(885,420,400,300));
    QString qv1 = v1->text();
    string sv1 = qv1.toStdString();
    QString qv2 = v2->text();
    string sv2 = qv2.toStdString();
    int result = text->Floyd(sv1, sv2);
    string temp;
    stringstream ss;
    if(result==INT_MAX)
    {
        temp = "∞";
    }
    else
    {
        ss<<result;
        ss>>temp;
    }
    string s = "顶点 "+sv1+" 与顶点 "+sv2+" 的最短距离是：";
    s += temp;
    QString outputText = QString::fromStdString(s);
    floydOutput->setOutput(outputText,10, 10, 380, 280);
    floydOutput->show();
}



//--------------设置-------------------//

void Dialog::setLabel(QString text, int x, int y)
{
    label->setText(text);
    label->move(x,y);
    label->setFont(QFont("Timers", 16, QFont::Bold));
}

void Dialog::setNextBtn(QString text, int x, int y, int width, int hight, QString image)
{
    nextBtn = new QPushButton(this);
    nextBtn->setText(text);
    nextBtn->setGeometry(QRect(x, y, width, hight));
    nextBtn->setStyleSheet(image);
    //nextBtn->setFocusPolicy(Qt::NoFocus);
    if(text == tr("下一步"))
        connect(nextBtn, &QPushButton::clicked, this, &Dialog::next_clicked);
    else if(text == tr("上一步"))
        connect(nextBtn, &QPushButton::clicked, this, &Dialog::last_clicked);
    else if(text == tr("bfs显示"))
        connect(nextBtn, &QPushButton::clicked, this, &Dialog::bfsOutput_clicked);
    else if(text == tr("dfs显示"))
        connect(nextBtn, &QPushButton::clicked, this, &Dialog::dfsOutput_clicked);
    else if(text == tr("显示距离"))
        connect(nextBtn, &QPushButton::clicked, this, &Dialog::floydOutput_clicked);
}

void Dialog::setReInputBtn(QString text, int x, int y, int width, int hight, QString image)
{
    reInputBtn = new QPushButton(this);
    reInputBtn->setText(text);
    reInputBtn->setGeometry(QRect(x, y, width, hight));
    reInputBtn->setFocusPolicy(Qt::NoFocus);
    reInputBtn->setStyleSheet(image);
    connect(reInputBtn, &QPushButton::clicked, this, &Dialog::reInput_clicked);
}

void Dialog::setReturnBtn(QString text, int x, int y, int width, int hight, QString image)
{
    returnBtn = new QPushButton(this);
    returnBtn->setText(text);
    returnBtn->setGeometry(QRect(x, y, width, hight));
    returnBtn->setFocusPolicy(Qt::NoFocus);
    returnBtn->setStyleSheet(image);
    connect(returnBtn, &QPushButton::clicked, this, &Dialog::return_clicked);
}

void Dialog::setMatrixOutputBtn(QString text, int x, int y, int width, int hight, QString image)
{
    matrixOutputBtn = new QPushButton(this);
    matrixOutputBtn->setText(text);
    matrixOutputBtn->setGeometry(QRect(x, y, width, hight));
    matrixOutputBtn->setStyleSheet(image);
    connect(matrixOutputBtn, &QPushButton::clicked, this, &Dialog::matrixOutput_clicked);
}

void Dialog::setEdgeOutputBtn(QString text, int x, int y, int width, int hight, QString image)
{
    edgeOutputBtn = new QPushButton(this);
    edgeOutputBtn->setText(text);
    edgeOutputBtn->setGeometry(QRect(x, y, width, hight));
    edgeOutputBtn->setStyleSheet(image);
    connect(edgeOutputBtn, &QPushButton::clicked, this, &Dialog::edgeOutput_clicked);
}

void Dialog::setDfsBtn(QString text, int x, int y, int width, int hight, QString image)
{
    dfsBtn = new QPushButton(this);
    dfsBtn->setText(text);
    dfsBtn->setGeometry(QRect(x, y, width, hight));
    dfsBtn->setStyleSheet(image);
    connect(dfsBtn, &QPushButton::clicked, this, &Dialog::dfs_clicked);
}

void Dialog::setBfsBtn(QString text, int x, int y, int width, int hight, QString image)
{
    bfsBtn = new QPushButton(this);
    bfsBtn->setText(text);
    bfsBtn->setGeometry(QRect(x, y, width, hight));
    bfsBtn->setStyleSheet(image);
    connect(bfsBtn, &QPushButton::clicked, this, &Dialog::bfs_clicked);
}

void Dialog::setIsConnectBtn(QString text, int x, int y, int width, int hight, QString image)
{
    isConnectBtn = new QPushButton(this);
    isConnectBtn->setText(text);
    isConnectBtn->setGeometry(QRect(x, y, width, hight));
    isConnectBtn->setStyleSheet(image);
    connect(isConnectBtn, &QPushButton::clicked, this, &Dialog::isConnect_clicked);
}

void Dialog::setFindConnectBtn(QString text, int x, int y, int width, int hight, QString image)
{
    findConnectBtn = new QPushButton(this);
    findConnectBtn->setText(text);
    findConnectBtn->setGeometry(QRect(x, y, width, hight));
    findConnectBtn->setStyleSheet(image);
    connect(findConnectBtn, &QPushButton::clicked, this, &Dialog::findConnect_clicked);
}

void Dialog::setConnectMatrixBtn(QString text, int x, int y, int width, int hight, QString image)
{
    connectMatrix = new QPushButton(this);
    connectMatrix->setText(text);
    connectMatrix->setGeometry(QRect(x, y, width, hight));
    connectMatrix->setStyleSheet(image);
    connect(connectMatrix, &QPushButton::clicked, this, &Dialog::connectMatrix_clicked);
}

void Dialog::setConnectEdgeBtn(QString text, int x, int y, int width, int hight, QString image)
{
    connectEdge = new QPushButton(this);
    connectEdge->setText(text);
    connectEdge->setGeometry(QRect(x, y, width, hight));
    connectEdge->setStyleSheet(image);
    connect(connectEdge, &QPushButton::clicked, this, &Dialog::connectEdge_clicked);
}

void Dialog::setFloydBtn(QString text, int x, int y, int width, int hight, QString image)
{
    floydBtn = new QPushButton(this);
    floydBtn->setText(text);
    floydBtn->setGeometry(QRect(x, y, width, hight));
    floydBtn->setStyleSheet(image);
    connect(floydBtn, &QPushButton::clicked, this, &Dialog::floyd_clicked);
}

void Dialog::setVertexNumLe(QString echoText, int x, int y, int width, int hight)
{
    vertexNumLe = new QLineEdit(this);
    vertexNumLe->setPlaceholderText(echoText);
    vertexNumLe->setGeometry(QRect(x, y, width, hight));
    vertexNumLe->setFocus();
}

void Dialog::setVertexNameLe(QString echoText, int x, int y, int width, int hight)
{
    vertexNameLe = new QLineEdit(this);
    vertexNameLe->setPlaceholderText(echoText);
    vertexNameLe->setGeometry(QRect(x, y, width, hight));
}

void Dialog::setEdgeNumLe(QString echoText, int x, int y, int width, int hight)
{
    edgeNumLe = new QLineEdit(this);
    edgeNumLe->setPlaceholderText(echoText);
    edgeNumLe->setGeometry(QRect(x, y, width, hight));
}

void Dialog::setV1(QString echoText, int x, int y, int width, int hight)
{
    v1 = new QLineEdit(this);
    v1->setPlaceholderText(echoText);
    v1->setGeometry(QRect(x, y, width, hight));
}

void Dialog::setV2(QString echoText, int x, int y, int width, int hight)
{
    v2 = new QLineEdit(this);
    v2->setPlaceholderText(echoText);
    v2->setGeometry(QRect(x, y, width, hight));
}

void Dialog::setEveryEdge(QString echoText, int x, int y, int width, int hight)
{
    everyEdge = new QPlainTextEdit(this);
    everyEdge->setPlaceholderText(echoText);
    everyEdge->setGeometry(QRect(x, y, width, hight));
}

void Dialog::setOutput(QString outputText, int x, int y, int width, int hight)
{
    output = new QTextBrowser(this);
    output->setGeometry(QRect(x, y, width, hight));
    output->setPlainText(outputText);
    //output->set
    //output->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

QString Dialog::getText()
{
    return vertexNumLe->text();
}

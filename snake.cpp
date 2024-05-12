#include "snake.h"
#include "ui_snake.h"
#include <qrect.h>
#include <qtimer.h>
#include <QKeyEvent>
#include <QRandomGenerator>
Snake::Snake(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Snake),blsRun(false),speed(500)
{
    ui->setupUi(this);
    this->setGeometry(QRect(600,300,290,310));
}

Snake::~Snake()
{
    delete ui;
}
void Snake::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    if(!blsRun){
    InitSnake();
    }
    painter.setPen(Qt::black);
    painter.setBrush(Qt::gray);
    painter.drawRect(15,15,260,260);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawRect(20,20,250,250);
    painter.drawPixmap(20,20,250,250,QPixmap(":/myimage/images/download.jpg"));
    painter.setPen(Qt::blue);
    for(int i=0;i<=27;i++){
        painter.drawLine(20,i*10,270,i*10);
        painter.drawLine(i*10,20,i*10,270);
    }
    QFont font1("Courier",24);
    painter.setFont(font1);
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);
    painter.drawText(40,150,sDisplay);
    QFont font2("Courier",15);
    painter.setFont(font2);
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::blue);
    painter.drawText(140,300,scoreLabel);
    painter.drawText(230,300,QString::number(nScore));
    painter.setPen(Qt::black);
    painter.setBrush(Qt::green);
    painter.drawRect(food);
    painter.drawRects(&vSnakeRect[0],vSnakeRect.size());
    if(blsOver)
        timer->stop();
}
void Snake::InitSnake(){
    nDirection=2;
    blsRun=true;
    blsOver=false;
    sDisplay="游戏开始";
    scoreLabel="得分";
    nScore=0;
    food=CreateRect();
    vSnakeRect.resize(5);
    for(int i=0;i<vSnakeRect.size();i++){
            QRect rect(100,70+10*i,10,10);//生成小方块
            vSnakeRect[vSnakeRect.size()-1-i]=rect;//小方块赋值到容器
    }
    timer=new QTimer(this);
     SnakeHead=vSnakeRect.first();
    timer->start(speed);
    connect(timer,SIGNAL(timeout()),SLOT(Snake_update()));
    }
void Snake::keyPressEvent(QKeyEvent *event){
    QKeyEvent *key=(QKeyEvent*)event;
    switch(key->key()){
    case Qt::Key_Up:nDirection=1;
        break;
    case Qt::Key_Down:nDirection=2;
        break;
    case Qt::Key_Left:nDirection=3;
        break;
    case Qt::Key_Right:nDirection=4;
        break;
    default:;
    }
}
void Snake::Snake_update(){
    sDisplay="";
    SnakeHead=vSnakeRect.first();
    IsEat();
    IsHit();
    for(int j=0;j<vSnakeRect.size()-1;j++){
        vSnakeRect[vSnakeRect.size()-1-j]=vSnakeRect[vSnakeRect.size()-2-j];
    }
    switch(nDirection)
    {
    case 1:
        SnakeHead.setTop(SnakeHead.top()-10);
         SnakeHead.setBottom(SnakeHead.bottom()-10);
        break;
    case 2:
        SnakeHead.setTop(SnakeHead.top()+10);
         SnakeHead.setBottom(SnakeHead.bottom()+10);
        break;
    case 3:
        SnakeHead.setLeft(SnakeHead.left()-10);
         SnakeHead.setRight(SnakeHead.right()-10);
        break;
    case 4:
        SnakeHead.setLeft(SnakeHead.left()+10);
         SnakeHead.setRight(SnakeHead.right()+10);
        break;
    default:;
    }
    vSnakeRect[0]=SnakeHead;
    if(SnakeHead.left()<20||SnakeHead.right()>270||SnakeHead.top()<20 || SnakeHead.bottom()>270){
            sDisplay="游戏结束";
            blsOver=true;
    }
      update();
}
QRect Snake::CreateRect(){
    int x,y;
    x=QRandomGenerator::global()->bounded(0,1000)%25;
    y=QRandomGenerator::global()->bounded(0,1000)%25;
    QRect rect(20+x*10,20+y*10,10,10);
    return rect;
}
void Snake::IsEat(){
    if(SnakeHead==food){
        SnakeHead=food;
        vSnakeRect.push_back(vSnakeRect.last());
        food=CreateRect();
        nScore+=10;
        if(speed>50){
            speed=speed-10;
            timer->stop();
            timer->start(speed);
        }
    }
}
void Snake::IsHit(){
    for(int i=1;i<vSnakeRect.size();i++){
        if(SnakeHead==vSnakeRect[i]){
            sDisplay="游戏结束";
            blsOver=true;
            update();
        }
    }
}


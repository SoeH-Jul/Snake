#ifndef SNAKE_H
#define SNAKE_H
#include <QMainWindow>
#include<qpainter.h>
#include<QVector>
#include<qstring.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Snake; }
QT_END_NAMESPACE

class Snake : public QMainWindow
{
    Q_OBJECT

public:
    Snake(QWidget *parent = nullptr);
    ~Snake();
    void paintEvent(QPaintEvent *event);
    void InitSnake();
    QRect CreateRect();
    void IsEat();
    void IsHit();

private slots:
    void Snake_update();

private:
    Ui::Snake *ui;
    QVector<QRect> vSnakeRect;
    QRect SnakeHead;
    void keyPressEvent(QKeyEvent *key);
    QTimer *timer;
    bool blsRun;
    bool blsOver;
    QString sDisplay;
    int nDirection;
    QRect food;
    int nScore;
    QString scoreLabel;
    int speed;
};
#endif // SNAKE_H

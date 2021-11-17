#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sceneLb = new QGraphicsScene(0,0,500,350,this);
    ui->graphicsView->setScene(sceneLb);
    Polygonal = new polygonal();
    Polygonal->pen.setColor(Qt::black);
    Polygonal->brush.setStyle(Qt::SolidPattern);
}
void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        Polygonal->topsList.append(event->pos());
        sceneLb->addRect(event->pos().x(),event->pos().y(),1,1);
    }
    if(event->button() == Qt::RightButton){
        sceneLb->clear();
        for(int i = 0; i < Polygonal->topsList.length(); ++i){
            if(Polygonal->topsList.length() == i+1){
                sceneLb->addLine(Polygonal->topsList[i].x(),Polygonal->topsList[i].y(),
                               Polygonal->topsList[0].x(),Polygonal->topsList[0].y());
                break;
            }
            sceneLb->addLine(Polygonal->topsList[i].x(),Polygonal->topsList[i].y(),
                           Polygonal->topsList[i+1].x(),Polygonal->topsList[i+1].y());
        }
            polygonFillingScanLine(Polygonal, sceneLb);
            Polygonal->topsList.clear();
    }
}
void polygonFillingScanLine(polygonal *pol, QGraphicsScene *scene){
    QTransform trans;
    QGraphicsItem *tempItem;
    QVector<int> xPos;
    QMultiMap<int,int> yKey;
    int yMin = pol->topsList[0].y();
    int yMax = pol->topsList[0].y();
    int xMax = pol->topsList[0].x();
    int xMin = pol->topsList[0].x();
    //ищем максимальный и минимальный x,y(стартовые координаты)
    for(int i = 1; i < pol->topsList.length(); ++i){
        if(pol->topsList[i].y() < yMin){
            yMin = pol->topsList[i].y();
        }
        if(pol->topsList[i].x() < xMin){
            xMin = pol->topsList[i].x();
        }
        if(pol->topsList[i].y() > yMax){
            yMax = pol->topsList[i].y();
        }
        if(pol->topsList[i].x() > xMax){
            xMax = pol->topsList[i].x();
        }
    }

    for(int i = 0; i < pol->topsList.length(); ++i){
        yKey.insert(pol->topsList[i].y(),pol->topsList[i].x());
    }
    tempItem = scene->itemAt(xMin,yMax,trans);
    static int count = 0;

    for(int y = yMin; y <= yMax; y++){//заполним массив пересечениями

        for(int x = xMin; x <= xMax; ++x){
            if(scene->itemAt(x,y,trans)){
                //не добавляем пиксели от одной и той же линии
                if(scene->itemAt(x,y,trans) == tempItem){
                    if(!xPos.isEmpty()){
                        xPos.pop_back();
                    }
                }
                tempItem = scene->itemAt(x,y,trans);
                xPos.append(x);
                continue;
            }
        }

            for(int i = 0; i < xPos.length(); ++i){

            }

        //используем правило чет-нечет, для определения внутри ли точка
        bool startWithTop = yKey.contains(y,xPos[0]);
        //bool meetTop = 0;
        for(int i = 0; i+1 < xPos.length(); ++i){
            if(startWithTop){
                //начало с вершины и нужно закрашивать с чет
                if(xPos.length()%2==0){
                    if(i%2){
                        continue;
                    }else{

                        scene->addLine(xPos[i],y,xPos[i+1],y);
                        continue;
                    }
                }
                if(xPos.length()%2==1){
                //начало с вершины и нужно закрашивать с нечет
                    if(i%2){

                        scene->addLine(xPos[i],y,xPos[i+1],y);
                        continue;
                    }else{
                        continue;
                    }
                }
            }else{

                if(xPos.length()%2==0){
                    if(i%2){
                        continue;
                    }else{

                        scene->addLine(xPos[i],y,xPos[i+1],y);
                        continue;
                    }
                 }
                if(xPos.length()%2==1){
                    if(i%2){
                        if(yKey.contains(y,xPos[i])){

                            scene->addLine(xPos[i],y,xPos[i+1],y);
                            continue;
                        }
                        continue;
                    }else{

                        scene->addLine(xPos[i],y,xPos[i+1],y);
                        continue;
                    }
                }
            }

        }
        //задержка
        QTimer timer;
        QEventLoop loop;
        timer.setInterval(10); //1000 = 1 sec
        MainWindow::connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
        timer.start();
        loop.exec();
        xPos.clear();
    }
    count = 0;
    yKey.clear();
}
MainWindow::~MainWindow()
{
    delete ui;
}

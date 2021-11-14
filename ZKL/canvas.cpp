#include "canvas.h"
#include "mainwindow.h"
#include <QComboBox>
#include <QStringList>
#include <QColor>
#include <QPoint>
#include <QGraphicsItem>
#include <QPolygonF>
#include <QLine>
#include <QVector>

/* this->clearSelection();  //СОХРАНЕНИЕ КАРТИНКИ
    this->setSceneRect(this->itemsBoundingRect());
    QImage image(this->sceneRect().size().toSize(), QImage::Format_ARGB32);
    image.fill(Qt::transparent);
    QPainter _painter(&image);
    this->render(&_painter);
    image.save("C:\\Users\\Pavel\\Desktop\\ТУСУР\\2 Курс\\ППННИРР\\pract_proj\\file_name.png"); */

    //ЗАГРУЗКА КАРТИНКИ
  /*  QImage image("C:\\Users\\Pavel\\Desktop\\ТУСУР\\2 Курс\\ППННИРР\\pract_proj\\file_name.png");  // Create the image with the exact size of the shrunk scene
    //image.fill(Qt::transparent);
    QGraphicsPixmapItem item(QPixmap::fromImage(image));
    this->addPixmap(QPixmap::fromImage(image) );
    //QGraphicsScene* scene = new QGraphicsScene;
    //this->addItem(&item); */

Canvas::Canvas(QObject *parent) : QGraphicsScene(parent)
{
    //this->set
    //rubberBand = nullptr;
    //rubberBand = new QRubberBand(QRubberBand::Rectangle);
    pen->setColor(Qt::black);
    pen->setStyle(Qt::SolidLine);
    pen->setCapStyle(Qt::RoundCap);
    pen->setWidth(1);
}

Canvas::~Canvas()
{
}

void Canvas::loadPicture(QString path)
{
    QImage image(path);  // Create the image with the exact size of the shrunk scene
    image.fill(Qt::transparent);
    QGraphicsPixmapItem item(QPixmap::fromImage(image));
    //this->addPixmap(QPixmap::fromImage(image));
    addItem(&item);
}

void Canvas::setToolLine()
{
    chosenInstrument = 1;
}

void Canvas::setToolRays()
{
    chosenInstrument = 3;
}

/*void Canvas::copySceneAsIMG()
{
    this->clearSelection();                                                  // Selections would also render to the file
    //this->setSceneRect(this->itemsBoundingRect());                          // Re-shrink the scene to it's bounding contents
    //QImage image(this->sceneRect().size().toSize(), QImage::Format_ARGB32);  // Create the image with the exact size of the shrunk scene
//    canvasCopy.copy(0, 0, this->width(), this->height());
    canvasCopy.fill(Qt::transparent);
} */

void Canvas::setSize(int size)
{
    pen->setWidth(size);
}


void Canvas::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    switch(chosenInstrument)
    {
    case 1: case 3: // кисть и лучи
        //MainWindow::wasEraser = false;
        //canvas->pen->setColor(canvas->previusColor);
        //pen->brush();
        pointsOfLine->append(event->scenePos().toPoint()); // Сохраняем координаты точки нажатия
        addEllipse(event->scenePos().x(), event->scenePos().y(), 1, 1, QPen(pen->color()));
        break;
   /* case 2:
        QGraphicsItem *item;
        break;
    case 3:
        break;
    default:
        break;*/
    }


   //rubberBand->setGeometry(1, 1, 10, 10);  //QRect(origin.toPoint(), QSize())
   // rubberBand->show();

}



void Canvas::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    switch (chosenInstrument)
    {
        case 1: // Рисование
            current_line = new QLine(pointsOfLine->last(), event->scenePos().toPoint());
            pointsOfLine->append(event->scenePos().toPoint());
            polyline->append(*current_line);
            addLine(*current_line, *pen);
            break;
        //case 2: // Ластик
            break;
        //case 3: // Прямоугольное выделение объекта
         //   rubberBand->setGeometry(mouseOnStartMoveXPosition, mouseOnStartMoveYPosition,
         //                           event->screenPos().x() - mouseOnStartMoveXPosition,
         //                           event->screenPos().y() - mouseOnStartMoveYPosition); //QRect(origin.toPoint(), event->scenePos().toPoint()).normalized()
            break;
       case 3: // лучи
            current_line = new QLine(pointsOfLine->last(), event->scenePos().toPoint());
            polyline->append(*current_line);
            addLine(*current_line, *pen);
            break;
        //default: // выбран какой-то другой инструмент
            break;
    }

    /*this->clearSelection();                                                  // Selections would also render to the file
    this->setSceneRect(this->itemsBoundingRect());                          // Re-shrink the scene to it's bounding contents
    QImage image(this->sceneRect().size().toSize(), QImage::Format_ARGB32);  // Create the image with the exact size of the shrunk scene
    image.fill(Qt::transparent);                                              // Start all pixels transparent
    QPainter _painter(&image);
    this->render(&_painter);
    image.save("file_name.png"); */

    //copySceneAsIMG();//
   // canvasCopy.save("file_name.png");

}



void Canvas::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    figures->append(*polyline);
    polyline->clear();
    //rubberBand->hide();
}

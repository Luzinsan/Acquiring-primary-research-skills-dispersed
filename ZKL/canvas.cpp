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
#include <QTransform>
#include <iostream>

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
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidth(1);
}

Canvas::~Canvas()
{
}
void Canvas::loadPicture(QString path)
{
    QGraphicsPixmapItem * image = new QGraphicsPixmapItem(QPixmap(path));
            int imageWidth = image->pixmap().width();
            int imageHeight = image->pixmap().height();
            image->setOffset(- imageWidth / 2, -imageHeight / 2);
            image->setPos(0, 0);
        this->addItem(image);
}
void Canvas::setToolLine()
{
    chosenInstrument = 1;
}
void Canvas::setToolFigure()
{
   chosenInstrument = 2;
}
void Canvas::setToolDuplication()
{
    if(duplication) duplication = false;
    else duplication = true;
}
void Canvas::setToolEraser()
{
   chosenInstrument = 3;
}

void Canvas::setRectangle()
{
    chosenFigure = 1;
}
void Canvas::setCircle()
{
    chosenFigure = 2;
}
void Canvas::setTriangle()
{
   chosenFigure = 3;
}
void Canvas::setTriangleRectangular()
{
    chosenFigure = 4;
}
void Canvas::setRhomb()
{
    chosenFigure = 5;
}
void Canvas::setTrapezoid()
{
    chosenFigure = 6;
}
void Canvas::setPentagon()
{
    chosenFigure = 7;
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
    pen.setWidth(size);
}

void Canvas::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    switch(chosenInstrument)
    {
    case 1: // кисть и дублирование
        wasEraser = false;
        pen.setBrush(currentColor);
        pointsOfLine->append(event->scenePos().toPoint()); // Сохраняем координаты точки нажатия
        addEllipse(event->scenePos().x(), event->scenePos().y(), 1, 1, pen);
        break;
    case 3: // ластик
        if(!wasEraser)
        {
            currentColor = pen.color();
            pen.setColor(Qt::white);
            wasEraser = true;
        }
        pointsOfLine->append(event->scenePos().toPoint()); // Сохраняем координаты точки нажатия
        addEllipse(event->scenePos().x(), event->scenePos().y(), 1, 1, pen);
        break;

    case 2:
        wasEraser = false;
        pen.setBrush(currentColor);
        if (mouseOnEndPressXPosition == -2)//bool - top left
            {
                mouseOnEndPressXPosition = -1;
                mouseOnEndPressYPosition = -1;
                x1 = event->scenePos().x();
                y1 = event->scenePos().y();
                figure =  new Figure(x1, y1,
                                     x1+1, y1+1,
                                     0,
                                     pen);
            } else
            {
                x2 = event->screenPos().x();
                y2 = event->screenPos().y();

                mouseOnEndPressXPosition = -2;
                mouseOnEndPressYPosition = -2;
            }
        break;

    default:
        break;
    }


}

void Canvas::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    switch (chosenInstrument)
    {
        case 1: // Рисование
            if(duplication)// лучи
            {
                current_line = new QLine(pointsOfLine->last(), event->scenePos().toPoint());
                polyline->append(*current_line);
                addLine(*current_line, pen);
                break;
            }
        case 3: // и ластик
            current_line = new QLine(pointsOfLine->last(), event->scenePos().toPoint());
            pointsOfLine->append(event->scenePos().toPoint());
            polyline->append(*current_line);
            addLine(*current_line, pen);
            break;
        case 2: // фигура
            if(!duplication)
                figure->~Figure();
            x2 = event->scenePos().x();
            y2 = event->scenePos().y();
            figure =  new Figure(x1, y1,
                                 x2, y2,
                                 chosenFigure,
                                 pen);
            addItem(figure);
            break;


        default: // выбран какой-то другой инструмент
            break;
    }
}


void Canvas::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);

    switch (chosenInstrument)
    {
        case 1: // Рисование
        if(duplication)// лучи
        {
            current_line = new QLine(pointsOfLine->last(), event->scenePos().toPoint());
            polyline->append(*current_line);
            addLine(*current_line, pen);
        }
        else
        {
            polylines->append(*polyline);
            polyline->clear();
        }
        break;
        case 2: // фигура
            mouseOnEndPressXPosition = -2;
            figures.append(figure);
            figure = nullptr;
            break;
       case 3:
            polyline->clear();
        default: // выбран какой-то другой инструмент
            break;
    }
}

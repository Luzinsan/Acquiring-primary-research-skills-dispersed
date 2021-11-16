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

void Canvas::setToolRays()
{
    chosenInstrument = 3;
}


void Canvas::setToolFigure()
{
   chosenInstrument = 2;
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
    pen->setWidth(size);
}

void Canvas::drawRectangle()
{
    addRect(x1, y1, x2 - x1, y2 - y1, *pen);
}
void Canvas::drawCircle()
{
    addEllipse(QRect(x1, y1, x2 - x1, y2 - y1), *pen);
}

void Canvas::drawTriangle()
{
    addLine(x1, y2, (x1 + x2) / 2, y1, *pen);

    addLine(x2, y2, (x1 + x2) / 2, y1, *pen);

    addLine(x1, y2, x2, y2, *pen);
}

void Canvas::drawTriangleRectangular()
{
    addLine(x1, y2, x1, y1, *pen);

    addLine(x1, y2, x2, y2, *pen);

    addLine(x1, y1, x2, y2, *pen);
}
void Canvas::drawRhomb()
{
    qreal cW, cH;

    if ((x1 >= 0  && x2 <= 0) || (x1 <= 0 && x2 >= 0))
        cW = abs((abs(x1) + abs(x2))) / 2 + x1;
    else
        cW = abs((abs(x2) - abs(x1))) / 2 + x1;

    if ((y1 >= 0  && y2 <= 0) || (y1 <= 0 && y2 >= 0))
        cH = abs((abs(y1) + abs(y2))) / 2 + y1;
    else
        cH = abs((abs(y2) - abs(y1))) / 2 + y1;

    addLine(x1, cH, cW, y1, *pen);

    addLine(cW, y1, x2, cH, *pen);

    addLine(x2, cH, cW, y2, *pen);

    addLine(cW, y2, x1, cH, *pen);
}
void Canvas::drawTrapezoid()
{
    qreal len;

    qreal coeff = 0.25;

    if ((x1 >= 0  && x2 <= 0) || (x1 <= 0 && x2 >= 0))
        len = (abs(x1)+abs(x2)) * coeff;
    else
        len = (abs(x2) - abs(x1)) * coeff;

     addLine(x1, y2, x2, y2, *pen);

     addLine(x1, y2, x1 + len, y1, *pen);

     addLine(x1 + len, y1, x2 - len, y1, *pen);

     addLine(x2 - len, y1, x2, y2, *pen);
}

void Canvas::drawPentagon()
{
    qreal shift, uShift, coeff = 0.25, uCoeff = 0.35;

    qreal cW, cH;

    if ((x1 >= 0  && x2 <= 0) || (x1 <= 0 && x2 >= 0))
        cW = abs((abs(x1) + abs(x2))) / 2 + x1;
    else
        cW = abs((abs(x2) - abs(x1))) / 2 + x1;

    if ((x1 >= 0  && x2 <= 0) || (x1 <= 0 && x2 >= 0))
        shift = ((abs(x1) + abs(x2))) * coeff;
    else
        shift = abs((abs(x2) - abs(x1))) * coeff;

    if ((y1 >= 0  && y2 <= 0) || (y1 <= 0 && y2 >= 0))
        uShift = abs((abs(y1) + abs(y2))) * uCoeff;
    else
        uShift = abs((abs(y2) - abs(y1))) * uCoeff;

    addLine(x1 + shift, y2, x2 - shift, y2, *pen);

    addLine(x2 - shift, y2, x2, y1 + uShift, *pen);

    addLine(x2, y1 + uShift, cW, y1, *pen);

    addLine(cW, y1, x1, y1 + uShift, *pen);

    addLine(x1, y1 + uShift, x1 + shift, y2, *pen);
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
    case 2:
        if (mouseOnEndPressXPosition == -2)
            {
                x1 = event->scenePos().x();
                y1 = event->scenePos().y();
                mouseOnEndPressXPosition = -1;
                mouseOnEndPressYPosition = -1;
            } else
                if (mouseOnEndPressXPosition == -1)
                {
                    x2 = event->scenePos().x();
                    y2 = event->scenePos().y();

                    switch (chosenFigure)
                    {
                    case 1:
                        drawRectangle();
                        break;
                    case 2:
                        drawCircle();
                        break;
                    case 3:
                        drawTriangle();
                        break;
                    case 4:
                        drawTriangleRectangular();
                        break;
                    case 5:
                        drawRhomb();
                        break;
                    case 6:
                        drawTrapezoid();
                        break;
                    case 7:
                        drawPentagon();
                        break;
                    }

                    mouseOnEndPressXPosition = -2;
                    mouseOnEndPressYPosition = -2;
                }
        break;
    /*case 3:
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

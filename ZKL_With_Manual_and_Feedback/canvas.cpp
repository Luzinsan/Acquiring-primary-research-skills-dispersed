#include "canvas.h"
#include "mainwindow.h"
#include <QComboBox>
#include <QStringList>
#include <QColor>
#include <QPen>
#include <QPoint>
#include <QGraphicsItem>
#include <QPolygonF>
#include <QLine>
#include <QVector>
#include <QTransform>
#include <QInputDialog>
#include <QFileDialog>

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

void Canvas::savePicture(QString path)
{
    QString file = path;

    const qreal width = this->width();
    const qreal height = this->height();
        QImage image(width, height, QImage::Format_ARGB32);
        image.fill(Qt::transparent);
        QPainter _painter(&image);
        this->render(&_painter);
        image.save(file);
}

void Canvas::setSolidLine()
{
    pen.setStyle(Qt::SolidLine);
}
void Canvas::setDashLine()
{
    pen.setStyle(Qt::DashLine);
}
void Canvas::setDotLine()
{
    pen.setStyle(Qt::DotLine);
}
void Canvas::setDashDotLine()
{
    pen.setStyle(Qt::DashDotLine);
}
void Canvas::setDashDotDotLine()
{
    pen.setStyle(Qt::DashDotDotLine);
}
void Canvas::setCustomLine()
{
    QVector<qreal> dashes;
    qreal space = 10*pen.width();
    dashes << 1 << space;
    pen.setCosmetic(true);
    pen.setMiterLimit(5);
    pen.setDashPattern(dashes);
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
    duplication = !duplication;
}
void Canvas::setToolText()
{
   chosenInstrument = 4;
}
void Canvas::setToolEraser()
{
   chosenInstrument = 3;
}

void Canvas::setLine()
{
    chosenFigure = 1;
}
void Canvas::setRectangle()
{
    chosenFigure = 2;
}
void Canvas::setCircle()
{
    chosenFigure = 3;
}
void Canvas::setTriangle()
{
    chosenFigure = 4;
}
void Canvas::setTriangleRectangular()
{
    chosenFigure = 5;
}
void Canvas::setRhomb()
{
    chosenFigure = 6;
}
void Canvas::setTrapezoid()
{
    chosenFigure = 7;
}
void Canvas::setPentagon()
{
    chosenFigure = 8;
}

void Canvas::setSize(int size)
{
    pen.setWidth(size);
}


void Canvas::deleteAll()
{
    clear();
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
                x2 = event->scenePos().x();
                y2 = event->scenePos().y();

                mouseOnEndPressXPosition = -2;
                mouseOnEndPressYPosition = -2;
            }
        break;

    case 4:
    {
        //if(!this->itemAt(event->scenePos().toPoint(),QTransform()))
        //{
            x1=event->scenePos().x();
            y1=event->scenePos().y();
            bool ok=true;
            QString text = QInputDialog::getMultiLineText(event->widget(),
                                                          tr("Введите текст"),
                                                          tr("Текст: "),
                                                          "Приятного времени суток\nВводите здесь свой текст ;)",
                                                          &ok);
            this->addSimpleText(text)->moveBy(event->scenePos().x(),event->scenePos().y());
        //}


        break;
    }
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
            if (x2 < x1 && y2 < y1)
                figure =  new Figure(x2, y2,
                                     x1, y1,
                                     chosenFigure,
                                     pen);
            else
                if (x2 < x1)
                    figure =  new Figure(x2, y1,
                                         x1, y2,
                                         chosenFigure,
                                         pen);
            else
                if (y2 < y1)
                    figure =  new Figure(x1, y2,
                                         x2, y1,
                                         chosenFigure,
                                         pen);
            else
                figure =  new Figure(x1, y1,
                                     x2, y2,
                                     chosenFigure,
                                     pen);
            addItem(figure);
            break;
        //case 4:

            //this->itemAt(QPoint(x1,y1),QTransform())->setPos(event->scenePos().toPoint());

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

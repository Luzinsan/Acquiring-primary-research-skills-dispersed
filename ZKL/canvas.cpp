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
#include <QFont>
#include <QGraphicsSimpleTextItem>
#include <QBrush>



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

void Canvas::savePicture(QString path)
{
    QString file = path;


    //this->clearSelection();  //СОХРАНЕНИЕ КАРТИНКИ
        //this->setSceneRect(this->itemsBoundingRect());
    const qreal width = this->width();
    const qreal height = this->height();
        QImage image(width, height, QImage::Format_ARGB32);
        image.fill(Qt::transparent);
        QPainter _painter(&image);
        this->render(&_painter);
        //background->~Figure();
        //background = nullptr;
        image.save(file);


   /* if (!file.isEmpty()) {
        //const QGraphicsScene *cur = scene();
        const qreal width = this->width();
        const qreal height = this->height();
        QImage image(width, height, QImage::Format_RGB888);
        QPainter painter(&image);
        painter.setRenderHint(QPainter::Antialiasing);
        this->render(&painter, QRectF(0, 0, width, height), QRect(0, 0, width, height));
        image.save(file); */
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
void Canvas::setBackground()
{
    clear();
    chosenFigure = 9;

    background =  new Figure(0, 0,
                         width()-1, height()-1,
                         chosenFigure,
                         pen);

    addItem(background);
    background = nullptr;
}

void Canvas::drawGridLines()
{
    QPen background_pen = pen;
    widthGrid = pen.width()+1;
    pen.setWidth(1);
    for(int i = 0; i < this->height(); i += widthGrid)
        this->addLine(0, i, width(), i, pen);
    pen.setWidth(background_pen.width());
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
                //figure->setCursor(Qt::IBeamCursor);

            } else
            {
                x2 = event->scenePos().x();
                y2 = event->scenePos().y();

                mouseOnEndPressXPosition = -2;
                mouseOnEndPressYPosition = -2;
            }
        //if(this->itemAt(event->scenePos(), QTransform()))

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
            QFont font;
            font.setPixelSize(widthGrid-5);
            font.setStyleHint(QFont::SansSerif);
            QGraphicsSimpleTextItem *textItem = this->addSimpleText(text, font);
            textItem->setBrush(pen.brush());
            textItem->moveBy(event->scenePos().x(),event->scenePos().y());
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
            figure =  new Figure(x1, y1,
                                 x2, y2,
                                 chosenFigure,
                                 pen);

            /*
            if (x2 < x1 && y2 < y1)
                figure =  new Figure(x2, y2,
                                     x1, y1,
                                     chosenFigure,
                                     pen);
            else if (x2 < x1)
                figure =  new Figure(x2, y1,
                                     x1, y2,
                                     chosenFigure,
                                     pen);
            else if (y2 < y1)
                figure =  new Figure(x1, y2,
                                     x2, y1,
                                     chosenFigure,
                                     pen);
            else
                figure =  new Figure(x1, y1,
                                     x2, y2,
                                     chosenFigure,
                                     pen);
            */

            addItem(figure);
            //figure->update();

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

            //figure->unsetCursor();
            figure = nullptr;
            break;
       case 3:
            polyline->clear();
        default: // выбран какой-то другой инструмент
            break;
    }
}

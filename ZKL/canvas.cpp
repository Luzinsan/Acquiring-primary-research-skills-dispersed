#include "canvas.h"
#include <QComboBox>
#include <QStringList>
#include <QColor>

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

/* ===============================================================
 *
 * ========== НИЖЕ КОНСТРУКТОР И ДЕСТРУКТОР ХОЛСТА ===============
 *
 * ===============================================================
 */

Canvas::Canvas(QObject *parent) : QGraphicsScene(parent)
{
    //this->set
    //rubberBand = nullptr;
    rubberBand = new QRubberBand(QRubberBand::Rectangle);
    pen = new QPen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap);
}

Canvas::~Canvas()
{
    delete rubberBand;
    delete pen;
}

void Canvas::loadPicture(QString path)
{
    QImage image(path);  // Create the image with the exact size of the shrunk scene
    image.fill(Qt::transparent);
    QGraphicsPixmapItem item(QPixmap::fromImage(image));
    //this->addPixmap(QPixmap::fromImage(image));
    addItem(&item);
}

/* ===============================================================
 *
 * ========== НИЖЕ РЕДАКТИРОВАНИЕ ВЫДЕЛЕННОЙ ОБЛАСТИ =============
 *
 * ===============================================================
 */

void Canvas::copySceneAsIMG()
{
    this->clearSelection();                                                  // Selections would also render to the file
    this->setSceneRect(this->itemsBoundingRect());                          // Re-shrink the scene to it's bounding contents
    QImage image(this->sceneRect().size().toSize(), QImage::Format_ARGB32);  // Create the image with the exact size of the shrunk scene
    canvasCopy = image;
    canvasCopy.fill(Qt::transparent);
}

void Canvas::cropImage()
{
    copySceneAsIMG();

    croppedImage = canvasCopy.copy(highlighterCoords);
}


/* ===============================================================
 *
 * ========== НИЖЕ ФУНКЦИИ ДЛЯ НАСТРОЙКИ ИНСТРУМЕНТОВ ============
 *
 * ===============================================================
 */

void Canvas::setChosenInstrument(int id)
{
    chosenInstrument = id;
}

void Canvas::setSize(int size)
{
    pen->setWidth(size);
}


/* ===============================================================
 *
 * ===== НИЖЕ ФУНКЦИИ ДЛЯ ОТОБРАЖЕНИЯ ИНФОРМАЦИИ НА ХОЛСТЕ =======
 *
 * ===============================================================
 */

void Canvas::drawLine(int x, int y)
{
    // Отрисовываем линии с использованием предыдущей координаты
    addLine(previousPoint.x(),
            previousPoint.y(),
            x,
            y,
            *pen);
}

// =============== ТРЕУГОЛЬНИК ===================
/*
 * addLine(x1, y2, (x1 + x2) / 2, y1, *pen);

   addLine(x2, y2, (x1 + x2) / 2, y1, *pen);

   addLine(x1, y2, x2, y2, *pen);
 */


// =============== ПРЯМОУГОЛЬНЫЙ ТРЕУГОЛЬНИК ===================
/*
 * addLine(x1, y2, x1, y1, *pen);

   addLine(x1, y2, x2, y2, *pen);

   addLine(x1, y1, x2, y2, *pen);
 */


// =============== ТРАПЕЦИЯ ===================
/*
 * qreal len;

            if ((x1 >= 0  && x2 <= 0) || (x1 <= 0 && x2 >= 0))
                len = (abs(x1)+abs(x2)) * coeff;
            else
                len = (abs(x2) - abs(x1)) * coeff;

            addLine(x1, y2, x2, y2, *pen);

            addLine(x1, y2, x1 + len, y1, *pen);

            addLine(x1 + len, y1, x2 - len, y1, *pen);

            addLine(x2 - len, y1, x2, y2, *pen);
 */


// =============== РОМБ ===================
/*
 * qreal cW, cH;

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

 */

/* ===============================================================
 *
 * ===================== НИЖЕ MOUSE EVENT'Ы ======================
 *
 * ===============================================================
 */

void Canvas::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);

    highlighterCoords.setCoords(mouseOnPressXPosition, mouseOnPressYPosition,
                                event->screenPos().x(),event->screenPos().y());



    mouseOnStartMoveXPosition = -1;
    mouseOnStartMoveYPosition = -1;
    //rubberBand->hide();


}

void Canvas::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    mouseOnPressXPosition = event->scenePos().x();
    mouseOnPressYPosition = event->scenePos().y();

    qreal coeff = 0.25, uCoeff = 0.35;

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

            qreal shift, uShift;

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

                        addLine(x2, y1 + uShift, x1 + shift, y1, *pen);

                        addLine(x1 + shift, y1, x1, y1 + uShift, *pen);

                        addLine(x1, y1 + uShift, x1 + shift, y2, *pen);

            mouseOnEndPressXPosition = -2;
            mouseOnEndPressYPosition = -2;
        }


    printf("x = %d, y = %d\n", mouseOnPressXPosition, mouseOnPressYPosition);


    /*addEllipse(event->scenePos().x(),
               event->scenePos().y(),
               pen->width(),
               pen->width(),
               *pen); */
    // Сохраняем координаты точки нажатия
    previousPoint = event->scenePos();

   origin = event->pos();
        //if (!rubberBand)
        //    rubberBand = new QRubberBand(QRubberBand::Rectangle);
        rubberBand->setGeometry(1, 1, 10, 10);  //QRect(origin.toPoint(), QSize())
        rubberBand->show();
   //copySceneAsIMG();
}

void Canvas::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (mouseOnStartMoveXPosition == -1 && mouseOnStartMoveYPosition == -1) {
        mouseOnStartMoveXPosition = event->screenPos().x();
        mouseOnStartMoveYPosition = event->screenPos().y();
    }
    switch (chosenInstrument)
    {
        case 0: // Рисование
            drawLine(event->scenePos().x(), event->scenePos().y());
            break;
        case 1: // Ластик
            break;
        case 2: // Прямоугольное выделение объекта
                // Надо еще предусмотреть вариант, когда
                // текущая позиция имеет меньшие значения координат,
                // чем начальные
            rubberBand->setGeometry(mouseOnStartMoveXPosition, mouseOnStartMoveYPosition,
                                    event->screenPos().x() - mouseOnStartMoveXPosition,
                                    event->screenPos().y() - mouseOnStartMoveYPosition); //QRect(origin.toPoint(), event->scenePos().toPoint()).normalized()
            break;
        default: // выбран какой-то другой инструмент
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


    // Обновляем данные о предыдущей координате
    previousPoint = event->scenePos();
}

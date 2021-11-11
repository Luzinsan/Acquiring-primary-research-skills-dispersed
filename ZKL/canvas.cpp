#include "canvas.h"
#include <QComboBox>
#include <QStringList>

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
    rubberBand = new QRubberBand(QRubberBand::Rectangle);
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

void Canvas::setChosenInstrument(int id)
{
    chosenInstrument = id;
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
    // Сигнал activated() нашего QComboBox подключается к слоту setText() метки.
    // Поскольку сигнал перегружен,
    // то мы делаем статическое преобразование данных при помощи оператора static_cast:
    //connect(combo, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::activated),
   //         pen, static_cast<void(QPen::*)(int)>(&QPen::setWidth));
}

void Canvas::drawLine(int x, int y)
{
    // Отрисовываем линии с использованием предыдущей координаты
    addLine(previousPoint.x(),
            previousPoint.y(),
            x,
            y,
            *pen);
}

void Canvas::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    mouseOnStartMoveXPosition = -1;
    mouseOnStartMoveYPosition = -1;
    //rubberBand->hide();
}

void Canvas::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    mouseOnPressXPosition = event->screenPos().x();
    mouseOnPressYPosition = event->screenPos().y();

    printf("x = %d, y = %d\n", mouseOnPressXPosition, mouseOnPressYPosition);

    addEllipse(event->scenePos().x(),
               event->scenePos().y(),
               pen->width(),
               pen->width(),
               *pen);
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

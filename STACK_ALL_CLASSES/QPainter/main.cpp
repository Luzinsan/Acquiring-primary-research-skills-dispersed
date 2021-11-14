#include "mainwindow.h"
#include "calculator.h"
#include "keypress.h"
#include "move.h"
#include "disconnect.h"
#include "timer.h"
#include "label.h"
#include "slider.h"
#include "combobox.h"
#include "spinbox.h"
#include "ledit.h"
#include "statusbar.h"
#include "checkbox.h"
#include "listwidget.h"
#include "progressbarex.h"
#include "pixmap.h"
#include "splitter.h"
#include "table.h"

#include <QLocale>
#include <QTranslator>

#include <QGridLayout>
#include <QFrame>
#include <QIcon>
#include "plusminus.h"
#include "simplemenu.h"


class Cursors : public QWidget
{
public:
    Cursors(QWidget *parent = 0): QWidget(parent)
    {
        QFrame *frame1 = new QFrame(this);// создаем виджет
        frame1->setFrameStyle(QFrame::Box);// устанавливаем рамки фрейма
        frame1->setCursor(Qt::SizeAllCursor); // задаем тип курсора SizeAllCursor для фрейма

        QFrame *frame2 = new QFrame(this);// создаем виджет
        frame2->setFrameStyle(QFrame::Box);// устанавливаем рамки фрейма
        frame2->setCursor(Qt::WaitCursor); // задаем тип курсора WaitCursor для фрейма

        QFrame *frame3 = new QFrame(this);// создаем виджет
        frame3->setFrameStyle(QFrame::Box);// устанавливаем рамки фрейма
        frame3->setCursor(Qt::PointingHandCursor); // задаем тип курсора PointingHandCursor для фрейма


        // Группируем все фреймы в одну строку
        QGridLayout *grid = new QGridLayout(this);
        grid->addWidget(frame1, 0, 0);
        grid->addWidget(frame2, 0, 1);
        grid->addWidget(frame3, 0, 2);

        setLayout(grid);

    }

};

class MyButton : public Cursors
{
public:
    MyButton(Cursors *parent = 0): Cursors(parent)
    {
        QPushButton *quitBtn = new QPushButton("Quit", this);// создаем новую кнопку
        quitBtn->setGeometry(100,40,100,30);// изменяем размеры кнопки в пикселях и помещаем на форму окна

        connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
    }
};

int main(int argc, char *argv[])
{
    // Каждое Qt5-приложение (за исключением консольных) должно включать следующую строку
    QApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "QPainter_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    // Главный виджет, который представляет окно нашей программы
    SimpleMenu window;
    // изменяем размер виджета в пикселях
    window.resize(500, 500);
    // устанавливаем заголовок для главного окна
    window.setWindowTitle("My OWN window!!!");
    window.setWindowIcon(QIcon("U:/ProjectQt/QPainter/icon.png"));//!!!
    // устанавливаем всплывающую подсказку для виджета
    window.setToolTip("This is window");
    // выводим виджет на экран
    window.show();


    Calculator calculator;
    calculator.resize(50, 50);
    calculator.setWindowTitle("Calculator!!!");

    calculator.setToolTip("This is Calculator");
    calculator.show();


    KeyPress key;
    key.resize(50, 50);
    key.setWindowTitle("KeyPress!!!");
    key.show();

    Move move;
    move.resize(100, 50);
    move.setWindowTitle("Move!!!");
    move.show();


    Disconnect disconnect;
    disconnect.resize(100, 100);
    disconnect.setWindowTitle("Disconnect!!!");
    disconnect.show();

    Timer timer;
    timer.resize(500, 100);
    timer.setWindowTitle("Timer!!!");
    timer.show();

    Label label;
    label.resize(500, 100);
    label.setWindowTitle("Label!!!");
    label.show();


    Slider slider;
    slider.resize(500, 100);
    slider.setWindowTitle("Slider!!!");
    slider.show();

    ComboBox combobox;
    combobox.resize(500, 100);
    combobox.setWindowTitle("ComboBox!!!");
    combobox.show();

    SpinBox spinbox;
    spinbox.resize(500, 100);
    spinbox.setWindowTitle("SpinBox!!!");
    spinbox.show();

    Ledit ledit;
    ledit.resize(500, 100);
    ledit.setWindowTitle("Ledit!!!");
    ledit.show();


    Statusbar statusbar;
    statusbar.resize(500, 100);
    statusbar.setWindowTitle("Statusbar!!!");
    statusbar.show();


    CheckBox checkbox;
    checkbox.resize(500, 100);
    checkbox.setWindowTitle("CheckBox!!!");
    checkbox.show();

    ListWidget listwidget;
    listwidget.resize(500, 100);
    listwidget.setWindowTitle("ListWidget!!!");
    listwidget.show();

    ProgressBarEx progressbarex;
    progressbarex.resize(500, 100);
    progressbarex.setWindowTitle("ProgressBarEx!!!");
    progressbarex.show();


    Pixmap pixmap;
    pixmap.resize(500, 100);
    pixmap.setWindowTitle("Pixmap!!!");
    pixmap.show();

    Splitter splitter;
    splitter.resize(500, 100);
    splitter.setWindowTitle("Splitter!!!");
    splitter.show();

    Table table;
    table.resize(500, 500);
    table.setWindowTitle("Table!!!");
    table.show();

    // С помощью метода exec() запускаем основной цикл нашей программы
    return app.exec();
}

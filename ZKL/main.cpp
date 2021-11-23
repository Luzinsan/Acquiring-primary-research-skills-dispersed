#include "mainwindow.h"

//#include "feedback.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QColor>
#include <QPalette>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ZKL_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }
    MainWindow window;
    window.setPalette(QPalette(QColor(90,90,140,250)));
    window.setWindowIcon(QIcon("Icons/icons8-categorize-64.png"));
    window.resize(1420, 800);
    window.setFixedSize(1415, 790);
    window.setWindowTitle("XPainter");
    window.show();
/*
    Feedback feedback;
    feedback.resize(800, 500);
    feedback.setWindowTitle("Feedback!!!");
    feedback.show();
    */
    return app.exec();


}

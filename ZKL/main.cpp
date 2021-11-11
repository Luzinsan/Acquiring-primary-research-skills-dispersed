#include "mainwindow.h"
//#include "createfile.h"
//#include "feedback.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

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
    window.resize(500, 500);
    window.setWindowTitle("MainWindow!!!");
    window.show();
/*


    CreateFile create;
    create.resize(500, 300);
    create.setWindowTitle("CreateFile!!!");
    create.show();

    Feedback feedback;
    feedback.resize(800, 500);
    feedback.setWindowTitle("Feedback!!!");
    feedback.show();

    */
    return app.exec();


}

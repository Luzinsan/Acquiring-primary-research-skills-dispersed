#include "toolswindow.h"
#include "paintwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "practice_GraphicEditor_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    ToolsWindow toolsWindow;
    PaintWindow paintWindow;
    toolsWindow.SetPaintWindow(&paintWindow);
    toolsWindow.show();
    paintWindow.show();
    return a.exec();
}

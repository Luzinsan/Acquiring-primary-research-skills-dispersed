QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calculator.cpp \
    checkbox.cpp \
    combobox.cpp \
    disconnect.cpp \
    keypress.cpp \
    label.cpp \
    ledit.cpp \
    listwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    move.cpp \
    pixmap.cpp \
    plusminus.cpp \
    progressbarex.cpp \
    simplemenu.cpp \
    slider.cpp \
    spinbox.cpp \
    splitter.cpp \
    statusbar.cpp \
    table.cpp \
    timer.cpp

HEADERS += \
    calculator.h \
    checkbox.h \
    combobox.h \
    disconnect.h \
    keypress.h \
    label.h \
    ledit.h \
    listwidget.h \
    mainwindow.h \
    move.h \
    pixmap.h \
    plusminus.h \
    progressbarex.h \
    simplemenu.h \
    slider.h \
    spinbox.h \
    splitter.h \
    statusbar.h \
    table.h \
    timer.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    QPainter_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    createfile.cpp \
    dotsignal.cpp \
    feedback.cpp \
    main.cpp \
    mainwindow.cpp \
    svgreader.cpp \
    vepolyline.cpp \
    verectangle.cpp \
    verticalbox.cpp \
    veselectionrect.cpp \
    veworkplace.cpp

HEADERS += \
    createfile.h \
    dotsignal.h \
    feedback.h \
    mainwindow.h \
    svgreader.h \
    vepolyline.h \
    verectangle.h \
    verticalbox.h \
    veselectionrect.h \
    veworkplace.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    ZKL_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

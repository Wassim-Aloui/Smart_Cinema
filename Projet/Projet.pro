QT       += core gui sql network charts
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
TARGET = smtp
DEPENDPATH += D:/OpenSSL-Win32/include

SOURCES += \
    conge.cpp \
    connection.cpp \
    employe.cpp \
    main.cpp \
    mainwindow.cpp \
    smtp.cpp \
    statcng.cpp \
    statistiques.cpp

HEADERS += \
    conge.h \
    connection.h \
    employe.h \
    mainwindow.h \
    smtp.h \
    statcng.h \
    statistiques.h

FORMS += \
    mainwindow.ui \
    statcng.ui \
    statistiques.ui
    OTHER_FILES += \
      icons8-film-reel-100.png

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

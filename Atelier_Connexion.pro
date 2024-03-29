#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------
QT       += core gui sql network charts
QT += gui multimedia
QT += network
QT += core gui widgets
QT       += core gui sql
QT       += core gui charts
QT    += core gui sql printsupport charts
QT       += core gui sql printsupport serialport
QT += printsupport network
gui+= printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    abonnee.cpp \
    abonnement.cpp \
    admin.cpp \
    arduino_led.cpp \
    commande.cpp \
    conge.cpp \
    employe.cpp \
    film.cpp \
    login.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    planning.cpp \
    produit.cpp \
    salles.cpp \
    smtp.cpp \
    smtp_employe.cpp \
    smtp_produit.cpp \
    stat2.cpp \
    stat_conge.cpp \
    stat_employe.cpp \
    statfilm.cpp \
    statistique.cpp \
    statistiquee.cpp \
    user_interface.cpp

HEADERS += \
    abonnee.h \
    abonnement.h \
    admin.h \
    arduino_led.h \
    commande.h \
    conge.h \
    employe.h \
    film.h \
    login.h \
        mainwindow.h \
    connection.h \
    planning.h \
    produit.h \
    salles.h \
    smtp.h \
    smtp_employe.h \
    smtp_produit.h \
    stat2.h \
    stat_conge.h \
    stat_employe.h \
    statfilm.h \
    statistique.h \
    statistiquee.h \
    user_interface.h

FORMS += \
        admin.ui \
        login.ui \
        mainwindow.ui \
        stat2.ui \
        stat_conge.ui \
        stat_employe.ui \
        statfilm.ui \
        statistique.ui \
        statistiquee.ui \
        user_interface.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imag.qrc \
    rsc.qrc

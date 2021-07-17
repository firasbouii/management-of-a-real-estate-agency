QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

RC_ICONS = icon2.ico

-std=c++11

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    adresse.cpp \
    agent.cpp \
    appartement.cpp \
    bien_immobilier.cpp \
    client.cpp \
    clientwindow.cpp \
    connexion.cpp \
    contrat.cpp \
    contratachat.cpp \
    contratlocation.cpp \
    date.cpp \
    entrepot.cpp \
    loginadmin.cpp \
    loginadminwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    maison.cpp \
    mpdoublie.cpp \
    nouveaumdp.cpp \
    proposition.cpp \
    reservation.cpp \
    secondclientwindow.cpp \
    terrain.cpp

HEADERS += \
    NewQTABdesign.h \
    Qtabnewstyle.h \
    admin.h \
    adresse.h \
    agent.h \
    appartement.h \
    bien_immobilier.h \
    client.h \
    clientwindow.h \
    connexion.h \
    contrat.h \
    contratachat.h \
    contratlocation.h \
    costumstyle.h \
    date.h \
    entrepot.h \
    loginadmin.h \
    loginadminwindow.h \
    mainwindow.h \
    maison.h \
    mpdoublie.h \
    nouveaumdp.h \
    proposition.h \
    reservation.h \
    secondclientwindow.h \
    terrain.h

FORMS += \
    admin.ui \
    agent.ui \
    clientwindow.ui \
    loginadmin.ui \
    loginadminwindow.ui \
    mainwindow.ui \
    mpdoublie.ui \
    nouveaumdp.ui \
    secondclientwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

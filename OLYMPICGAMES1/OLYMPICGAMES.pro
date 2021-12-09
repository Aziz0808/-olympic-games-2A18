QT       += core gui sql multimedia
QT       += sql qml
QT       += printsupport serialport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    reservation.cpp \
    spectateur.cpp \
    spectateur_page.cpp

HEADERS += \
    arduino.h \
    connection.h \
    mainwindow.h \
    reservation.h \
    spectateur.h \
    spectateur_page.h

FORMS += \
    mainwindow.ui \
    spectateur_page.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc

#-------------------------------------------------
#
# Project created by QtCreator 2019-07-12T01:54:57
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pos
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
        DigitalClock.cpp \
        Entry.cpp \
        FoodMenuWindow.cpp \
        MainWindow.cpp \
        SalesReportWindow.cpp \
        SettingsWindow.cpp \
        Ticket.cpp \
        TicketsTableWindow.cpp \
        main.cpp

HEADERS += \
        DigitalClock.h \
        Entry.h \
        FoodMenuWindow.h \
        MainWindow.h \
        SalesReportWindow.h \
        SettingsWindow.h \
        Ticket.h \
        TicketsTableWindow.h

FORMS += \
        foodmenuwindow.ui \
        mainwindow.ui \
        salesreportwindow.ui \
        settingswindow.ui \
        ticketstablewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Define the application icon
win32:RC_ICONS += icons/icon.ico

# Define the application name
TARGET = Pos

RESOURCES += \
    resources.qrc
	

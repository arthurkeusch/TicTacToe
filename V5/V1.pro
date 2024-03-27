QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settings.cpp \
    stats.cpp \
    widget.cpp \
    agent.cpp \
    board.cpp \
    game.cpp \
    gamelogic.cpp \
    gamestate.cpp \
    humanplayer.cpp

HEADERS += \
    mainwindow.h \
    settings.h \
    stats.h \
    widget.h \
    agent.h \
    player.h \
    board.h \
    game.h \
    gamelogic.h \
    gamestate.h \
    humanplayer.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

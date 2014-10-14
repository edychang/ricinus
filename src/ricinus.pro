#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T15:23:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ricinus
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    define.h \
    program/program.h \
    program/program_manager.h \
    mediaplayer/media_player.h \
    mediaplayer/player_manager.h \
    task/task.h \
    task/task_manager.h

FORMS    += mainwindow.ui

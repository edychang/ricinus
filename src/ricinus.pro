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
        mainwindow.cpp \
    mediaplayer/media_player_impl.cpp \
    program/program_manager_impl.cpp

HEADERS  += mainwindow.h \
    define.h \
    program/program.h \
    program/program_manager.h \
    mediaplayer/media_player.h \
    mediaplayer/player_manager.h \
    task/task.h \
    task/task_manager.h \
    system/sys_manager.h \
    mediaplayer/media_player_impl.h \
    program/program_manager_impl.h

FORMS    += mainwindow.ui

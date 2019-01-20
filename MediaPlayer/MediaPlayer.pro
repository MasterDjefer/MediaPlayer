QT += core
QT += gui
QT += multimedia
QT += multimediawidgets
QT += widgets
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MediaPlayer
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    artist.cpp \
    mediadata.cpp \
    music.cpp \
    musicinfo.cpp \
    title.cpp \
    musicfile.cpp \
    genre.cpp \
    year.cpp \
    widgetinfo.cpp \
    mediafile.cpp \
    widgetvolume.cpp \
    widgetplaybackrate.cpp \
    widgetprogress.cpp \
    time.cpp \
    myvideowidget.cpp \
    widgetcontrols.cpp \
    widgetplaylists.cpp \
    widgetaddplaylist.cpp \
    playlistmap.cpp \
    playlistsdatabase.cpp \
    databasehelper.cpp \
    server.cpp

HEADERS += \
    mainwindow.h \
    artist.h \
    mediadata.h \
    music.h \
    musicinfo.h \
    title.h \
    musicfile.h \
    genre.h \
    year.h \
    widgetinfo.h \
    mediafile.h \
    widgetvolume.h \
    widgetplaybackrate.h \
    widgetprogress.h \
    time.h \
    myvideowidget.h \
    widgetcontrols.h \
    widgetplaylists.h \
    widgetaddplaylist.h \
    playlistmap.h \
    playlistsdatabase.h \
    databasehelper.h \
    server.h

RESOURCES += \
    resources.qrc

win32: LIBS += -lws2_32

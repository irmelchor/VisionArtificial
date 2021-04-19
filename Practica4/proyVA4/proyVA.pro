#-------------------------------------------------
#
# Project created by QtCreator 2021-01-23T13:03:32
#
#-------------------------------------------------

QT += core gui opengl

TARGET = proyVA
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    imgviewer.cpp 

HEADERS  += mainwindow.h \
    imgviewer.h 

INCLUDEPATH += /usr/include/opencv4 /usr/local/include/opencv4
LIBS += -L/usr/lib -L/usr/local/lib -lopencv_imgproc -lopencv_core -lopencv_highgui -lopencv_features2d -lopencv_flann -lopencv_video -lopencv_videoio -lopencv_calib3d -lopencv_imgcodecs

FORMS    += mainwindow.ui \
    SelectionOfCategories.ui

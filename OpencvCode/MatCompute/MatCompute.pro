#-------------------------------------------------
#
# Project created by QtCreator 2014-05-02T16:02:47
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = MatCompute
CONFIG   += console
CONFIG   -= app_bundle
CONFIG +=c++11

TEMPLATE = app


SOURCES += main.cpp

INCLUDEPATH+=E:/opencv/build/include

win32:CONFIG(debug, debug|release): {
LIBS += -LE:/opencv/build/x86/vc11/lib \
-lopencv_core248d \
-lopencv_imgproc248d \
-lopencv_highgui248d \
-lopencv_ml248d \
-lopencv_video248d \
-lopencv_features2d248d \
-lopencv_calib3d248d \
-lopencv_objdetect248d \
-lopencv_contrib248d \
-lopencv_legacy248d \
-lopencv_flann248d
} else:win32:CONFIG(release, debug|release): {
LIBS += -LE:/opencv/build/x86/vc11/lib \
-lopencv_core248 \
-lopencv_imgproc248 \
-lopencv_highgui248 \
-lopencv_ml248 \
-lopencv_video248 \
-lopencv_features2d248 \
-lopencv_calib3d248 \
-lopencv_objdetect248 \
-lopencv_contrib248 \
-lopencv_legacy248 \
-lopencv_flann248
}

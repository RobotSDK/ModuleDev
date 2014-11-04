#-------------------------------------------------
#
# Project created by QtCreator 2014-10-10T13:44:43
#
#-------------------------------------------------

QT += widgets network opengl xml

TEMPLATE = lib

CONFIG += qt

unix{

    INCLUDEPATH += /usr/include/pcl-1.7
    INCLUDEPATH += /usr/include/eigen3
    INCLUDEPATH += $$(HOME)/SDK/GLViewer/include

    LIBS += -L/usr/lib -lpcl_io
    LIBS += -L/usr/lib -lpcl_common
    LIBS += -L/usr/lib -lpcl_filters
    LIBS += -L/usr/lib -lpcl_search
    LIBS += -L/usr/lib -lpcl_kdtree
    LIBS += -L/usr/lib -lpcl_features
    LIBS += -L/usr/lib -lpcl_segmentation
    LIBS += -L/usr/lib/x86_64-linux-gnu -lopencv_core
    LIBS += -L/usr/lib/x86_64-linux-gnu -lopencv_highgui
    LIBS += -L/usr/lib/x86_64-linux-gnu -lopencv_features2d
    LIBS += -L/usr/lib/x86_64-linux-gnu -lopencv_objdetect
    LIBS += -L/usr/lib/x86_64-linux-gnu -lopencv_contrib


    CONFIG(debug, debug|release){
        LIBS += -L$$(HOME)/SDK/GLViewer/lib/Debug -lGLViewer
    }else{
        LIBS += -L$$(HOME)/SDK/GLViewer/lib/Release -lGLViewer
    }
    LIBS *= -L/usr/lib/i386-linux-gnu -lGLU
}

PROJNAME = KITTI
INSTALLTYPE = MOD
include(RobotSDK_Main.pri)

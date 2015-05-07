    INCLUDEPATH += $$(HOME)/SDK/ROSInterface/include
    INCLUDEPATH += $$(HOME)/SDK/GLViewer/include
    INCLUDEPATH += $$(HOME)/SDK/serialport_lib/include
    INCLUDEPATH += $$(HOME)/SDK/serialport_lib/serialport/include

    CONFIG(debug, debug|release){
        LIBS += -L$$(HOME)/SDK/GLViewer/lib -lGLViewer_Debug
        LIBS += -L$$(HOME)/SDK/ROSInterface/lib/ -lROSInterface_Debug
        LIBS += -L$$(HOME)/SDK/serialport_lib/lib/ -lserialport_lib_Debug
    }else{
        LIBS += -L$$(HOME)/SDK/GLViewer/lib -lGLViewer_Release
        LIBS += -L$$(HOME)/SDK/ROSInterface/lib/ -lROSInterface_Release
        LIBS += -L$$(HOME)/SDK/serialport_lib/lib/ -lserialport_lib_Release
    }

    INCLUDEPATH += /opt/ros/indigo/include

    LIBS += -L/opt/ros/indigo/lib -lroscpp
    LIBS += -L/opt/ros/indigo/lib -lrosconsole
    LIBS += -L/opt/ros/indigo/lib -lroscpp_serialization
    LIBS += -L/opt/ros/indigo/lib -lrostime
    LIBS += -L/opt/ros/indigo/lib -lxmlrpcpp
    LIBS += -L/opt/ros/indigo/lib -lcpp_common
    LIBS += -L/opt/ros/indigo/lib -lrosconsole_log4cxx
    LIBS += -L/opt/ros/indigo/lib -lrosconsole_backend_interface
    LIBS += -L/opt/ros/indigo/lib -ltf
    LIBS += -L/opt/ros/indigo/lib -ltf2
    LIBS += -L/opt/ros/indigo/lib -ltf2_ros
    LIBS += -L/opt/ros/indigo/lib -lpcl_ros_tf
    LIBS += -L/opt/ros/indigo/lib -ltf_conversions
    LIBS += -L/opt/ros/indigo/lib -lactionlib
    LIBS += -L/usr/lib/x86_64-linux-gnu -lboost_system


HEADERS += wheelchair.h\
        wheelchair_global.h

SOURCES += wheelchair.cpp

PROJNAME = wheelchair
INSTTYPE = MOD
include(RobotSDK_Main.pri)

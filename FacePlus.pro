QT += qml quick network multimedia

CONFIG += c++11

SOURCES += main.cpp \
  faceplusplus.cpp \
  faceplusplus_filter.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
  faceplusplus.h \
  faceplusplus_filter.h


#INCLUDEPATH += \
#  $$(OPENCV_DIR)/include

#LIBS += \
#  -L$$(OPENCV_DIR)/$${QMAKE_TARGET.arch}/vc14/lib \
#  -lopencv_ml320 \
#  -lopencv_objdetect320 \
#  -lopencv_calib3d320 \
#  -lopencv_video320 \
#  -lopencv_features2d320 \
#  -lopencv_highgui320 \
#  -lopencv_flann320 \
#  -lopencv_imgproc320 \
#  -lopencv_core320 \
#  -lopencv_imgcodecs320 \
#  -lopencv_photo320 \
#  -lopencv_shape320 \
#  -lopencv_stitching320 \
#  -lopencv_superres320 \
#  -lopencv_videoio320 \
#  -lopencv_videostab320 \
#  -lopencv_face320 \

    LOCAL_PATH := $(call my-dir)

    include $(CLEAR_VARS)

    #opencv
    OPENCVROOT:= /home/rlopez/software/opencv-340-android-sdk
    OPENCV_CAMERA_MODULES:=on
    OPENCV_INSTALL_MODULES:=on
    OPENCV_LIB_TYPE:=SHARED
    include ${OPENCVROOT}/sdk/native/jni/OpenCV.mk

    LOCAL_SRC_FILES := com_nova_rlopez_facedetectionopencv_OpencvClass.cpp

    LOCAL_LDLIBS += -llog
    LOCAL_MODULE := MyOpencvLibs

    include $(BUILD_SHARED_LIBRARY)
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := my_app
LOCAL_SRC_FILES := player.cpp
LOCAL_SHARED_LIBRARIES :=  libutils  libui libgui libmedia libbinder

include $(BUILD_EXECUTABLE)


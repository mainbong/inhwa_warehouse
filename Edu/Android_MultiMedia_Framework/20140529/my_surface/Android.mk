LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := my_surface
LOCAL_SRC_FILES := my_surface.cpp 
LOCAL_SHARED_LIBRARIES :=  libutils  libgui libui

include $(BUILD_EXECUTABLE)


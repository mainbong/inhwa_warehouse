LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := my_looper 
LOCAL_SRC_FILES := my_looper.cpp
LOCAL_SHARED_LIBRARIES := libutils  liblog  

include $(BUILD_EXECUTABLE)

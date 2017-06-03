LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := libutils
LOCAL_SRC_FILES := my_thread.cpp
LOCAL_MODULE := my_thread
include $(BUILD_EXECUTABLE)


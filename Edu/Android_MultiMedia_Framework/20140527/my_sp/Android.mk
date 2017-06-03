LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := libutils
LOCAL_SRC_FILES := my_sp.cpp
LOCAL_MODULE := my_sp
include $(BUILD_EXECUTABLE)


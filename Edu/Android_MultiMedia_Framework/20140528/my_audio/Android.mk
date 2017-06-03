LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := my_audio 
LOCAL_SRC_FILES := my_audio.cpp
LOCAL_SHARED_LIBRARIES := libutils  liblog  libbinder libmedia


include $(BUILD_EXECUTABLE)

LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := liblog libbinder libutils
LOCAL_SRC_FILES := my_server.cpp 
LOCAL_MODULE := my_server
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := liblog libbinder libutils
LOCAL_SRC_FILES := my_client.cpp 
LOCAL_MODULE := my_client
include $(BUILD_EXECUTABLE)


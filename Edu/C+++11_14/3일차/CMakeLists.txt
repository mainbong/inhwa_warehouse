find_package( Threads )
ADD_EXECUTABLE (thread 14_thread.cpp)
ADD_EXECUTABLE (thread2 14_thread2.cpp)
target_link_libraries(thread ${CMAKE_THREAD_LIBS_INIT} )
target_link_libraries(thread2 ${CMAKE_THREAD_LIBS_INIT} )
ADD_EXECUTABLE (smart_ptr 15_스마트포인터.cpp)


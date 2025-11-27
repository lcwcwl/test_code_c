cmake_minimum_required(VERSION 3.13)

project(leedcode)

set(OPENCV_CFG_DIR "D:/software/opencv/build")

include_directories("inc")

add_executable(testbed
	src/leedcode.cpp
	
	inc/leedcode.h
)

#config for opencv
option(USE_OPENCV "set flag to use opencv or not" ON)
if(USE_OPENCV)
	set(OpenCV_DIR ${OPENCV_CFG_DIR} CACHE PATH "")
	find_package(OpenCV REQUIRED)
	if(OpenCV_FOUND)
		message(STATUS "--> Opencv found")
	endif()
endif()

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

set(CMAKE_EXE_LINKER_FLAGS /NODEFAULTLIB:"libc") #set the ignore linked lib name
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")

# add compile flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")


list(APPEND TESTBED_LIB_DIR
	#lib
)

# copy dll file
# set(ARCNN_PATH "${CMAKE_SOURCE_DIR}/lib/arcnn.dll")
# execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/Debug)
# execute_process(COMMAND ${CMAKE_COMMAND} -E copy ${ARCNN_PATH} ${CMAKE_BINARY_DIR}/Debug)
# execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/Release)
# execute_process(COMMAND ${CMAKE_COMMAND} -E copy ${ARCNN_PATH} ${CMAKE_BINARY_DIR}/Release)


list(APPEND TESTBED_LIB_NAMES
	#arcnn 
)

target_link_directories(testbed PRIVATE ${TESTBED_LIB_DIR})

target_link_libraries(testbed ${TESTBED_LIB_NAMES} ${OpenCV_LIBS})













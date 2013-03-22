cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#add dynamic reconfigure api
# Uncomment once we have the first task
rosbuild_find_ros_package(dynamic_reconfigure)
include(${dynamic_reconfigure_PACKAGE_PATH}/cmake/cfgbuild.cmake)
gencfg()


#uncomment if you have defined messages
#rosbuild_genmsg()
#uncomment if you have defined services
#rosbuild_gensrv()

#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})

ROSBUILD_ADD_LIBRARY( TaskGoTo SHARED tasks/TaskGoTo.cpp)
TARGET_LINK_LIBRARIES(TaskGoTo dl)

ROSBUILD_ADD_LIBRARY( TaskGoToAngle SHARED tasks/TaskGoToAngle.cpp)
TARGET_LINK_LIBRARIES(TaskGoToAngle dl)

ROSBUILD_ADD_LIBRARY( TaskFollowShore SHARED tasks/TaskFollowShore.cpp)
TARGET_LINK_LIBRARIES(TaskFollowShore dl)

ROSBUILD_ADD_LIBRARY( TaskFindFinishLine SHARED tasks/TaskFindFinishLine.cpp)
TARGET_LINK_LIBRARIES(TaskFindFinishLine dl)

ROSBUILD_ADD_LIBRARY( TaskJoinOtherShore SHARED tasks/TaskJoinOtherShore.cpp)
TARGET_LINK_LIBRARIES(TaskJoinOtherShore dl)

ROSBUILD_ADD_LIBRARY( TaskWaitForAuto SHARED tasks/TaskWaitForAuto.cpp)
TARGET_LINK_LIBRARIES(TaskWaitForAuto dl)

ROSBUILD_ADD_LIBRARY( TaskSetManual SHARED tasks/TaskSetManual.cpp)
TARGET_LINK_LIBRARIES(TaskSetManual dl)

ROSBUILD_ADD_EXECUTABLE( task_server src/task_server.cpp src/SimTasksEnv.cpp) 
TARGET_LINK_LIBRARIES(task_server dl boost_system)

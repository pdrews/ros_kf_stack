# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adam/ros_workspace/ros_kf_stack/kf_yaw_kf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adam/ros_workspace/ros_kf_stack/kf_yaw_kf/build

# Utility rule file for ROSBUILD_gensrv_py.

# Include the progress variables for this target.
include CMakeFiles/ROSBUILD_gensrv_py.dir/progress.make

CMakeFiles/ROSBUILD_gensrv_py: ../src/kf_yaw_kf/srv/__init__.py

../src/kf_yaw_kf/srv/__init__.py: ../src/kf_yaw_kf/srv/_SetMagOffset.py
	$(CMAKE_COMMAND) -E cmake_progress_report /home/adam/ros_workspace/ros_kf_stack/kf_yaw_kf/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ../src/kf_yaw_kf/srv/__init__.py"
	/opt/ros/fuerte/share/rospy/rosbuild/scripts/gensrv_py.py --initpy /home/adam/ros_workspace/ros_kf_stack/kf_yaw_kf/srv/SetMagOffset.srv

../src/kf_yaw_kf/srv/_SetMagOffset.py: ../srv/SetMagOffset.srv
../src/kf_yaw_kf/srv/_SetMagOffset.py: /opt/ros/fuerte/share/rospy/rosbuild/scripts/gensrv_py.py
../src/kf_yaw_kf/srv/_SetMagOffset.py: /opt/ros/fuerte/share/roslib/bin/gendeps
../src/kf_yaw_kf/srv/_SetMagOffset.py: ../manifest.xml
../src/kf_yaw_kf/srv/_SetMagOffset.py: /opt/ros/fuerte/share/roslang/manifest.xml
../src/kf_yaw_kf/srv/_SetMagOffset.py: /opt/ros/fuerte/share/rospy/manifest.xml
../src/kf_yaw_kf/srv/_SetMagOffset.py: /opt/ros/fuerte/share/roscpp/manifest.xml
../src/kf_yaw_kf/srv/_SetMagOffset.py: /opt/ros/fuerte/share/message_filters/manifest.xml
../src/kf_yaw_kf/srv/_SetMagOffset.py: /opt/ros/fuerte/share/geometry_msgs/manifest.xml
../src/kf_yaw_kf/srv/_SetMagOffset.py: /opt/ros/fuerte/share/nav_msgs/manifest.xml
../src/kf_yaw_kf/srv/_SetMagOffset.py: /opt/ros/fuerte/share/sensor_msgs/manifest.xml
../src/kf_yaw_kf/srv/_SetMagOffset.py: /opt/ros/fuerte/stacks/gps_umd/gps_common/manifest.xml
../src/kf_yaw_kf/srv/_SetMagOffset.py: /opt/ros/fuerte/stacks/gps_umd/gps_common/msg_gen/generated
	$(CMAKE_COMMAND) -E cmake_progress_report /home/adam/ros_workspace/ros_kf_stack/kf_yaw_kf/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating ../src/kf_yaw_kf/srv/_SetMagOffset.py"
	/opt/ros/fuerte/share/rospy/rosbuild/scripts/gensrv_py.py --noinitpy /home/adam/ros_workspace/ros_kf_stack/kf_yaw_kf/srv/SetMagOffset.srv

ROSBUILD_gensrv_py: CMakeFiles/ROSBUILD_gensrv_py
ROSBUILD_gensrv_py: ../src/kf_yaw_kf/srv/__init__.py
ROSBUILD_gensrv_py: ../src/kf_yaw_kf/srv/_SetMagOffset.py
ROSBUILD_gensrv_py: CMakeFiles/ROSBUILD_gensrv_py.dir/build.make
.PHONY : ROSBUILD_gensrv_py

# Rule to build all files generated by this target.
CMakeFiles/ROSBUILD_gensrv_py.dir/build: ROSBUILD_gensrv_py
.PHONY : CMakeFiles/ROSBUILD_gensrv_py.dir/build

CMakeFiles/ROSBUILD_gensrv_py.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ROSBUILD_gensrv_py.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ROSBUILD_gensrv_py.dir/clean

CMakeFiles/ROSBUILD_gensrv_py.dir/depend:
	cd /home/adam/ros_workspace/ros_kf_stack/kf_yaw_kf/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adam/ros_workspace/ros_kf_stack/kf_yaw_kf /home/adam/ros_workspace/ros_kf_stack/kf_yaw_kf /home/adam/ros_workspace/ros_kf_stack/kf_yaw_kf/build /home/adam/ros_workspace/ros_kf_stack/kf_yaw_kf/build /home/adam/ros_workspace/ros_kf_stack/kf_yaw_kf/build/CMakeFiles/ROSBUILD_gensrv_py.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ROSBUILD_gensrv_py.dir/depend


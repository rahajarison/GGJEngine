# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 2.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\CMake 2.8\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake 2.8\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "C:\Program Files (x86)\CMake 2.8\bin\cmake-gui.exe"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Seven\Documents\GitHub\GGJEngine\Box2D_v2.2.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Seven\Documents\GitHub\GGJEngine\Box2D_v2.2.1

# Include any dependencies generated for this target.
include HelloWorld/CMakeFiles/HelloWorld.dir/depend.make

# Include the progress variables for this target.
include HelloWorld/CMakeFiles/HelloWorld.dir/progress.make

# Include the compile flags for this target's objects.
include HelloWorld/CMakeFiles/HelloWorld.dir/flags.make

HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj: HelloWorld/CMakeFiles/HelloWorld.dir/flags.make
HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj: HelloWorld/CMakeFiles/HelloWorld.dir/includes_CXX.rsp
HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj: HelloWorld/HelloWorld.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report C:\Users\Seven\Documents\GitHub\GGJEngine\Box2D_v2.2.1\CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj"
	cd /d C:\Users\Seven\Documents\GitHub\GGJEngine\Box2D_v2.2.1\HelloWorld && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\HelloWorld.dir\HelloWorld.cpp.obj -c C:\Users\Seven\Documents\GitHub\GGJEngine\Box2D_v2.2.1\HelloWorld\HelloWorld.cpp

HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HelloWorld.dir/HelloWorld.cpp.i"
	cd /d C:\Users\Seven\Documents\GitHub\GGJEngine\Box2D_v2.2.1\HelloWorld && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:\Users\Seven\Documents\GitHub\GGJEngine\Box2D_v2.2.1\HelloWorld\HelloWorld.cpp > CMakeFiles\HelloWorld.dir\HelloWorld.cpp.i

HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HelloWorld.dir/HelloWorld.cpp.s"
	cd /d C:\Users\Seven\Documents\GitHub\GGJEngine\Box2D_v2.2.1\HelloWorld && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:\Users\Seven\Documents\GitHub\GGJEngine\Box2D_v2.2.1\HelloWorld\HelloWorld.cpp -o CMakeFiles\HelloWorld.dir\HelloWorld.cpp.s

HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj.requires:
.PHONY : HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj.requires

HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj.provides: HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj.requires
	$(MAKE) -f HelloWorld\CMakeFiles\HelloWorld.dir\build.make HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj.provides.build
.PHONY : HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj.provides

HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj.provides.build: HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj

# Object files for target HelloWorld
HelloWorld_OBJECTS = \
"CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj"

# External object files for target HelloWorld
HelloWorld_EXTERNAL_OBJECTS =

HelloWorld/HelloWorld.exe: HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj
HelloWorld/HelloWorld.exe: HelloWorld/CMakeFiles/HelloWorld.dir/build.make
HelloWorld/HelloWorld.exe: Box2D/libBox2D.a
HelloWorld/HelloWorld.exe: HelloWorld/CMakeFiles/HelloWorld.dir/objects1.rsp
HelloWorld/HelloWorld.exe: HelloWorld/CMakeFiles/HelloWorld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable HelloWorld.exe"
	cd /d C:\Users\Seven\Documents\GitHub\GGJEngine\Box2D_v2.2.1\HelloWorld && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HelloWorld.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
HelloWorld/CMakeFiles/HelloWorld.dir/build: HelloWorld/HelloWorld.exe
.PHONY : HelloWorld/CMakeFiles/HelloWorld.dir/build

HelloWorld/CMakeFiles/HelloWorld.dir/requires: HelloWorld/CMakeFiles/HelloWorld.dir/HelloWorld.cpp.obj.requires
.PHONY : HelloWorld/CMakeFiles/HelloWorld.dir/requires

HelloWorld/CMakeFiles/HelloWorld.dir/clean:
	cd /d C:\Users\Seven\Documents\GitHub\GGJEngine\Box2D_v2.2.1\HelloWorld && $(CMAKE_COMMAND) -P CMakeFiles\HelloWorld.dir\cmake_clean.cmake
.PHONY : HelloWorld/CMakeFiles/HelloWorld.dir/clean

HelloWorld/CMakeFiles/HelloWorld.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Seven\Documents\GitHub\GGJEngine\Box2D_v2.2.1 C:\Users\Seven\Documents\GitHub\GGJEngine\Box2D_v2.2.1\HelloWorld C:\Users\Seven\Documents\GitHub\GGJEngine\Box2D_v2.2.1 C:\Users\Seven\Documents\GitHub\GGJEngine\Box2D_v2.2.1\HelloWorld C:\Users\Seven\Documents\GitHub\GGJEngine\Box2D_v2.2.1\HelloWorld\CMakeFiles\HelloWorld.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : HelloWorld/CMakeFiles/HelloWorld.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shivanigoel/CLionProjects/prog5_week2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shivanigoel/CLionProjects/prog5_week2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/prog5_week2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prog5_week2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prog5_week2.dir/flags.make

CMakeFiles/prog5_week2.dir/main.cpp.o: CMakeFiles/prog5_week2.dir/flags.make
CMakeFiles/prog5_week2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shivanigoel/CLionProjects/prog5_week2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/prog5_week2.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prog5_week2.dir/main.cpp.o -c /Users/shivanigoel/CLionProjects/prog5_week2/main.cpp

CMakeFiles/prog5_week2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prog5_week2.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shivanigoel/CLionProjects/prog5_week2/main.cpp > CMakeFiles/prog5_week2.dir/main.cpp.i

CMakeFiles/prog5_week2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prog5_week2.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shivanigoel/CLionProjects/prog5_week2/main.cpp -o CMakeFiles/prog5_week2.dir/main.cpp.s

CMakeFiles/prog5_week2.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/prog5_week2.dir/main.cpp.o.requires

CMakeFiles/prog5_week2.dir/main.cpp.o.provides: CMakeFiles/prog5_week2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/prog5_week2.dir/build.make CMakeFiles/prog5_week2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/prog5_week2.dir/main.cpp.o.provides

CMakeFiles/prog5_week2.dir/main.cpp.o.provides.build: CMakeFiles/prog5_week2.dir/main.cpp.o


CMakeFiles/prog5_week2.dir/test.cpp.o: CMakeFiles/prog5_week2.dir/flags.make
CMakeFiles/prog5_week2.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shivanigoel/CLionProjects/prog5_week2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/prog5_week2.dir/test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prog5_week2.dir/test.cpp.o -c /Users/shivanigoel/CLionProjects/prog5_week2/test.cpp

CMakeFiles/prog5_week2.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prog5_week2.dir/test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shivanigoel/CLionProjects/prog5_week2/test.cpp > CMakeFiles/prog5_week2.dir/test.cpp.i

CMakeFiles/prog5_week2.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prog5_week2.dir/test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shivanigoel/CLionProjects/prog5_week2/test.cpp -o CMakeFiles/prog5_week2.dir/test.cpp.s

CMakeFiles/prog5_week2.dir/test.cpp.o.requires:

.PHONY : CMakeFiles/prog5_week2.dir/test.cpp.o.requires

CMakeFiles/prog5_week2.dir/test.cpp.o.provides: CMakeFiles/prog5_week2.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/prog5_week2.dir/build.make CMakeFiles/prog5_week2.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/prog5_week2.dir/test.cpp.o.provides

CMakeFiles/prog5_week2.dir/test.cpp.o.provides.build: CMakeFiles/prog5_week2.dir/test.cpp.o


# Object files for target prog5_week2
prog5_week2_OBJECTS = \
"CMakeFiles/prog5_week2.dir/main.cpp.o" \
"CMakeFiles/prog5_week2.dir/test.cpp.o"

# External object files for target prog5_week2
prog5_week2_EXTERNAL_OBJECTS =

prog5_week2: CMakeFiles/prog5_week2.dir/main.cpp.o
prog5_week2: CMakeFiles/prog5_week2.dir/test.cpp.o
prog5_week2: CMakeFiles/prog5_week2.dir/build.make
prog5_week2: CMakeFiles/prog5_week2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shivanigoel/CLionProjects/prog5_week2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable prog5_week2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prog5_week2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prog5_week2.dir/build: prog5_week2

.PHONY : CMakeFiles/prog5_week2.dir/build

CMakeFiles/prog5_week2.dir/requires: CMakeFiles/prog5_week2.dir/main.cpp.o.requires
CMakeFiles/prog5_week2.dir/requires: CMakeFiles/prog5_week2.dir/test.cpp.o.requires

.PHONY : CMakeFiles/prog5_week2.dir/requires

CMakeFiles/prog5_week2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prog5_week2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prog5_week2.dir/clean

CMakeFiles/prog5_week2.dir/depend:
	cd /Users/shivanigoel/CLionProjects/prog5_week2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shivanigoel/CLionProjects/prog5_week2 /Users/shivanigoel/CLionProjects/prog5_week2 /Users/shivanigoel/CLionProjects/prog5_week2/cmake-build-debug /Users/shivanigoel/CLionProjects/prog5_week2/cmake-build-debug /Users/shivanigoel/CLionProjects/prog5_week2/cmake-build-debug/CMakeFiles/prog5_week2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prog5_week2.dir/depend

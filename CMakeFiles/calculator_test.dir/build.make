# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/luxuser/Documents/QtProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luxuser/Documents/QtProject

# Include any dependencies generated for this target.
include CMakeFiles/calculator_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/calculator_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/calculator_test.dir/flags.make

CMakeFiles/calculator_test.dir/calculator_test.cc.o: CMakeFiles/calculator_test.dir/flags.make
CMakeFiles/calculator_test.dir/calculator_test.cc.o: calculator_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luxuser/Documents/QtProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/calculator_test.dir/calculator_test.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/calculator_test.dir/calculator_test.cc.o -c /home/luxuser/Documents/QtProject/calculator_test.cc

CMakeFiles/calculator_test.dir/calculator_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calculator_test.dir/calculator_test.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luxuser/Documents/QtProject/calculator_test.cc > CMakeFiles/calculator_test.dir/calculator_test.cc.i

CMakeFiles/calculator_test.dir/calculator_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calculator_test.dir/calculator_test.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luxuser/Documents/QtProject/calculator_test.cc -o CMakeFiles/calculator_test.dir/calculator_test.cc.s

CMakeFiles/calculator_test.dir/calculator_test.cc.o.requires:

.PHONY : CMakeFiles/calculator_test.dir/calculator_test.cc.o.requires

CMakeFiles/calculator_test.dir/calculator_test.cc.o.provides: CMakeFiles/calculator_test.dir/calculator_test.cc.o.requires
	$(MAKE) -f CMakeFiles/calculator_test.dir/build.make CMakeFiles/calculator_test.dir/calculator_test.cc.o.provides.build
.PHONY : CMakeFiles/calculator_test.dir/calculator_test.cc.o.provides

CMakeFiles/calculator_test.dir/calculator_test.cc.o.provides.build: CMakeFiles/calculator_test.dir/calculator_test.cc.o


CMakeFiles/calculator_test.dir/calculator.cc.o: CMakeFiles/calculator_test.dir/flags.make
CMakeFiles/calculator_test.dir/calculator.cc.o: calculator.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luxuser/Documents/QtProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/calculator_test.dir/calculator.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/calculator_test.dir/calculator.cc.o -c /home/luxuser/Documents/QtProject/calculator.cc

CMakeFiles/calculator_test.dir/calculator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/calculator_test.dir/calculator.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luxuser/Documents/QtProject/calculator.cc > CMakeFiles/calculator_test.dir/calculator.cc.i

CMakeFiles/calculator_test.dir/calculator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/calculator_test.dir/calculator.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luxuser/Documents/QtProject/calculator.cc -o CMakeFiles/calculator_test.dir/calculator.cc.s

CMakeFiles/calculator_test.dir/calculator.cc.o.requires:

.PHONY : CMakeFiles/calculator_test.dir/calculator.cc.o.requires

CMakeFiles/calculator_test.dir/calculator.cc.o.provides: CMakeFiles/calculator_test.dir/calculator.cc.o.requires
	$(MAKE) -f CMakeFiles/calculator_test.dir/build.make CMakeFiles/calculator_test.dir/calculator.cc.o.provides.build
.PHONY : CMakeFiles/calculator_test.dir/calculator.cc.o.provides

CMakeFiles/calculator_test.dir/calculator.cc.o.provides.build: CMakeFiles/calculator_test.dir/calculator.cc.o


# Object files for target calculator_test
calculator_test_OBJECTS = \
"CMakeFiles/calculator_test.dir/calculator_test.cc.o" \
"CMakeFiles/calculator_test.dir/calculator.cc.o"

# External object files for target calculator_test
calculator_test_EXTERNAL_OBJECTS =

calculator_test: CMakeFiles/calculator_test.dir/calculator_test.cc.o
calculator_test: CMakeFiles/calculator_test.dir/calculator.cc.o
calculator_test: CMakeFiles/calculator_test.dir/build.make
calculator_test: lib/libgtest.a
calculator_test: lib/libgmock_main.a
calculator_test: lib/libgmock.a
calculator_test: lib/libgtest.a
calculator_test: CMakeFiles/calculator_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luxuser/Documents/QtProject/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable calculator_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/calculator_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/calculator_test.dir/build: calculator_test

.PHONY : CMakeFiles/calculator_test.dir/build

CMakeFiles/calculator_test.dir/requires: CMakeFiles/calculator_test.dir/calculator_test.cc.o.requires
CMakeFiles/calculator_test.dir/requires: CMakeFiles/calculator_test.dir/calculator.cc.o.requires

.PHONY : CMakeFiles/calculator_test.dir/requires

CMakeFiles/calculator_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/calculator_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/calculator_test.dir/clean

CMakeFiles/calculator_test.dir/depend:
	cd /home/luxuser/Documents/QtProject && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luxuser/Documents/QtProject /home/luxuser/Documents/QtProject /home/luxuser/Documents/QtProject /home/luxuser/Documents/QtProject /home/luxuser/Documents/QtProject/CMakeFiles/calculator_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/calculator_test.dir/depend

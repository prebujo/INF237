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
CMAKE_COMMAND = /home/morten/code/clion-2017.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/morten/code/clion-2017.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/morten/code/git/INF237/Morten/learningC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/morten/code/git/INF237/Morten/learningC/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/learningC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/learningC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/learningC.dir/flags.make

CMakeFiles/learningC.dir/main.c.o: CMakeFiles/learningC.dir/flags.make
CMakeFiles/learningC.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/morten/code/git/INF237/Morten/learningC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/learningC.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/learningC.dir/main.c.o   -c /home/morten/code/git/INF237/Morten/learningC/main.c

CMakeFiles/learningC.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/learningC.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/morten/code/git/INF237/Morten/learningC/main.c > CMakeFiles/learningC.dir/main.c.i

CMakeFiles/learningC.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/learningC.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/morten/code/git/INF237/Morten/learningC/main.c -o CMakeFiles/learningC.dir/main.c.s

CMakeFiles/learningC.dir/main.c.o.requires:

.PHONY : CMakeFiles/learningC.dir/main.c.o.requires

CMakeFiles/learningC.dir/main.c.o.provides: CMakeFiles/learningC.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/learningC.dir/build.make CMakeFiles/learningC.dir/main.c.o.provides.build
.PHONY : CMakeFiles/learningC.dir/main.c.o.provides

CMakeFiles/learningC.dir/main.c.o.provides.build: CMakeFiles/learningC.dir/main.c.o


# Object files for target learningC
learningC_OBJECTS = \
"CMakeFiles/learningC.dir/main.c.o"

# External object files for target learningC
learningC_EXTERNAL_OBJECTS =

learningC: CMakeFiles/learningC.dir/main.c.o
learningC: CMakeFiles/learningC.dir/build.make
learningC: CMakeFiles/learningC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/morten/code/git/INF237/Morten/learningC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable learningC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/learningC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/learningC.dir/build: learningC

.PHONY : CMakeFiles/learningC.dir/build

CMakeFiles/learningC.dir/requires: CMakeFiles/learningC.dir/main.c.o.requires

.PHONY : CMakeFiles/learningC.dir/requires

CMakeFiles/learningC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/learningC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/learningC.dir/clean

CMakeFiles/learningC.dir/depend:
	cd /home/morten/code/git/INF237/Morten/learningC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/morten/code/git/INF237/Morten/learningC /home/morten/code/git/INF237/Morten/learningC /home/morten/code/git/INF237/Morten/learningC/cmake-build-debug /home/morten/code/git/INF237/Morten/learningC/cmake-build-debug /home/morten/code/git/INF237/Morten/learningC/cmake-build-debug/CMakeFiles/learningC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/learningC.dir/depend


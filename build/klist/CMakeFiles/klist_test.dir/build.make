# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.21.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.21.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kuzmich/src/ktree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kuzmich/src/ktree/build

# Include any dependencies generated for this target.
include klist/CMakeFiles/klist_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include klist/CMakeFiles/klist_test.dir/compiler_depend.make

# Include the progress variables for this target.
include klist/CMakeFiles/klist_test.dir/progress.make

# Include the compile flags for this target's objects.
include klist/CMakeFiles/klist_test.dir/flags.make

klist/CMakeFiles/klist_test.dir/test.c.o: klist/CMakeFiles/klist_test.dir/flags.make
klist/CMakeFiles/klist_test.dir/test.c.o: ../klist/test.c
klist/CMakeFiles/klist_test.dir/test.c.o: klist/CMakeFiles/klist_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kuzmich/src/ktree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object klist/CMakeFiles/klist_test.dir/test.c.o"
	cd /Users/kuzmich/src/ktree/build/klist && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT klist/CMakeFiles/klist_test.dir/test.c.o -MF CMakeFiles/klist_test.dir/test.c.o.d -o CMakeFiles/klist_test.dir/test.c.o -c /Users/kuzmich/src/ktree/klist/test.c

klist/CMakeFiles/klist_test.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/klist_test.dir/test.c.i"
	cd /Users/kuzmich/src/ktree/build/klist && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kuzmich/src/ktree/klist/test.c > CMakeFiles/klist_test.dir/test.c.i

klist/CMakeFiles/klist_test.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/klist_test.dir/test.c.s"
	cd /Users/kuzmich/src/ktree/build/klist && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kuzmich/src/ktree/klist/test.c -o CMakeFiles/klist_test.dir/test.c.s

# Object files for target klist_test
klist_test_OBJECTS = \
"CMakeFiles/klist_test.dir/test.c.o"

# External object files for target klist_test
klist_test_EXTERNAL_OBJECTS =

klist/klist_test: klist/CMakeFiles/klist_test.dir/test.c.o
klist/klist_test: klist/CMakeFiles/klist_test.dir/build.make
klist/klist_test: klist/libklist.a
klist/klist_test: klist/CMakeFiles/klist_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kuzmich/src/ktree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable klist_test"
	cd /Users/kuzmich/src/ktree/build/klist && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/klist_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
klist/CMakeFiles/klist_test.dir/build: klist/klist_test
.PHONY : klist/CMakeFiles/klist_test.dir/build

klist/CMakeFiles/klist_test.dir/clean:
	cd /Users/kuzmich/src/ktree/build/klist && $(CMAKE_COMMAND) -P CMakeFiles/klist_test.dir/cmake_clean.cmake
.PHONY : klist/CMakeFiles/klist_test.dir/clean

klist/CMakeFiles/klist_test.dir/depend:
	cd /Users/kuzmich/src/ktree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kuzmich/src/ktree /Users/kuzmich/src/ktree/klist /Users/kuzmich/src/ktree/build /Users/kuzmich/src/ktree/build/klist /Users/kuzmich/src/ktree/build/klist/CMakeFiles/klist_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : klist/CMakeFiles/klist_test.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kevin/Projects/C/UDP_CALC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kevin/Projects/C/UDP_CALC

# Include any dependencies generated for this target.
include CMakeFiles/ClientUDP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ClientUDP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ClientUDP.dir/flags.make

CMakeFiles/ClientUDP.dir/ClientUDP.c.o: CMakeFiles/ClientUDP.dir/flags.make
CMakeFiles/ClientUDP.dir/ClientUDP.c.o: ClientUDP.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kevin/Projects/C/UDP_CALC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ClientUDP.dir/ClientUDP.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ClientUDP.dir/ClientUDP.c.o -c /home/kevin/Projects/C/UDP_CALC/ClientUDP.c

CMakeFiles/ClientUDP.dir/ClientUDP.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ClientUDP.dir/ClientUDP.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/kevin/Projects/C/UDP_CALC/ClientUDP.c > CMakeFiles/ClientUDP.dir/ClientUDP.c.i

CMakeFiles/ClientUDP.dir/ClientUDP.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ClientUDP.dir/ClientUDP.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/kevin/Projects/C/UDP_CALC/ClientUDP.c -o CMakeFiles/ClientUDP.dir/ClientUDP.c.s

# Object files for target ClientUDP
ClientUDP_OBJECTS = \
"CMakeFiles/ClientUDP.dir/ClientUDP.c.o"

# External object files for target ClientUDP
ClientUDP_EXTERNAL_OBJECTS =

ClientUDP: CMakeFiles/ClientUDP.dir/ClientUDP.c.o
ClientUDP: CMakeFiles/ClientUDP.dir/build.make
ClientUDP: EncodeDecode/libEncodeDecode.a
ClientUDP: CMakeFiles/ClientUDP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kevin/Projects/C/UDP_CALC/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ClientUDP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ClientUDP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ClientUDP.dir/build: ClientUDP

.PHONY : CMakeFiles/ClientUDP.dir/build

CMakeFiles/ClientUDP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ClientUDP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ClientUDP.dir/clean

CMakeFiles/ClientUDP.dir/depend:
	cd /home/kevin/Projects/C/UDP_CALC && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kevin/Projects/C/UDP_CALC /home/kevin/Projects/C/UDP_CALC /home/kevin/Projects/C/UDP_CALC /home/kevin/Projects/C/UDP_CALC /home/kevin/Projects/C/UDP_CALC/CMakeFiles/ClientUDP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ClientUDP.dir/depend


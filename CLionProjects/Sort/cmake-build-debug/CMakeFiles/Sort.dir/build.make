# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "G:\Clion\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "G:\Clion\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\HUAWEI\CLionProjects\Sort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\HUAWEI\CLionProjects\Sort\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Sort.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sort.dir/flags.make

CMakeFiles/Sort.dir/main.c.obj: CMakeFiles/Sort.dir/flags.make
CMakeFiles/Sort.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\HUAWEI\CLionProjects\Sort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Sort.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Sort.dir\main.c.obj -c C:\Users\HUAWEI\CLionProjects\Sort\main.c

CMakeFiles/Sort.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Sort.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\HUAWEI\CLionProjects\Sort\main.c > CMakeFiles\Sort.dir\main.c.i

CMakeFiles/Sort.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Sort.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\HUAWEI\CLionProjects\Sort\main.c -o CMakeFiles\Sort.dir\main.c.s

CMakeFiles/Sort.dir/sort.c.obj: CMakeFiles/Sort.dir/flags.make
CMakeFiles/Sort.dir/sort.c.obj: ../sort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\HUAWEI\CLionProjects\Sort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Sort.dir/sort.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Sort.dir\sort.c.obj -c C:\Users\HUAWEI\CLionProjects\Sort\sort.c

CMakeFiles/Sort.dir/sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Sort.dir/sort.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\HUAWEI\CLionProjects\Sort\sort.c > CMakeFiles\Sort.dir\sort.c.i

CMakeFiles/Sort.dir/sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Sort.dir/sort.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\HUAWEI\CLionProjects\Sort\sort.c -o CMakeFiles\Sort.dir\sort.c.s

# Object files for target Sort
Sort_OBJECTS = \
"CMakeFiles/Sort.dir/main.c.obj" \
"CMakeFiles/Sort.dir/sort.c.obj"

# External object files for target Sort
Sort_EXTERNAL_OBJECTS =

Sort.exe: CMakeFiles/Sort.dir/main.c.obj
Sort.exe: CMakeFiles/Sort.dir/sort.c.obj
Sort.exe: CMakeFiles/Sort.dir/build.make
Sort.exe: CMakeFiles/Sort.dir/linklibs.rsp
Sort.exe: CMakeFiles/Sort.dir/objects1.rsp
Sort.exe: CMakeFiles/Sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\HUAWEI\CLionProjects\Sort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Sort.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Sort.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sort.dir/build: Sort.exe
.PHONY : CMakeFiles/Sort.dir/build

CMakeFiles/Sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Sort.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Sort.dir/clean

CMakeFiles/Sort.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\HUAWEI\CLionProjects\Sort C:\Users\HUAWEI\CLionProjects\Sort C:\Users\HUAWEI\CLionProjects\Sort\cmake-build-debug C:\Users\HUAWEI\CLionProjects\Sort\cmake-build-debug C:\Users\HUAWEI\CLionProjects\Sort\cmake-build-debug\CMakeFiles\Sort.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Sort.dir/depend


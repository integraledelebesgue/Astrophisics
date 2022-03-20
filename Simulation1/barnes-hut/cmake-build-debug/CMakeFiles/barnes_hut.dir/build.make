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
CMAKE_COMMAND = /home/jsmolka/Pobrane/CLion-2021.3.3/clion-2021.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/jsmolka/Pobrane/CLion-2021.3.3/clion-2021.3.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/barnes_hut.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/barnes_hut.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/barnes_hut.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/barnes_hut.dir/flags.make

CMakeFiles/barnes_hut.dir/system.c.o: CMakeFiles/barnes_hut.dir/flags.make
CMakeFiles/barnes_hut.dir/system.c.o: ../system.c
CMakeFiles/barnes_hut.dir/system.c.o: CMakeFiles/barnes_hut.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/barnes_hut.dir/system.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/barnes_hut.dir/system.c.o -MF CMakeFiles/barnes_hut.dir/system.c.o.d -o CMakeFiles/barnes_hut.dir/system.c.o -c /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/system.c

CMakeFiles/barnes_hut.dir/system.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/barnes_hut.dir/system.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/system.c > CMakeFiles/barnes_hut.dir/system.c.i

CMakeFiles/barnes_hut.dir/system.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/barnes_hut.dir/system.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/system.c -o CMakeFiles/barnes_hut.dir/system.c.s

CMakeFiles/barnes_hut.dir/stack.c.o: CMakeFiles/barnes_hut.dir/flags.make
CMakeFiles/barnes_hut.dir/stack.c.o: ../stack.c
CMakeFiles/barnes_hut.dir/stack.c.o: CMakeFiles/barnes_hut.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/barnes_hut.dir/stack.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/barnes_hut.dir/stack.c.o -MF CMakeFiles/barnes_hut.dir/stack.c.o.d -o CMakeFiles/barnes_hut.dir/stack.c.o -c /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/stack.c

CMakeFiles/barnes_hut.dir/stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/barnes_hut.dir/stack.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/stack.c > CMakeFiles/barnes_hut.dir/stack.c.i

CMakeFiles/barnes_hut.dir/stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/barnes_hut.dir/stack.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/stack.c -o CMakeFiles/barnes_hut.dir/stack.c.s

CMakeFiles/barnes_hut.dir/q-tree.c.o: CMakeFiles/barnes_hut.dir/flags.make
CMakeFiles/barnes_hut.dir/q-tree.c.o: ../q-tree.c
CMakeFiles/barnes_hut.dir/q-tree.c.o: CMakeFiles/barnes_hut.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/barnes_hut.dir/q-tree.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/barnes_hut.dir/q-tree.c.o -MF CMakeFiles/barnes_hut.dir/q-tree.c.o.d -o CMakeFiles/barnes_hut.dir/q-tree.c.o -c /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/q-tree.c

CMakeFiles/barnes_hut.dir/q-tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/barnes_hut.dir/q-tree.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/q-tree.c > CMakeFiles/barnes_hut.dir/q-tree.c.i

CMakeFiles/barnes_hut.dir/q-tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/barnes_hut.dir/q-tree.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/q-tree.c -o CMakeFiles/barnes_hut.dir/q-tree.c.s

CMakeFiles/barnes_hut.dir/physics.c.o: CMakeFiles/barnes_hut.dir/flags.make
CMakeFiles/barnes_hut.dir/physics.c.o: ../physics.c
CMakeFiles/barnes_hut.dir/physics.c.o: CMakeFiles/barnes_hut.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/barnes_hut.dir/physics.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/barnes_hut.dir/physics.c.o -MF CMakeFiles/barnes_hut.dir/physics.c.o.d -o CMakeFiles/barnes_hut.dir/physics.c.o -c /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/physics.c

CMakeFiles/barnes_hut.dir/physics.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/barnes_hut.dir/physics.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/physics.c > CMakeFiles/barnes_hut.dir/physics.c.i

CMakeFiles/barnes_hut.dir/physics.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/barnes_hut.dir/physics.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/physics.c -o CMakeFiles/barnes_hut.dir/physics.c.s

CMakeFiles/barnes_hut.dir/main.c.o: CMakeFiles/barnes_hut.dir/flags.make
CMakeFiles/barnes_hut.dir/main.c.o: ../main.c
CMakeFiles/barnes_hut.dir/main.c.o: CMakeFiles/barnes_hut.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/barnes_hut.dir/main.c.o"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/barnes_hut.dir/main.c.o -MF CMakeFiles/barnes_hut.dir/main.c.o.d -o CMakeFiles/barnes_hut.dir/main.c.o -c /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/main.c

CMakeFiles/barnes_hut.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/barnes_hut.dir/main.c.i"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/main.c > CMakeFiles/barnes_hut.dir/main.c.i

CMakeFiles/barnes_hut.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/barnes_hut.dir/main.c.s"
	/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/main.c -o CMakeFiles/barnes_hut.dir/main.c.s

# Object files for target barnes_hut
barnes_hut_OBJECTS = \
"CMakeFiles/barnes_hut.dir/system.c.o" \
"CMakeFiles/barnes_hut.dir/stack.c.o" \
"CMakeFiles/barnes_hut.dir/q-tree.c.o" \
"CMakeFiles/barnes_hut.dir/physics.c.o" \
"CMakeFiles/barnes_hut.dir/main.c.o"

# External object files for target barnes_hut
barnes_hut_EXTERNAL_OBJECTS =

barnes_hut: CMakeFiles/barnes_hut.dir/system.c.o
barnes_hut: CMakeFiles/barnes_hut.dir/stack.c.o
barnes_hut: CMakeFiles/barnes_hut.dir/q-tree.c.o
barnes_hut: CMakeFiles/barnes_hut.dir/physics.c.o
barnes_hut: CMakeFiles/barnes_hut.dir/main.c.o
barnes_hut: CMakeFiles/barnes_hut.dir/build.make
barnes_hut: CMakeFiles/barnes_hut.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable barnes_hut"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/barnes_hut.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/barnes_hut.dir/build: barnes_hut
.PHONY : CMakeFiles/barnes_hut.dir/build

CMakeFiles/barnes_hut.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/barnes_hut.dir/cmake_clean.cmake
.PHONY : CMakeFiles/barnes_hut.dir/clean

CMakeFiles/barnes_hut.dir/depend:
	cd /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/cmake-build-debug /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/cmake-build-debug /home/jsmolka/Programowanie/Projekty/Astrophisics/Simulation1/barnes-hut/cmake-build-debug/CMakeFiles/barnes_hut.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/barnes_hut.dir/depend


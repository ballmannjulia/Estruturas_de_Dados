# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_SOURCE_DIR = /workspaces/Estruturas_de_Dados

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/Estruturas_de_Dados/build

# Include any dependencies generated for this target.
include CMakeFiles/doubly_linked_list_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/doubly_linked_list_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/doubly_linked_list_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/doubly_linked_list_test.dir/flags.make

CMakeFiles/doubly_linked_list_test.dir/test/doubly_linked_list.cpp.o: CMakeFiles/doubly_linked_list_test.dir/flags.make
CMakeFiles/doubly_linked_list_test.dir/test/doubly_linked_list.cpp.o: /workspaces/Estruturas_de_Dados/test/doubly_linked_list.cpp
CMakeFiles/doubly_linked_list_test.dir/test/doubly_linked_list.cpp.o: CMakeFiles/doubly_linked_list_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/Estruturas_de_Dados/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/doubly_linked_list_test.dir/test/doubly_linked_list.cpp.o"
	/opt/rh/gcc-toolset-14/root/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/doubly_linked_list_test.dir/test/doubly_linked_list.cpp.o -MF CMakeFiles/doubly_linked_list_test.dir/test/doubly_linked_list.cpp.o.d -o CMakeFiles/doubly_linked_list_test.dir/test/doubly_linked_list.cpp.o -c /workspaces/Estruturas_de_Dados/test/doubly_linked_list.cpp

CMakeFiles/doubly_linked_list_test.dir/test/doubly_linked_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/doubly_linked_list_test.dir/test/doubly_linked_list.cpp.i"
	/opt/rh/gcc-toolset-14/root/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/Estruturas_de_Dados/test/doubly_linked_list.cpp > CMakeFiles/doubly_linked_list_test.dir/test/doubly_linked_list.cpp.i

CMakeFiles/doubly_linked_list_test.dir/test/doubly_linked_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/doubly_linked_list_test.dir/test/doubly_linked_list.cpp.s"
	/opt/rh/gcc-toolset-14/root/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/Estruturas_de_Dados/test/doubly_linked_list.cpp -o CMakeFiles/doubly_linked_list_test.dir/test/doubly_linked_list.cpp.s

# Object files for target doubly_linked_list_test
doubly_linked_list_test_OBJECTS = \
"CMakeFiles/doubly_linked_list_test.dir/test/doubly_linked_list.cpp.o"

# External object files for target doubly_linked_list_test
doubly_linked_list_test_EXTERNAL_OBJECTS =

doubly_linked_list_test: CMakeFiles/doubly_linked_list_test.dir/test/doubly_linked_list.cpp.o
doubly_linked_list_test: CMakeFiles/doubly_linked_list_test.dir/build.make
doubly_linked_list_test: CMakeFiles/doubly_linked_list_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/Estruturas_de_Dados/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable doubly_linked_list_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/doubly_linked_list_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/doubly_linked_list_test.dir/build: doubly_linked_list_test
.PHONY : CMakeFiles/doubly_linked_list_test.dir/build

CMakeFiles/doubly_linked_list_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/doubly_linked_list_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/doubly_linked_list_test.dir/clean

CMakeFiles/doubly_linked_list_test.dir/depend:
	cd /workspaces/Estruturas_de_Dados/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/Estruturas_de_Dados /workspaces/Estruturas_de_Dados /workspaces/Estruturas_de_Dados/build /workspaces/Estruturas_de_Dados/build /workspaces/Estruturas_de_Dados/build/CMakeFiles/doubly_linked_list_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/doubly_linked_list_test.dir/depend


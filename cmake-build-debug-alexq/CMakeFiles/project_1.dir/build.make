# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /users/guest/a/alexqian/CS236/project-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /users/guest/a/alexqian/CS236/project-1/cmake-build-debug-alexq

# Include any dependencies generated for this target.
include CMakeFiles/project_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project_1.dir/flags.make

CMakeFiles/project_1.dir/Project1_Starter_Code/Lexer.cpp.o: CMakeFiles/project_1.dir/flags.make
CMakeFiles/project_1.dir/Project1_Starter_Code/Lexer.cpp.o: ../Project1_Starter_Code/Lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/guest/a/alexqian/CS236/project-1/cmake-build-debug-alexq/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project_1.dir/Project1_Starter_Code/Lexer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1.dir/Project1_Starter_Code/Lexer.cpp.o -c /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/Lexer.cpp

CMakeFiles/project_1.dir/Project1_Starter_Code/Lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1.dir/Project1_Starter_Code/Lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/Lexer.cpp > CMakeFiles/project_1.dir/Project1_Starter_Code/Lexer.cpp.i

CMakeFiles/project_1.dir/Project1_Starter_Code/Lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1.dir/Project1_Starter_Code/Lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/Lexer.cpp -o CMakeFiles/project_1.dir/Project1_Starter_Code/Lexer.cpp.s

CMakeFiles/project_1.dir/Project1_Starter_Code/main.cpp.o: CMakeFiles/project_1.dir/flags.make
CMakeFiles/project_1.dir/Project1_Starter_Code/main.cpp.o: ../Project1_Starter_Code/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/guest/a/alexqian/CS236/project-1/cmake-build-debug-alexq/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project_1.dir/Project1_Starter_Code/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1.dir/Project1_Starter_Code/main.cpp.o -c /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/main.cpp

CMakeFiles/project_1.dir/Project1_Starter_Code/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1.dir/Project1_Starter_Code/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/main.cpp > CMakeFiles/project_1.dir/Project1_Starter_Code/main.cpp.i

CMakeFiles/project_1.dir/Project1_Starter_Code/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1.dir/Project1_Starter_Code/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/main.cpp -o CMakeFiles/project_1.dir/Project1_Starter_Code/main.cpp.s

CMakeFiles/project_1.dir/Project1_Starter_Code/Token.cpp.o: CMakeFiles/project_1.dir/flags.make
CMakeFiles/project_1.dir/Project1_Starter_Code/Token.cpp.o: ../Project1_Starter_Code/Token.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/guest/a/alexqian/CS236/project-1/cmake-build-debug-alexq/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project_1.dir/Project1_Starter_Code/Token.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1.dir/Project1_Starter_Code/Token.cpp.o -c /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/Token.cpp

CMakeFiles/project_1.dir/Project1_Starter_Code/Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1.dir/Project1_Starter_Code/Token.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/Token.cpp > CMakeFiles/project_1.dir/Project1_Starter_Code/Token.cpp.i

CMakeFiles/project_1.dir/Project1_Starter_Code/Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1.dir/Project1_Starter_Code/Token.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/Token.cpp -o CMakeFiles/project_1.dir/Project1_Starter_Code/Token.cpp.s

CMakeFiles/project_1.dir/Project1_Starter_Code/MatcherAutomaton.cpp.o: CMakeFiles/project_1.dir/flags.make
CMakeFiles/project_1.dir/Project1_Starter_Code/MatcherAutomaton.cpp.o: ../Project1_Starter_Code/MatcherAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/guest/a/alexqian/CS236/project-1/cmake-build-debug-alexq/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/project_1.dir/Project1_Starter_Code/MatcherAutomaton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1.dir/Project1_Starter_Code/MatcherAutomaton.cpp.o -c /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/MatcherAutomaton.cpp

CMakeFiles/project_1.dir/Project1_Starter_Code/MatcherAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1.dir/Project1_Starter_Code/MatcherAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/MatcherAutomaton.cpp > CMakeFiles/project_1.dir/Project1_Starter_Code/MatcherAutomaton.cpp.i

CMakeFiles/project_1.dir/Project1_Starter_Code/MatcherAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1.dir/Project1_Starter_Code/MatcherAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/MatcherAutomaton.cpp -o CMakeFiles/project_1.dir/Project1_Starter_Code/MatcherAutomaton.cpp.s

CMakeFiles/project_1.dir/Project1_Starter_Code/IDAutomaton.cpp.o: CMakeFiles/project_1.dir/flags.make
CMakeFiles/project_1.dir/Project1_Starter_Code/IDAutomaton.cpp.o: ../Project1_Starter_Code/IDAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/guest/a/alexqian/CS236/project-1/cmake-build-debug-alexq/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/project_1.dir/Project1_Starter_Code/IDAutomaton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1.dir/Project1_Starter_Code/IDAutomaton.cpp.o -c /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/IDAutomaton.cpp

CMakeFiles/project_1.dir/Project1_Starter_Code/IDAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1.dir/Project1_Starter_Code/IDAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/IDAutomaton.cpp > CMakeFiles/project_1.dir/Project1_Starter_Code/IDAutomaton.cpp.i

CMakeFiles/project_1.dir/Project1_Starter_Code/IDAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1.dir/Project1_Starter_Code/IDAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/IDAutomaton.cpp -o CMakeFiles/project_1.dir/Project1_Starter_Code/IDAutomaton.cpp.s

CMakeFiles/project_1.dir/Project1_Starter_Code/StringAutomaton.cpp.o: CMakeFiles/project_1.dir/flags.make
CMakeFiles/project_1.dir/Project1_Starter_Code/StringAutomaton.cpp.o: ../Project1_Starter_Code/StringAutomaton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/guest/a/alexqian/CS236/project-1/cmake-build-debug-alexq/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/project_1.dir/Project1_Starter_Code/StringAutomaton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1.dir/Project1_Starter_Code/StringAutomaton.cpp.o -c /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/StringAutomaton.cpp

CMakeFiles/project_1.dir/Project1_Starter_Code/StringAutomaton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1.dir/Project1_Starter_Code/StringAutomaton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/StringAutomaton.cpp > CMakeFiles/project_1.dir/Project1_Starter_Code/StringAutomaton.cpp.i

CMakeFiles/project_1.dir/Project1_Starter_Code/StringAutomaton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1.dir/Project1_Starter_Code/StringAutomaton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/StringAutomaton.cpp -o CMakeFiles/project_1.dir/Project1_Starter_Code/StringAutomaton.cpp.s

CMakeFiles/project_1.dir/Project1_Starter_Code/BlockComment.cpp.o: CMakeFiles/project_1.dir/flags.make
CMakeFiles/project_1.dir/Project1_Starter_Code/BlockComment.cpp.o: ../Project1_Starter_Code/BlockComment.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/guest/a/alexqian/CS236/project-1/cmake-build-debug-alexq/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/project_1.dir/Project1_Starter_Code/BlockComment.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1.dir/Project1_Starter_Code/BlockComment.cpp.o -c /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/BlockComment.cpp

CMakeFiles/project_1.dir/Project1_Starter_Code/BlockComment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1.dir/Project1_Starter_Code/BlockComment.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/BlockComment.cpp > CMakeFiles/project_1.dir/Project1_Starter_Code/BlockComment.cpp.i

CMakeFiles/project_1.dir/Project1_Starter_Code/BlockComment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1.dir/Project1_Starter_Code/BlockComment.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/BlockComment.cpp -o CMakeFiles/project_1.dir/Project1_Starter_Code/BlockComment.cpp.s

CMakeFiles/project_1.dir/Project1_Starter_Code/LineComment.cpp.o: CMakeFiles/project_1.dir/flags.make
CMakeFiles/project_1.dir/Project1_Starter_Code/LineComment.cpp.o: ../Project1_Starter_Code/LineComment.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/guest/a/alexqian/CS236/project-1/cmake-build-debug-alexq/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/project_1.dir/Project1_Starter_Code/LineComment.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project_1.dir/Project1_Starter_Code/LineComment.cpp.o -c /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/LineComment.cpp

CMakeFiles/project_1.dir/Project1_Starter_Code/LineComment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project_1.dir/Project1_Starter_Code/LineComment.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/LineComment.cpp > CMakeFiles/project_1.dir/Project1_Starter_Code/LineComment.cpp.i

CMakeFiles/project_1.dir/Project1_Starter_Code/LineComment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project_1.dir/Project1_Starter_Code/LineComment.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/guest/a/alexqian/CS236/project-1/Project1_Starter_Code/LineComment.cpp -o CMakeFiles/project_1.dir/Project1_Starter_Code/LineComment.cpp.s

# Object files for target project_1
project_1_OBJECTS = \
"CMakeFiles/project_1.dir/Project1_Starter_Code/Lexer.cpp.o" \
"CMakeFiles/project_1.dir/Project1_Starter_Code/main.cpp.o" \
"CMakeFiles/project_1.dir/Project1_Starter_Code/Token.cpp.o" \
"CMakeFiles/project_1.dir/Project1_Starter_Code/MatcherAutomaton.cpp.o" \
"CMakeFiles/project_1.dir/Project1_Starter_Code/IDAutomaton.cpp.o" \
"CMakeFiles/project_1.dir/Project1_Starter_Code/StringAutomaton.cpp.o" \
"CMakeFiles/project_1.dir/Project1_Starter_Code/BlockComment.cpp.o" \
"CMakeFiles/project_1.dir/Project1_Starter_Code/LineComment.cpp.o"

# External object files for target project_1
project_1_EXTERNAL_OBJECTS =

project_1: CMakeFiles/project_1.dir/Project1_Starter_Code/Lexer.cpp.o
project_1: CMakeFiles/project_1.dir/Project1_Starter_Code/main.cpp.o
project_1: CMakeFiles/project_1.dir/Project1_Starter_Code/Token.cpp.o
project_1: CMakeFiles/project_1.dir/Project1_Starter_Code/MatcherAutomaton.cpp.o
project_1: CMakeFiles/project_1.dir/Project1_Starter_Code/IDAutomaton.cpp.o
project_1: CMakeFiles/project_1.dir/Project1_Starter_Code/StringAutomaton.cpp.o
project_1: CMakeFiles/project_1.dir/Project1_Starter_Code/BlockComment.cpp.o
project_1: CMakeFiles/project_1.dir/Project1_Starter_Code/LineComment.cpp.o
project_1: CMakeFiles/project_1.dir/build.make
project_1: CMakeFiles/project_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/users/guest/a/alexqian/CS236/project-1/cmake-build-debug-alexq/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable project_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project_1.dir/build: project_1

.PHONY : CMakeFiles/project_1.dir/build

CMakeFiles/project_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project_1.dir/clean

CMakeFiles/project_1.dir/depend:
	cd /users/guest/a/alexqian/CS236/project-1/cmake-build-debug-alexq && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /users/guest/a/alexqian/CS236/project-1 /users/guest/a/alexqian/CS236/project-1 /users/guest/a/alexqian/CS236/project-1/cmake-build-debug-alexq /users/guest/a/alexqian/CS236/project-1/cmake-build-debug-alexq /users/guest/a/alexqian/CS236/project-1/cmake-build-debug-alexq/CMakeFiles/project_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project_1.dir/depend


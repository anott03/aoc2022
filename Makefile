# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/amitav/repos/aoc2022

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amitav/repos/aoc2022

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/amitav/repos/aoc2022/CMakeFiles /home/amitav/repos/aoc2022//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/amitav/repos/aoc2022/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named out/day1

# Build rule for target.
out/day1: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 out/day1
.PHONY : out/day1

# fast build rule for target.
out/day1/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day1.dir/build.make CMakeFiles/out/day1.dir/build
.PHONY : out/day1/fast

#=============================================================================
# Target rules for targets named out/day2

# Build rule for target.
out/day2: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 out/day2
.PHONY : out/day2

# fast build rule for target.
out/day2/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day2.dir/build.make CMakeFiles/out/day2.dir/build
.PHONY : out/day2/fast

#=============================================================================
# Target rules for targets named out/day3

# Build rule for target.
out/day3: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 out/day3
.PHONY : out/day3

# fast build rule for target.
out/day3/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day3.dir/build.make CMakeFiles/out/day3.dir/build
.PHONY : out/day3/fast

#=============================================================================
# Target rules for targets named out/day4

# Build rule for target.
out/day4: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 out/day4
.PHONY : out/day4

# fast build rule for target.
out/day4/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day4.dir/build.make CMakeFiles/out/day4.dir/build
.PHONY : out/day4/fast

#=============================================================================
# Target rules for targets named out/day5

# Build rule for target.
out/day5: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 out/day5
.PHONY : out/day5

# fast build rule for target.
out/day5/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day5.dir/build.make CMakeFiles/out/day5.dir/build
.PHONY : out/day5/fast

#=============================================================================
# Target rules for targets named out/day6

# Build rule for target.
out/day6: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 out/day6
.PHONY : out/day6

# fast build rule for target.
out/day6/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day6.dir/build.make CMakeFiles/out/day6.dir/build
.PHONY : out/day6/fast

#=============================================================================
# Target rules for targets named out/day8

# Build rule for target.
out/day8: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 out/day8
.PHONY : out/day8

# fast build rule for target.
out/day8/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day8.dir/build.make CMakeFiles/out/day8.dir/build
.PHONY : out/day8/fast

#=============================================================================
# Target rules for targets named out/day9

# Build rule for target.
out/day9: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 out/day9
.PHONY : out/day9

# fast build rule for target.
out/day9/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day9.dir/build.make CMakeFiles/out/day9.dir/build
.PHONY : out/day9/fast

day1.o: day1.cpp.o
.PHONY : day1.o

# target to build an object file
day1.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day1.dir/build.make CMakeFiles/out/day1.dir/day1.cpp.o
.PHONY : day1.cpp.o

day1.i: day1.cpp.i
.PHONY : day1.i

# target to preprocess a source file
day1.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day1.dir/build.make CMakeFiles/out/day1.dir/day1.cpp.i
.PHONY : day1.cpp.i

day1.s: day1.cpp.s
.PHONY : day1.s

# target to generate assembly for a file
day1.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day1.dir/build.make CMakeFiles/out/day1.dir/day1.cpp.s
.PHONY : day1.cpp.s

day2.o: day2.cpp.o
.PHONY : day2.o

# target to build an object file
day2.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day2.dir/build.make CMakeFiles/out/day2.dir/day2.cpp.o
.PHONY : day2.cpp.o

day2.i: day2.cpp.i
.PHONY : day2.i

# target to preprocess a source file
day2.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day2.dir/build.make CMakeFiles/out/day2.dir/day2.cpp.i
.PHONY : day2.cpp.i

day2.s: day2.cpp.s
.PHONY : day2.s

# target to generate assembly for a file
day2.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day2.dir/build.make CMakeFiles/out/day2.dir/day2.cpp.s
.PHONY : day2.cpp.s

day3.o: day3.cpp.o
.PHONY : day3.o

# target to build an object file
day3.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day3.dir/build.make CMakeFiles/out/day3.dir/day3.cpp.o
.PHONY : day3.cpp.o

day3.i: day3.cpp.i
.PHONY : day3.i

# target to preprocess a source file
day3.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day3.dir/build.make CMakeFiles/out/day3.dir/day3.cpp.i
.PHONY : day3.cpp.i

day3.s: day3.cpp.s
.PHONY : day3.s

# target to generate assembly for a file
day3.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day3.dir/build.make CMakeFiles/out/day3.dir/day3.cpp.s
.PHONY : day3.cpp.s

day4.o: day4.cpp.o
.PHONY : day4.o

# target to build an object file
day4.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day4.dir/build.make CMakeFiles/out/day4.dir/day4.cpp.o
.PHONY : day4.cpp.o

day4.i: day4.cpp.i
.PHONY : day4.i

# target to preprocess a source file
day4.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day4.dir/build.make CMakeFiles/out/day4.dir/day4.cpp.i
.PHONY : day4.cpp.i

day4.s: day4.cpp.s
.PHONY : day4.s

# target to generate assembly for a file
day4.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day4.dir/build.make CMakeFiles/out/day4.dir/day4.cpp.s
.PHONY : day4.cpp.s

day5.o: day5.cpp.o
.PHONY : day5.o

# target to build an object file
day5.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day5.dir/build.make CMakeFiles/out/day5.dir/day5.cpp.o
.PHONY : day5.cpp.o

day5.i: day5.cpp.i
.PHONY : day5.i

# target to preprocess a source file
day5.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day5.dir/build.make CMakeFiles/out/day5.dir/day5.cpp.i
.PHONY : day5.cpp.i

day5.s: day5.cpp.s
.PHONY : day5.s

# target to generate assembly for a file
day5.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day5.dir/build.make CMakeFiles/out/day5.dir/day5.cpp.s
.PHONY : day5.cpp.s

day6.o: day6.cpp.o
.PHONY : day6.o

# target to build an object file
day6.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day6.dir/build.make CMakeFiles/out/day6.dir/day6.cpp.o
.PHONY : day6.cpp.o

day6.i: day6.cpp.i
.PHONY : day6.i

# target to preprocess a source file
day6.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day6.dir/build.make CMakeFiles/out/day6.dir/day6.cpp.i
.PHONY : day6.cpp.i

day6.s: day6.cpp.s
.PHONY : day6.s

# target to generate assembly for a file
day6.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day6.dir/build.make CMakeFiles/out/day6.dir/day6.cpp.s
.PHONY : day6.cpp.s

day8.o: day8.cpp.o
.PHONY : day8.o

# target to build an object file
day8.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day8.dir/build.make CMakeFiles/out/day8.dir/day8.cpp.o
.PHONY : day8.cpp.o

day8.i: day8.cpp.i
.PHONY : day8.i

# target to preprocess a source file
day8.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day8.dir/build.make CMakeFiles/out/day8.dir/day8.cpp.i
.PHONY : day8.cpp.i

day8.s: day8.cpp.s
.PHONY : day8.s

# target to generate assembly for a file
day8.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day8.dir/build.make CMakeFiles/out/day8.dir/day8.cpp.s
.PHONY : day8.cpp.s

day9.o: day9.cpp.o
.PHONY : day9.o

# target to build an object file
day9.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day9.dir/build.make CMakeFiles/out/day9.dir/day9.cpp.o
.PHONY : day9.cpp.o

day9.i: day9.cpp.i
.PHONY : day9.i

# target to preprocess a source file
day9.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day9.dir/build.make CMakeFiles/out/day9.dir/day9.cpp.i
.PHONY : day9.cpp.i

day9.s: day9.cpp.s
.PHONY : day9.s

# target to generate assembly for a file
day9.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/out/day9.dir/build.make CMakeFiles/out/day9.dir/day9.cpp.s
.PHONY : day9.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... out/day1"
	@echo "... out/day2"
	@echo "... out/day3"
	@echo "... out/day4"
	@echo "... out/day5"
	@echo "... out/day6"
	@echo "... out/day8"
	@echo "... out/day9"
	@echo "... day1.o"
	@echo "... day1.i"
	@echo "... day1.s"
	@echo "... day2.o"
	@echo "... day2.i"
	@echo "... day2.s"
	@echo "... day3.o"
	@echo "... day3.i"
	@echo "... day3.s"
	@echo "... day4.o"
	@echo "... day4.i"
	@echo "... day4.s"
	@echo "... day5.o"
	@echo "... day5.i"
	@echo "... day5.s"
	@echo "... day6.o"
	@echo "... day6.i"
	@echo "... day6.s"
	@echo "... day8.o"
	@echo "... day8.i"
	@echo "... day8.s"
	@echo "... day9.o"
	@echo "... day9.i"
	@echo "... day9.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


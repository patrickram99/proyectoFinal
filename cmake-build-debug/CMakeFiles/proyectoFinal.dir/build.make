# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\HP\Documents\GitHub\proyectoFinal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\HP\Documents\GitHub\proyectoFinal\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/proyectoFinal.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/proyectoFinal.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/proyectoFinal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proyectoFinal.dir/flags.make

CMakeFiles/proyectoFinal.dir/proyectoFinal.cpp.obj: CMakeFiles/proyectoFinal.dir/flags.make
CMakeFiles/proyectoFinal.dir/proyectoFinal.cpp.obj: ../proyectoFinal.cpp
CMakeFiles/proyectoFinal.dir/proyectoFinal.cpp.obj: CMakeFiles/proyectoFinal.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\HP\Documents\GitHub\proyectoFinal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proyectoFinal.dir/proyectoFinal.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proyectoFinal.dir/proyectoFinal.cpp.obj -MF CMakeFiles\proyectoFinal.dir\proyectoFinal.cpp.obj.d -o CMakeFiles\proyectoFinal.dir\proyectoFinal.cpp.obj -c C:\Users\HP\Documents\GitHub\proyectoFinal\proyectoFinal.cpp

CMakeFiles/proyectoFinal.dir/proyectoFinal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proyectoFinal.dir/proyectoFinal.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\HP\Documents\GitHub\proyectoFinal\proyectoFinal.cpp > CMakeFiles\proyectoFinal.dir\proyectoFinal.cpp.i

CMakeFiles/proyectoFinal.dir/proyectoFinal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proyectoFinal.dir/proyectoFinal.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\HP\Documents\GitHub\proyectoFinal\proyectoFinal.cpp -o CMakeFiles\proyectoFinal.dir\proyectoFinal.cpp.s

# Object files for target proyectoFinal
proyectoFinal_OBJECTS = \
"CMakeFiles/proyectoFinal.dir/proyectoFinal.cpp.obj"

# External object files for target proyectoFinal
proyectoFinal_EXTERNAL_OBJECTS =

proyectoFinal.exe: CMakeFiles/proyectoFinal.dir/proyectoFinal.cpp.obj
proyectoFinal.exe: CMakeFiles/proyectoFinal.dir/build.make
proyectoFinal.exe: CMakeFiles/proyectoFinal.dir/linklibs.rsp
proyectoFinal.exe: CMakeFiles/proyectoFinal.dir/objects1.rsp
proyectoFinal.exe: CMakeFiles/proyectoFinal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\HP\Documents\GitHub\proyectoFinal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable proyectoFinal.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\proyectoFinal.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proyectoFinal.dir/build: proyectoFinal.exe
.PHONY : CMakeFiles/proyectoFinal.dir/build

CMakeFiles/proyectoFinal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\proyectoFinal.dir\cmake_clean.cmake
.PHONY : CMakeFiles/proyectoFinal.dir/clean

CMakeFiles/proyectoFinal.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\HP\Documents\GitHub\proyectoFinal C:\Users\HP\Documents\GitHub\proyectoFinal C:\Users\HP\Documents\GitHub\proyectoFinal\cmake-build-debug C:\Users\HP\Documents\GitHub\proyectoFinal\cmake-build-debug C:\Users\HP\Documents\GitHub\proyectoFinal\cmake-build-debug\CMakeFiles\proyectoFinal.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proyectoFinal.dir/depend


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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.26.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.26.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hunter/dev/volumetric_engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hunter/dev/volumetric_engine/build

# Utility rule file for docs.

# Include any custom commands dependencies for this target.
include vendor/glfw/docs/CMakeFiles/docs.dir/compiler_depend.make

# Include the progress variables for this target.
include vendor/glfw/docs/CMakeFiles/docs.dir/progress.make

vendor/glfw/docs/html/index.html: vendor/glfw/docs/Doxyfile
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/include/GLFW/glfw3.h
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/include/GLFW/glfw3native.h
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/main.dox
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/news.dox
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/quick.dox
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/moving.dox
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/compile.dox
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/build.dox
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/intro.dox
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/context.dox
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/monitor.dox
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/window.dox
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/input.dox
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/vulkan.dox
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/compat.dox
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/internal.dox
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/DoxygenLayout.xml
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/header.html
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/footer.html
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/extra.css
vendor/glfw/docs/html/index.html: /Users/hunter/dev/volumetric_engine/vendor/glfw/docs/spaces.svg
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/hunter/dev/volumetric_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating HTML documentation"
	cd /Users/hunter/dev/volumetric_engine/build/vendor/glfw/docs && /opt/homebrew/bin/doxygen

docs: vendor/glfw/docs/html/index.html
docs: vendor/glfw/docs/CMakeFiles/docs.dir/build.make
.PHONY : docs

# Rule to build all files generated by this target.
vendor/glfw/docs/CMakeFiles/docs.dir/build: docs
.PHONY : vendor/glfw/docs/CMakeFiles/docs.dir/build

vendor/glfw/docs/CMakeFiles/docs.dir/clean:
	cd /Users/hunter/dev/volumetric_engine/build/vendor/glfw/docs && $(CMAKE_COMMAND) -P CMakeFiles/docs.dir/cmake_clean.cmake
.PHONY : vendor/glfw/docs/CMakeFiles/docs.dir/clean

vendor/glfw/docs/CMakeFiles/docs.dir/depend:
	cd /Users/hunter/dev/volumetric_engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hunter/dev/volumetric_engine /Users/hunter/dev/volumetric_engine/vendor/glfw/docs /Users/hunter/dev/volumetric_engine/build /Users/hunter/dev/volumetric_engine/build/vendor/glfw/docs /Users/hunter/dev/volumetric_engine/build/vendor/glfw/docs/CMakeFiles/docs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : vendor/glfw/docs/CMakeFiles/docs.dir/depend


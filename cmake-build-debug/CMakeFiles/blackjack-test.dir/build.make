# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/blackjack-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/blackjack-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/blackjack-test.dir/flags.make

Debug/blackjack-test/blackjack-test.app/Contents/Resources/CinderApp.icns: /Users/nrking0/Code/cinder_0.9.2_mac/samples/data/CinderApp.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content Debug/blackjack-test/blackjack-test.app/Contents/Resources/CinderApp.icns"
	$(CMAKE_COMMAND) -E copy /Users/nrking0/Code/cinder_0.9.2_mac/samples/data/CinderApp.icns Debug/blackjack-test/blackjack-test.app/Contents/Resources/CinderApp.icns

CMakeFiles/blackjack-test.dir/tests/test_main.cc.o: CMakeFiles/blackjack-test.dir/flags.make
CMakeFiles/blackjack-test.dir/tests/test_main.cc.o: ../tests/test_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/blackjack-test.dir/tests/test_main.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blackjack-test.dir/tests/test_main.cc.o -c /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/tests/test_main.cc

CMakeFiles/blackjack-test.dir/tests/test_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blackjack-test.dir/tests/test_main.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/tests/test_main.cc > CMakeFiles/blackjack-test.dir/tests/test_main.cc.i

CMakeFiles/blackjack-test.dir/tests/test_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blackjack-test.dir/tests/test_main.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/tests/test_main.cc -o CMakeFiles/blackjack-test.dir/tests/test_main.cc.s

CMakeFiles/blackjack-test.dir/src/card.cc.o: CMakeFiles/blackjack-test.dir/flags.make
CMakeFiles/blackjack-test.dir/src/card.cc.o: ../src/card.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/blackjack-test.dir/src/card.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blackjack-test.dir/src/card.cc.o -c /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/src/card.cc

CMakeFiles/blackjack-test.dir/src/card.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blackjack-test.dir/src/card.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/src/card.cc > CMakeFiles/blackjack-test.dir/src/card.cc.i

CMakeFiles/blackjack-test.dir/src/card.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blackjack-test.dir/src/card.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/src/card.cc -o CMakeFiles/blackjack-test.dir/src/card.cc.s

CMakeFiles/blackjack-test.dir/src/deck.cc.o: CMakeFiles/blackjack-test.dir/flags.make
CMakeFiles/blackjack-test.dir/src/deck.cc.o: ../src/deck.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/blackjack-test.dir/src/deck.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blackjack-test.dir/src/deck.cc.o -c /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/src/deck.cc

CMakeFiles/blackjack-test.dir/src/deck.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blackjack-test.dir/src/deck.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/src/deck.cc > CMakeFiles/blackjack-test.dir/src/deck.cc.i

CMakeFiles/blackjack-test.dir/src/deck.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blackjack-test.dir/src/deck.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/src/deck.cc -o CMakeFiles/blackjack-test.dir/src/deck.cc.s

CMakeFiles/blackjack-test.dir/src/player.cc.o: CMakeFiles/blackjack-test.dir/flags.make
CMakeFiles/blackjack-test.dir/src/player.cc.o: ../src/player.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/blackjack-test.dir/src/player.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blackjack-test.dir/src/player.cc.o -c /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/src/player.cc

CMakeFiles/blackjack-test.dir/src/player.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blackjack-test.dir/src/player.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/src/player.cc > CMakeFiles/blackjack-test.dir/src/player.cc.i

CMakeFiles/blackjack-test.dir/src/player.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blackjack-test.dir/src/player.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/src/player.cc -o CMakeFiles/blackjack-test.dir/src/player.cc.s

CMakeFiles/blackjack-test.dir/src/game_engine.cc.o: CMakeFiles/blackjack-test.dir/flags.make
CMakeFiles/blackjack-test.dir/src/game_engine.cc.o: ../src/game_engine.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/blackjack-test.dir/src/game_engine.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blackjack-test.dir/src/game_engine.cc.o -c /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/src/game_engine.cc

CMakeFiles/blackjack-test.dir/src/game_engine.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blackjack-test.dir/src/game_engine.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/src/game_engine.cc > CMakeFiles/blackjack-test.dir/src/game_engine.cc.i

CMakeFiles/blackjack-test.dir/src/game_engine.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blackjack-test.dir/src/game_engine.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/src/game_engine.cc -o CMakeFiles/blackjack-test.dir/src/game_engine.cc.s

CMakeFiles/blackjack-test.dir/src/visual_app.cc.o: CMakeFiles/blackjack-test.dir/flags.make
CMakeFiles/blackjack-test.dir/src/visual_app.cc.o: ../src/visual_app.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/blackjack-test.dir/src/visual_app.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blackjack-test.dir/src/visual_app.cc.o -c /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/src/visual_app.cc

CMakeFiles/blackjack-test.dir/src/visual_app.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blackjack-test.dir/src/visual_app.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/src/visual_app.cc > CMakeFiles/blackjack-test.dir/src/visual_app.cc.i

CMakeFiles/blackjack-test.dir/src/visual_app.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blackjack-test.dir/src/visual_app.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/src/visual_app.cc -o CMakeFiles/blackjack-test.dir/src/visual_app.cc.s

CMakeFiles/blackjack-test.dir/tests/card_test.cc.o: CMakeFiles/blackjack-test.dir/flags.make
CMakeFiles/blackjack-test.dir/tests/card_test.cc.o: ../tests/card_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/blackjack-test.dir/tests/card_test.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blackjack-test.dir/tests/card_test.cc.o -c /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/tests/card_test.cc

CMakeFiles/blackjack-test.dir/tests/card_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blackjack-test.dir/tests/card_test.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/tests/card_test.cc > CMakeFiles/blackjack-test.dir/tests/card_test.cc.i

CMakeFiles/blackjack-test.dir/tests/card_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blackjack-test.dir/tests/card_test.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/tests/card_test.cc -o CMakeFiles/blackjack-test.dir/tests/card_test.cc.s

CMakeFiles/blackjack-test.dir/tests/deck_test.cc.o: CMakeFiles/blackjack-test.dir/flags.make
CMakeFiles/blackjack-test.dir/tests/deck_test.cc.o: ../tests/deck_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/blackjack-test.dir/tests/deck_test.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blackjack-test.dir/tests/deck_test.cc.o -c /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/tests/deck_test.cc

CMakeFiles/blackjack-test.dir/tests/deck_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blackjack-test.dir/tests/deck_test.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/tests/deck_test.cc > CMakeFiles/blackjack-test.dir/tests/deck_test.cc.i

CMakeFiles/blackjack-test.dir/tests/deck_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blackjack-test.dir/tests/deck_test.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/tests/deck_test.cc -o CMakeFiles/blackjack-test.dir/tests/deck_test.cc.s

CMakeFiles/blackjack-test.dir/tests/player_test.cc.o: CMakeFiles/blackjack-test.dir/flags.make
CMakeFiles/blackjack-test.dir/tests/player_test.cc.o: ../tests/player_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/blackjack-test.dir/tests/player_test.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blackjack-test.dir/tests/player_test.cc.o -c /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/tests/player_test.cc

CMakeFiles/blackjack-test.dir/tests/player_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blackjack-test.dir/tests/player_test.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/tests/player_test.cc > CMakeFiles/blackjack-test.dir/tests/player_test.cc.i

CMakeFiles/blackjack-test.dir/tests/player_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blackjack-test.dir/tests/player_test.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/tests/player_test.cc -o CMakeFiles/blackjack-test.dir/tests/player_test.cc.s

CMakeFiles/blackjack-test.dir/tests/game_engine_test.cc.o: CMakeFiles/blackjack-test.dir/flags.make
CMakeFiles/blackjack-test.dir/tests/game_engine_test.cc.o: ../tests/game_engine_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/blackjack-test.dir/tests/game_engine_test.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/blackjack-test.dir/tests/game_engine_test.cc.o -c /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/tests/game_engine_test.cc

CMakeFiles/blackjack-test.dir/tests/game_engine_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/blackjack-test.dir/tests/game_engine_test.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/tests/game_engine_test.cc > CMakeFiles/blackjack-test.dir/tests/game_engine_test.cc.i

CMakeFiles/blackjack-test.dir/tests/game_engine_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/blackjack-test.dir/tests/game_engine_test.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/tests/game_engine_test.cc -o CMakeFiles/blackjack-test.dir/tests/game_engine_test.cc.s

# Object files for target blackjack-test
blackjack__test_OBJECTS = \
"CMakeFiles/blackjack-test.dir/tests/test_main.cc.o" \
"CMakeFiles/blackjack-test.dir/src/card.cc.o" \
"CMakeFiles/blackjack-test.dir/src/deck.cc.o" \
"CMakeFiles/blackjack-test.dir/src/player.cc.o" \
"CMakeFiles/blackjack-test.dir/src/game_engine.cc.o" \
"CMakeFiles/blackjack-test.dir/src/visual_app.cc.o" \
"CMakeFiles/blackjack-test.dir/tests/card_test.cc.o" \
"CMakeFiles/blackjack-test.dir/tests/deck_test.cc.o" \
"CMakeFiles/blackjack-test.dir/tests/player_test.cc.o" \
"CMakeFiles/blackjack-test.dir/tests/game_engine_test.cc.o"

# External object files for target blackjack-test
blackjack__test_EXTERNAL_OBJECTS =

Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test: CMakeFiles/blackjack-test.dir/tests/test_main.cc.o
Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test: CMakeFiles/blackjack-test.dir/src/card.cc.o
Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test: CMakeFiles/blackjack-test.dir/src/deck.cc.o
Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test: CMakeFiles/blackjack-test.dir/src/player.cc.o
Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test: CMakeFiles/blackjack-test.dir/src/game_engine.cc.o
Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test: CMakeFiles/blackjack-test.dir/src/visual_app.cc.o
Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test: CMakeFiles/blackjack-test.dir/tests/card_test.cc.o
Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test: CMakeFiles/blackjack-test.dir/tests/deck_test.cc.o
Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test: CMakeFiles/blackjack-test.dir/tests/player_test.cc.o
Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test: CMakeFiles/blackjack-test.dir/tests/game_engine_test.cc.o
Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test: CMakeFiles/blackjack-test.dir/build.make
Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test: /Users/nrking0/Code/cinder_0.9.2_mac/lib/macosx/Debug/libcinder.a
Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test: /Users/nrking0/Code/cinder_0.9.2_mac/lib/macosx/libboost_system.a
Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test: /Users/nrking0/Code/cinder_0.9.2_mac/lib/macosx/libboost_filesystem.a
Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test: CMakeFiles/blackjack-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/blackjack-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/blackjack-test.dir/build: Debug/blackjack-test/blackjack-test.app/Contents/MacOS/blackjack-test
CMakeFiles/blackjack-test.dir/build: Debug/blackjack-test/blackjack-test.app/Contents/Resources/CinderApp.icns

.PHONY : CMakeFiles/blackjack-test.dir/build

CMakeFiles/blackjack-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/blackjack-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/blackjack-test.dir/clean

CMakeFiles/blackjack-test.dir/depend:
	cd /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/cmake-build-debug /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/cmake-build-debug /Users/nrking0/Code/cinder_0.9.2_mac/my-projects/final-project/cmake-build-debug/CMakeFiles/blackjack-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/blackjack-test.dir/depend


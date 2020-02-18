# - Main CMake builscript for mpags-cipher

# - Set CMake requirements then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - When Makefiles are generated, output all command lines by default
#   Do this to begin with so it's easy to see what compiler command/flags
#   are used. This can also be done by removing the 'set' command append
#   running make as a 'make VERBOSE=1'
set(CMAKE_VERBOSE_MAKEFILE ON)

# - Let compiler know the C++ standard
set(CMAKE_CXX_STANDARD 14)

# - Don't allow C++ Compiler Vendor Extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# - Use our standard set of flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

# - Declare build of mpags-cipher main program and any files needed with functions
add_executable(mpags-cipher mpags-cipher.cpp MPAGSCipher/TransformChar.cpp MPAGSCipher/processCommandLine.cpp MPAGSCipher/runCaesarCipher.cpp)

# - Tell compiler where to look for headers/include files within MPAGSCipher directory (where TransformChar.cpp is)
target_include_directories(mpags-cipher PRIVATE MPAGSCipher)

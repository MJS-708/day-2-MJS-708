
message("New subdirectory added to the build")


# - Build sub-script for MPAGSCipher library

# - Declare the build of the static MPAGSCipher library
add_library(MPAGSCipher STATIC
    CaesarCipher.hpp
    CaesarCipher.cpp
    ProcessCommandLine.hpp
    ProcessCommandLine.cpp
    TransformChar.hpp
    TransformChar.cpp
    )

target_include_directories(MPAGSCipher
    PUBLIC ${CMAKE_CURRENT_LIST_DIR} # CMake convenience variable
    # has a value equal to the absolute path to the directory holding the CMake script currently being processed
    )

target_compile_features(MPAGSCipher
    PUBLIC cxx_auto_type cxx_range_for cxx_uniform_initialization
    )

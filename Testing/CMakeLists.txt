# - Most basic test

add_executable(testHello testHello.cpp)

add_test(NAME test-hello COMMAND testHello)


# - Create Interface Library for Catch

add_library(Catch INTERFACE)

target_include_directories(Catch
      INTERFACE ${CMAKE_CURRENT_LIST_DIR})



# - First Catch-based test
#add_executable(testCatch testCatch.cpp)
#target_link_libraries(testCatch Catch)
#add_test(NAME test-catch COMMAND testCatch)



# - testTrasformChar unit test

add_executable(testTransformChar testTrasformChar.cpp)
target_link_libraries(testTransformChar MPAGSCipher Catch)
add_test(NAME test-TransformChar COMMAND testTransformChar)


# - testProcessCommandLine unit test

add_executable(testProcessCommandLine testProcessCommandLine.cpp)
target_link_libraries(testProcessCommandLine MPAGSCipher Catch)
add_test(NAME test-ProcessCommandLine COMMAND testProcessCommandLine)



# - testCaesarCipher unit test

add_executable(testCaesarCipher testCaesarCipher.cpp)
target_link_libraries(testCaesarCipher MPAGSCipher Catch)
add_test(NAME test-CaesarCipher COMMAND testCaesarCipher)


# - testCiphers unit test

add_executable(testCiphers testCiphers.cpp)
target_link_libraries(testCiphers MPAGSCipher Catch)
add_test(NAME test-Ciphers COMMAND testCiphers)
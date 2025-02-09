cmake_minimum_required(VERSION 3.20)
project(Assessment2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(mainGame
        assessment.cpp
        assessment.h
        data_processing.cpp
        hangman_guesser.cpp
        hangman_guesser.h
        main_game.cpp
        util.cpp
        util.h)
add_executable(main
        assessment.cpp
        assessment.h
        data_processing.cpp
        hangman_guesser.cpp
        hangman_guesser.h
        main.cpp
        util.cpp
        util.h)
add_executable(Test
        assessment.cpp
        assessment.h
        data_processing.cpp
        hangman_guesser.cpp
        hangman_guesser.h
        util.cpp
        util.h
        mainTest.cpp)

find_package(CppUnit CONFIG REQUIRED)
target_link_libraries(mainGame PRIVATE CppUnit)
target_link_libraries(main PRIVATE CppUnit)
target_link_libraries(Test PRIVATE CppUnit)
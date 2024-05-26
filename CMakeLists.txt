cmake_minimum_required(VERSION 3.22)
project(sine_wave_oscillator)

set(CMAKE_CXX_STANDARD 14)


# Find SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(sine_wave_oscillator
        main.cpp
        waveform.cpp
        synth.cpp
        synth.h
        input.h
        input.cpp
        ui.h
        ui.cpp)

target_include_directories(sine_wave_oscillator PRIVATE ${SFML_INCLUDE_DIR})


# Link SFML libraries to your executable
target_link_libraries(sine_wave_oscillator PRIVATE sfml-system sfml-window sfml-graphics sfml-audio)

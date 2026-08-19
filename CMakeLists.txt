cmake_minimum_required(VERSION 3.20)

# 1. Project declaration
project(main
    VERSION 1.0.0
    LANGUAGES CXX
)

# 2. Enforce C++20 standard and clang compiler 
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

# 3. Locate system ncurses installation
find_package(Curses REQUIRED)

# 4. Declare executable build target
add_executable(${PROJECT_NAME} src/main.cpp)

# 5. Link ncurses libraries and include header search paths
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CURSES_INCLUDE_DIRS})

# Optional: Enable warnings
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

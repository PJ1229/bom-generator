cmake_minimum_required(VERSION 3.18)
project(bom_generator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# locate poppler
find_package(PkgConfig REQUIRED)
pkg_check_modules(POPPLER_CPP REQUIRED poppler-cpp)

add_executable(main.exe main.cpp)

# include libraries
target_include_directories(main.exe PRIVATE ${POPPLER_CPP_INCLUDE_DIRS})
target_link_libraries(main.exe PRIVATE ${POPPLER_CPP_LIBRARIES})

# break
if(APPLE)
    execute_process(
        COMMAND brew --prefix
        OUTPUT_VARIABLE BREW_PREFIX
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    target_include_directories(main.exe PRIVATE ${BREW_PREFIX}/include)
    target_link_directories(main.exe PRIVATE ${BREW_PREFIX}/lib)
endif()

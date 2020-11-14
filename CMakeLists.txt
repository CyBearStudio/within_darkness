cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(WithinDarkness VERSION 0.0.2)

# configure a header file to pass the version number to the source code
configure_file(${PROJECT_SOURCE_DIR}/include/Version.h.in ${PROJECT_SOURCE_DIR}/include/Version.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

# search for SFML
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

# generate list of source files
file(GLOB_RECURSE WithinDarkness_FILES
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
    )

# add the executable
add_executable(WithinDarkness 
                    ${WithinDarkness_FILES}
                )

# link SFML
target_link_libraries(WithinDarkness sfml-graphics)

# required to make the version system work
target_include_directories(WithinDarkness PUBLIC "${PROJECT_SOURCE_DIR}/include")
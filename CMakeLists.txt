# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8)
project (homework1)

find_package(Boost REQUIRED COMPONENTS system thread)

include_directories(include)

add_executable(find_path 
    src/main.cpp 
    src/Map.cpp
    src/Cell.cpp
    src/FileReader.cpp
    src/Move.cpp
    src/Path.cpp
    src/BfsPathFinder.cpp
    src/UcsPathFinder.cpp
)

target_link_libraries(find_path ${Boost_LIBRARIES})
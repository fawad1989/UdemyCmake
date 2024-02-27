cmake_minimum_required(VERSION 3.22)

project(
    ProjectTemplate
    VERSION 1.0.0
    LANGUAGES C CXX)

# add_library (<Name of the Library> <Scope> .cpp file to be added)
add_library(Library STATIC my_lib.cpp) # Added a library that we created
add_executable(Executable main.cpp)


# Basically tells the linker all the executable files that need to be linked
target_link_libraries(Executable PUBLIC Library) # Executable is the file with which to link, Library is the name of the executable that need to be added

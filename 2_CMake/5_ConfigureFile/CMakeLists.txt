cmake_minimum_required(VERSION 3.22)

project(
    ProjectTemplate
    VERSION 1.0.0 # 1 is the major version (The last and the current is not same and may break), 0 isthe minor version (New features inplemented but old version works) and 0 is the minor version (bug fixing)
    LANGUAGES C CXX
    )

# Setting some normal Variables that we need for the execution of the Project

set(CMAKE_CXX_STANDARD 17) # Setting and integer value for C++ standard used in the project
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Using a boolean for turning on or off certain things e.g. to make sure C++ 17 is used always
set(CMAKE_CXX_EXTENSIONS OFF) # Turning of Extensions between different features in the C++ and GCC

#Good Practice to define varibales in the upper directory but not necessary
set(LIBRARY_NAME Library) #Added Varibale for the Library to be used all over the CMAKE
set(EXECUTABLE_NAME Executable) #Added Varibale for the Executable to be used all over the CMAKE

#Options

option(COMPILE_EXECUTABLE "Whether to Compile the Executable" ON) # COMPILE_EXECUTABLE is a variable that has boolean value of OFF

add_subdirectory(configure)
add_subdirectory(src)
if (COMPILE_EXECUTABLE)
    add_subdirectory(app)
else()
    message("Without .exe compilation")
endif()

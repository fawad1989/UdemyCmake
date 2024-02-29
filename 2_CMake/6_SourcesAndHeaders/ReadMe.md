# Adding a list of the sources and headers and exe sources

In the app or src folders, The CMakeLists.exe has a list of things to be added
- Snippet from the src/CMakeLists.txt

### BEFORE

```cmake
add_library(${LIBRARY_NAME} STATIC my_lib.cpp)

target_include_directories(${LIBRARY_NAME} PUBLIC "../inc"
                                                  "${CMAKE_BINARY_DIR}/configured_files/include")
```

### AFTER

```cmake
set(LIBRARY_SOURCES
    "my_lib.cpp"
)

set(LIBRARY_HEADERS
    "../inc/my_lib.hpp"
)

add_library(${LIBRARY_NAME} STATIC
            ${LIBRARY_SOURCES}
            ${LIBRARY_HEADERS}
)

target_include_directories(${LIBRARY_NAME} PUBLIC "../inc"
                                                  "${CMAKE_BINARY_DIR}/configured_files/include")

```

In the app folder

### BEFORE

```cmake
add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME})
```


### AFTER

```cmake
set(EXE_SOURCES
    "main.cpp"
)

add_executable(${EXECUTABLE_NAME} ${EXE_SOURCES})


target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME})
```

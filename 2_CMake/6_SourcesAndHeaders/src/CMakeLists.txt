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

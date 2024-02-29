# Adding Folders and Configuration Files

## Steps

1. Add a Folder to house a CMakeLists.txt and a config.hpp.in files

    1. In the config.hpp.in file add the following code

```cpp
#pragma once

#include <cstdint>
#include <string_view>

static constexpr std::string_view project_name = "@PROJECT_NAME@";
static constexpr std::string_view project_version = "@PROJECT_VERSION@";

static constexpr std::int32_t project_version_major = @PROJECT_VERSION_MAJOR@;
static constexpr std::int32_t project_version_minor = @PROJECT_VERSION_MINOR@;
static constexpr std::int32_t project_version_patch = @PROJECT_VERSION_PATCH@;
```

   2. The CmakeLists.txt looks as follows

```cmake
configure_file( # It configures the files
"config.hpp.in" # It acts as in input to create the .hpp file that can later be generated Automatically and used in the project
"${CMAKE_BINARY_DIR}/configured_files/include/config.hpp" ESCAPE_QUOTES #Location of the new .hpp file
)
```

2. The src directory needs to include the newly created .hpp file in the included directories as below

```cmake
add_library(${LIBRARY_NAME} STATIC my_lib.cpp)

target_include_directories(${LIBRARY_NAME} PUBLIC "../inc" # This includes the include folder for general files 
                                                  "${CMAKE_BINARY_DIR}/configured_files/include") # the newly generated .hpp file in the build/configured_files/include
```

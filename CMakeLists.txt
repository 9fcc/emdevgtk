cmake_minimum_required(VERSION 2.8)

include(FindPkgConfig)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11 -Werror=unused-result -Werror=format -Werror=implicit -Werror=return-type -Werror=uninitialized -Wno-deprecated -fPIE -pie -Wl,-z,relro")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0 -fstack-check -fbounds-check")

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O0 -fstack-protector-all -Wall")

set(PROJECT_NAME emdevgtk)

if(NOT DEFINED LIBDIR)
    if(CMAKE_INSTALL_PREFIX STREQUAL "")
        set(LIBDIR "/usr/lib/${PROJECT_NAME}")
    elseif(CMAKE_INSTALL_PREFIX STREQUAL "/opt")
        set(LIBDIR "/opt/${PROJECT_NAME}/lib")
    elseif(CMAKE_INSTALL_PREFIX STREQUAL "/usr/local")
        set(LIBDIR "/usr/local/lib/${PROJECT_NAME}")
    elseif(DEFINED CMAKE_INSTALL_PREFIX)
        set(LIBDIR "${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/lib")
    else()
        set(LIBDIR "/usr/local/lib/${PROJECT_NAME}")
    endif()
endif()

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/gtk3/gtk+/gtk")

add_subdirectory(gtkwheelcontrol)



pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(
    ${GTK3_INCLUDE_DIRS}
)

link_directories(
    ${GTK3_LIBRARY_DIRS}
)

add_definitions(${GTK3_CFLAGS_OTHER})

set(GTKCNCWIDGETS_SRCS
    gtkwheelcontrol.c
)

add_library(gtkwheelcontrol SHARED
    ${GTKCNCWIDGETS_SRCS}
)

target_link_libraries(gtkwheelcontrol
    ${GTK3_LIBRARIES}
)

message("${LIBDIR}")

install(TARGETS
    gtkwheelcontrol
DESTINATION
    "${LIBDIR}"
COMPONENT
    libraries
)



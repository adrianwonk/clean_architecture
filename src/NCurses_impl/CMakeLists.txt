add_subdirectory(NCurses_Compositor)
add_subdirectory(NCurses_ResxHandler)
add_subdirectory(NCurses_Drawer)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_sources(${PROJECT_NAME}
    PRIVATE
        main.cpp
        Log_impl/ColorfulLog.cpp
        NCurses_impl/NCursesResxManager.cpp
        Game_impl/game_loop.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/Game_impl
        ${CMAKE_CURRENT_SOURCE_DIR}/Log_impl
        ${CMAKE_CURRENT_SOURCE_DIR}/NCurses_impl
        ${CMAKE_CURRENT_SOURCE_DIR}/Quick_utils
)

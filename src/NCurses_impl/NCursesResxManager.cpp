#include "NCursesResxManager.hpp"
#include "vec3.hpp"

#include <ncurses.h>
#include <format>


NCursesResxManager::NCursesResxManager(ILog& log_obj)
    : logger(log_obj)
{}


void NCursesResxManager::init() {
    setlocale(LC_ALL, "C.UTF-8");
    if (initscr() == nullptr) {
        logger.log("failed to initialise ncurses");
        return;
    }

    cbreak();
    noecho();
    nodelay(stdscr, true);
    curs_set(0);

    if (has_colors()) {
        start_color();
    }

    logger.log("initialised NCursesHelloWorld");
}

void NCursesResxManager::cleanup(){
    endwin();
    logger.log("cleaned up NCursesHelloWorld");
}


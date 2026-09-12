#include "NCursesResxManager.hpp"
#include <ncurses.h>


NCursesResxManager::NCursesResxManager(ILog& log_obj)
    : logger(log_obj)
{ logger.log("IMPL: NCursesResxManager created. (IVisualResx)");
}

void NCursesResxManager::init() {
    setlocale(LC_ALL, "C.UTF-8");
    if (initscr() == nullptr) {
        logger.log("failed to initialise ncurses");
        exit(1);
    }

    cbreak();
    noecho();
    nodelay(stdscr, true);
    curs_set(0);

    if (has_colors()) {
        start_color();
    }

    logger.log("NCusesResxManager: initialised NCursesHelloWorld.");
}

void NCursesResxManager::cleanup(){
    endwin();
    logger.log("NCuresesResxManager: cleaned up NCursesHelloWorld.");
}


#include "NCursesHelloWorld.hpp"
#include "vec3.hpp"

#include <ncurses.h>
#include <format>

namespace{
point3 top_left {}; // MISSION CRITICAL
int WINDOW_WIDTH {20};
int WINDOW_HEIGHT {20};

void init_top_left(){
    int width;
    int height;
    getmaxyx(stdscr, height, width);
    top_left = vec3 {double(width / 2), double(height / 2), 0 } - vec3 {double(WINDOW_WIDTH / 2), double(WINDOW_HEIGHT / 2), 0};
    std::cerr << top_left << '\n';
}

}

NCursesHelloWorld::NCursesHelloWorld(ILog& log_obj)
    : logger(log_obj)
{
    logger.log("hello NCursesHelloWorld constructor");
}



void NCursesHelloWorld::init() {
    logger.log("hello NCursesHelloWorld init");
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
}

void NCursesHelloWorld::cleanup(){
    endwin();
}

void NCursesHelloWorld::draw(int x, int y, std::string_view str){
    logger.log(std::format("pos: ({}, {}), str: {}", x, y, str));
}

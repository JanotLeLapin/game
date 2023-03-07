#include "include/renderer.h"

void init_renderer() {
  initscr();
  raw();
  keypad(stdscr, 1);
  noecho();
  start_color();
}

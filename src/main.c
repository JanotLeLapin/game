#include "include/ecs/components.h"
#include "include/ecs/core.h"
#include "include/ecs/systems.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int ch;

  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  
  char running = 1;
  ComponentTable table;
  int ticks = 0;

  add_player(&table, "John Doe", 16, 16);

  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  refresh();

  printw("Press something to start the game...");

  while (running) {
    erase();

    char* ticks_str = (char*) malloc(10 * sizeof(char));
    sprintf(ticks_str, "Ticks: %d", ticks);
    mvaddstr(0, 0, ticks_str);
    free(ticks_str);

    for (int i = 0; i < table.entity_count; i++) {
      Health* health = table.health[i];
      if (health) health_system(health, &table);
    }

    for (int i = 0; i < table.entity_count; i++) {
      Sprite* sprite = table.sprite[i];
      if (sprite) sprite_system(sprite, &table);
    }

    ch = getch();
    switch (ch) {
      case 'q':
        running = 0;
        break;
      case KEY_LEFT:
        table.position[0]->x--;
        break;
      case KEY_RIGHT:
        table.position[0]->x++;
        break;
      case KEY_DOWN:
        table.position[0]->y++;
        break;
      case KEY_UP:
        table.position[0]->y--;
        break;
    }

    ticks++;
  }

  endwin();
}

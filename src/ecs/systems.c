#include "include/ecs/core.h"
#include "include/ecs/systems.h"

#include <stdio.h>
#include <ncurses.h>

void health_system(Health* health, ComponentTable* table) {
  int entity = health->entity;
  Name* name = table->name[entity];

  char* name_str = name ? name->name : "Player";
  
  // printf("%s has %d/%d HP\n", name_str, health->current, health->max);

  if (health->current == 0) {
    // printf("%s just died!\n", name_str);
    remove_entity(table, entity);
  }

  health->current--;
}

void position_system(Position* position, ComponentTable* table) {
  // printf("X: %d, Y: %d\n", position->x, position->y);
}

void sprite_system(Sprite* sprite, ComponentTable* table) {
  Position* pos = table->position[sprite->entity];
  if (!pos) {
    return;
  }

  mvaddch(pos->y, pos->x, sprite->display);
}

#pragma once

#include "include/ecs/components.h"

#define MAX_CMP 4096

typedef struct ComponentTable {
  int entity_count;
  Name* name[MAX_CMP];
  Position* position[MAX_CMP];
  Health* health[MAX_CMP];
  Sprite* sprite[MAX_CMP];

} ComponentTable;

void add_player(ComponentTable* table, char* name, int x, int y);
void remove_entity(ComponentTable*, int entity);

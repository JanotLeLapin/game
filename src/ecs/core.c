#include "include/ecs/core.h"
#include <stdio.h>
#include <stdlib.h>

void add_player(ComponentTable* table, char* name, int x, int y) {
  int id = table->entity_count;
  table->entity_count++;

  Name* name_cmp = malloc(sizeof(Name));
  name_cmp->entity = id;
  name_cmp->name = name;

  Health* health = malloc(sizeof(Health));
  health->entity = id;
  health->current = 10;
  health->max = 10;

  Position* position = malloc(sizeof(Position));
  position->entity = id;
  position->x = x;
  position->y = y;

  Sprite* sprite = malloc(sizeof(Sprite));
  sprite->entity = id;
  sprite->display = 'P';

  table->name[id] = name_cmp;
  table->health[id] = health;
  table->position[id] = position;
  table->sprite[id] = sprite;
}

void remove_entity(ComponentTable* table, int entity) {
  table->entity_count--;
  free(table->name[entity]);
  free(table->health[entity]);
  free(table->position[entity]);
  free(table->sprite[entity]);
  table->name[entity] = NULL;
  table->health[entity] = NULL;
  table->position[entity] = NULL;
  table->sprite[entity] = NULL;
}

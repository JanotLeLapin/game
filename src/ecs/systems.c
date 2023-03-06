#include "include/ecs/core.h"
#include "include/ecs/systems.h"
#include <stdio.h>

void health_system(Health* health, ComponentTable* components) {
  if (health->current > 0) {
    printf("Player has %d/%d HP\n", health->current, health->max);
    health->current--;
  }
}

void position_system(Position* position, ComponentTable* components) {
  printf("X: %d, Y: %d\n", position->x, position->y);
}

#include "include/ecs/components.h"
#include "include/ecs/core.h"
#include "include/ecs/systems.h"

#include <stdio.h>

int main() {
  Health health = (Health) { .entity = 0, .current = 100, .max = 100 };
  Position position = (Position) { .entity = 0, .x = 16, .y = 16 };

  ComponentNode health_node = { .data = &health };
  ComponentNode position_node = { .data = &position };
  
  ComponentTable components = {
    .health = health_node,
    .position = position_node,
  };

  while (1) {
    iter_component(&components, &components.health, health_system);
    iter_component(&components, &components.position, position_system);
  }
}

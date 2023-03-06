#include "include/ecs/components.h"
#include "include/ecs/core.h"
#include "include/ecs/systems.h"

#include <stdio.h>

int main() {
  ComponentTable table;

  add_player(&table, "John Doe", 69, 420);

  while (1) {
    for (int i = 0; i < table.entity_count; i++) {
      Health* health = table.health[i];
      if (health) health_system(health, &table);
    }
  }
}

#include "include/ecs/core.h"
#include <stdlib.h>

void iter_component(ComponentTable* table, ComponentNode* head, void (*f)(void* node, ComponentTable* table)) {
  ComponentNode *current = head;
  while (current) {
    (*f)(current->data, table);
    current = current->next;
  }
}

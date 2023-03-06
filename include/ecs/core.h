#pragma once

#include "include/ecs/components.h"

#define MAX_CMP 256

typedef struct ComponentNode {
  void* data;
  struct ComponentNode* next;
} ComponentNode;

typedef struct ComponentTable {
  ComponentNode position;
  ComponentNode health;
} ComponentTable;

void iter_component(ComponentTable* table, ComponentNode* head, void (*f)(void* node, ComponentTable* table));

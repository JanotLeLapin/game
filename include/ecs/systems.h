#pragma once

#include "include/ecs/components.h"
#include "include/ecs/core.h"

void health_system(Health* health, ComponentTable* table);
void position_system(Position* position, ComponentTable* table);
void sprite_system(Sprite* sprite, ComponentTable* table);

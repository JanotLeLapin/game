#pragma once

#include "include/ecs/components.h"
#include "include/ecs/core.h"

void health_system(Health* health, ComponentTable* components);
void position_system(Position* position, ComponentTable* components);

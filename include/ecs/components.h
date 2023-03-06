#pragma once

typedef struct Name {
  int entity;
  char* name;
} Name;

typedef struct Position {
  int entity;
  int x;
  int y;
} Position;

typedef struct Health {
  int entity;
  int current;
  int max;
} Health;

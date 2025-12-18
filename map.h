#ifndef MAP_H
#define MAP_H

#include "raylib.h"

#define MAP_WIDITH 10
#define MAP_HEIGHT 10

#define TILE_SIZE 64

extern int world_map[MAP_WIDITH][MAP_HEIGHT];

void DrawMap2D(void);

#endif

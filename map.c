#include "map.h"

int world_map[MAP_WIDITH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void DrawMap2D(void)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDITH; x++)
        {
            int screenX = x * TILE_SIZE;
            int screenY = y * TILE_SIZE;

            if (world_map[x][y] == 1)
            {
                DrawRectangle(screenX, screenY, TILE_SIZE, TILE_SIZE, WHITE);
            }
            else
            {
                DrawRectangle(screenX, screenY, TILE_SIZE,TILE_SIZE, BLACK);
            }
            DrawRectangleLines(screenX, screenY, TILE_SIZE, TILE_SIZE, DARKGRAY);
        }
    }   
}

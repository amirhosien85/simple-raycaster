#include "map.h"
#include<stdio.h>
#include<raylib.h>

int world_map[MAP_WIDITH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
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
void DrawMinimap(int offsetX, int offsetY, int miniTileSize)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDITH; x++)
        {
            int screenX = offsetX + (x * miniTileSize);
            int screenY = offsetY + (y * miniTileSize);

            if (world_map[x][y] > 0)
            {
                DrawRectangle(screenX, screenY, miniTileSize, miniTileSize, WHITE);
            }
            else
                DrawRectangle(screenX, screenY, miniTileSize, miniTileSize, BLACK);
            
            DrawRectangleLines(screenX, screenY, miniTileSize, miniTileSize, DARKGRAY);
        }
        
    }
    
}
void ToggleWall(int mapX, int mapY)
{
    if ((mapX >= 0 && mapX < MAP_WIDITH) && (mapY >= 0 && mapY < MAP_HEIGHT))
    {
        if (world_map[mapX][mapY] == 0)
        {
            world_map[mapX][mapY] = 1;
        }
        else
        {
            world_map[mapX][mapY] = 0;
        }
        
    }
    
}
void SaveMap(const char *fileName)
{
    FILE *file = fopen(fileName, "wb");

    if (file != NULL)
    {
        fwrite(world_map, sizeof(world_map), 1, file);

        fclose(file);

        TraceLog(LOG_INFO, "MAP SAVED SUCCESSFULLY TO: %s", fileName);
    }
    else
    {
        TraceLog(LOG_WARNING, "COULD NOT SAVE MAP!");
    }
}
void LoadMap(const char *fileName)
{
    FILE *file = fopen(fileName, "rb");

    if (file != NULL)
    {
        fread(world_map, sizeof(world_map), 1, file);

        fclose(file);

        TraceLog(LOG_INFO, "MAP LOADED SUCCESSFULLY FROM: %s", fileName);
    }
    else
    {
        TraceLog(LOG_WARNING, "SAVE FILE NOT FOUND!");
    }
    
}
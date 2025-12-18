#include "raylib.h"
#include "map.h"

int main(void)
{
    const int screenWidth = MAP_WIDITH * TILE_SIZE;
    const int screenHeigh = MAP_HEIGHT * TILE_SIZE;

    InitWindow(screenWidth, screenHeigh,"Raycasting Engine: phase_1");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(BLACK);
            DrawMap2D;
            
        EndDrawing;
    }
    
    CloseWindow();

    return 0;
}
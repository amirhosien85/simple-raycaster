#include "raylib.h"
#include "map.h"
#include "player.h"

int main(void)
{
    const int screenWidth = MAP_WIDITH * TILE_SIZE;
    const int screenHeigh = MAP_HEIGHT * TILE_SIZE;

    InitWindow(screenWidth, screenHeigh,"Raycasting Engine: phase_1");
    SetTargetFPS(60);

    InitPlayer();

    while (!WindowShouldClose())
    {
        UpdatePlayer();

        BeginDrawing();

            ClearBackground(BLACK);
            DrawMap2D();
            DrawPlayer2D();
            
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}
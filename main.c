#include "raylib.h"
#include "map.h"
#include "player.h"
#include "raycaster.h"

int main(void)
{
    const int screenWidth = 800;
    //MAP_WIDITH * TILE_SIZE;
    const int screenHeigh = 600;
    //MAP_HEIGHT * TILE_SIZE;

    InitWindow(screenWidth, screenHeigh,"Raycasting Engine: phase_2 (the 3D mode)");
    SetTargetFPS(60);

    InitPlayer();

    while (!WindowShouldClose())
    {
        UpdatePlayer();

        BeginDrawing();

            ClearBackground(BLACK);

            DrawRectangle(0, 0, screenWidth, screenHeigh / 2, DARKGRAY);
            DrawRectangle(0,screenHeigh / 2, screenWidth, screenHeigh / 2, BLUE);
            DrawRaycasting();

            DrawFPS(10,10);
            //DrawMap2D();
            //DrawPlayer2D();
            
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}
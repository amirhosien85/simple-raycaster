#include "raylib.h"
#include "map.h"
#include "player.h"
#include "raycaster.h"
#include <stdbool.h>
int main(void)
{
    const int screenWidth = 1024;
    //MAP_WIDITH * TILE_SIZE;
    const int screenHeigh = 768;
    //MAP_HEIGHT * TILE_SIZE;

    InitWindow(screenWidth, screenHeigh,"Raycasting Engine: phase_2 (the 3D mode)");
    SetTargetFPS(60);

    InitPlayer();

    bool showBigMap = 0;

    while (!WindowShouldClose())
    {
        UpdatePlayer();

        if (IsKeyPressed(KEY_M))
        {
            showBigMap = !showBigMap;
        }

        if (showBigMap && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Vector2 mousePos = GetMousePosition();

            int mapScale = 64;

            int clickedX = (int)((mousePos.x) / mapScale);
            int clickedY = (int)((mousePos.y) / mapScale);

            ToggleWall(clickedX, clickedY);
        }
        

        BeginDrawing();

            ClearBackground(BLACK);

        if (showBigMap)
        {

            DrawMinimap(0, 0, 64);
                
            DrawPlayerMinimap(0, 0, 64);
                
            DrawText("EDIT MODE: Left Click to Toggle Walls. Press 'M' to Play.", 10, 10, 20, GREEN);
        }
        else
        {

            DrawRectangle(0, 0, screenWidth, screenHeigh / 2, BLUE);
            DrawRectangle(0,screenHeigh / 2, screenWidth, screenHeigh / 2, DARKBROWN);

            DrawRaycasting();

            DrawMinimap(10, 10, 16);
            DrawPlayerMinimap(10, 10, 16);

            DrawFPS(10,200);

        }

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}
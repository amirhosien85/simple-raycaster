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

            int tileSize = 64;

                int startX = (screenWidth - (MAP_WIDITH* tileSize)) / 2;
                int startY = (screenHeigh - (MAP_HEIGHT * tileSize)) / 2;
                
                int clickedX = (int)((mousePos.x - startX) / tileSize);
                int clickedY = (int)((mousePos.y - startY) / tileSize);

                ToggleWall(clickedX, clickedY);
        }
        if (IsKeyPressed(KEY_S))
        {
            SaveMap("my_level.dat");
        }
        if (IsKeyPressed(KEY_L))
        {
            LoadMap("my_level.dat");
        }

        BeginDrawing();

            ClearBackground(BLACK);

            if (showBigMap)
            {
                int tileSize = 64;
                int startX = (screenWidth - (MAP_WIDITH * tileSize)) / 2;
                int startY = (screenHeigh - (MAP_HEIGHT * tileSize)) / 2;

                DrawMinimap(startX, startY, tileSize);
                DrawPlayerMinimap(startX, startY, tileSize);
                
                DrawRectangleLines(startX - 2, startY - 2, (MAP_WIDITH * tileSize) + 4, (MAP_HEIGHT * tileSize) + 4, GREEN);
                
                DrawText("EDIT MODE - Press 'M' to Play", 20, 20, 20, WHITE);
                DrawText("KEYS: [S] Save Map  |  [L] Load Map  |  [M] Play", 20, 50, 20, GREEN);
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
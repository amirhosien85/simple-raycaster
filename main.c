#include "raylib.h"
#include "map.h"
#include "player.h"
#include "raycaster.h"

int main(void)
{
    const int screenWidth = 1024;
    //MAP_WIDITH * TILE_SIZE;
    const int screenHeigh = 768;
    //MAP_HEIGHT * TILE_SIZE;

    InitWindow(screenWidth, screenHeigh,"Raycasting Engine: phase_2 (the 3D mode)");
    SetTargetFPS(60);

    InitPlayer();

    while (!WindowShouldClose())
    {
        UpdatePlayer();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Vector2 mousePos = GetMousePosition();

            int mapOffsetX = 10;
            int mapOffsetY = 10;
            int mapScale = 16;

            int clickedX = (int)((mousePos.x - mapOffsetX) / mapScale);
            int clickedY = (int)((mousePos.y - mapOffsetY) / mapScale);

            ToggleWall(clickedX, clickedY);
        }
        

        BeginDrawing();

            ClearBackground(BLACK);

            DrawRectangle(0, 0, screenWidth, screenHeigh / 2, BLUE);
            DrawRectangle(0,screenHeigh / 2, screenWidth, screenHeigh / 2, DARKBROWN);

            DrawRaycasting();

            DrawMinimap(10, 10, 16);
            DrawPlayerMinimap(10, 10, 16);

            DrawFPS(10,10);

            
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}
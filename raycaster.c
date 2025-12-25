#include "player.h"
#include "map.h"
#include "raycaster.h"
#include "raylib.h"
#include <math.h>

void DrawRaycasting(void)
{
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    for (int x = 0; x < screenWidth; x++)
    {
        double cameraX = 2 * x / (double)screenWidth - 1;
        
        double rayDirX = player.dir.x + player.plane.x * cameraX;
        double rayDirY = player.dir.y + player.plane.y * cameraX;





        int mapX = (int)player.pos.x;
        int mapY = (int)player.pos.y;

        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

        double sideDistX;
        double sideDiskY;

        int stepX;
        int stepY;

        int hit = 0;
        int side;

        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (player.pos.x - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player.pos.x) * deltaDistX;
        }
        if (rayDirX < 0)
        {
            stepY = -1;
            sideDiskY = (player.pos.y - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDiskY = (mapY + 1.0 - player.pos.y) * deltaDistY;
        }



        while (hit == 0)
        {
            if (sideDistX < sideDiskY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDiskY += deltaDistY;
                mapY += stepY;
                side = 1;
            }

            if (world_map[mapX][mapY] > 0)
                hit = 1;
        }

        double prepWallDist;
        if (side == 0)
            prepWallDist = (sideDistX - deltaDistX);
        else
            prepWallDist = (sideDiskY - deltaDistY);


        
        int lineHeight = (int)(screenHeight / prepWallDist);

        int drawStart= -lineHeight / 2 + screenHeight / 2;
        if (drawStart < 0)
            drawStart = 0;
        
        int drawEnd = lineHeight / 2 + screenHeight / 2;
        if (drawEnd >= screenHeight)
            drawEnd = screenHeight - 1;
        
        Color color = RED;

        if (side == 1)
            color = MAROON;
        
        DrawLine(x, drawStart, x, drawEnd, color);
        
    }
    
}
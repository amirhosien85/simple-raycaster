#include "player.h"
#include <math.h>
#include "map.h"

Player player;

const float MOVE_SPEED = 3.0f;
const float ROT_SPEED = 3.0f;

const float PLAYER_NATURAL_ENVIRONMENT = 0.1f;

void InitPlayer(void)
{
    player.pos = (Vector2){4.5f, 4.5f};
    player.dir = (Vector2){-1.0f, 0.0f};
    player.plane = (Vector2){ 0.0f, 0.66f};
}
void UpdatePlayer(void)
{
    float dt = GetFrameTime();
    float moveStep = MOVE_SPEED * dt;
    float rotStep = ROT_SPEED * dt;

    float moveX = 0;
    float moveY = 0;

    if (IsKeyDown(KEY_W))
    {
        moveX += player.dir.x * moveStep;
        moveY += player.dir.y * moveStep;
    }
    if (IsKeyDown(KEY_S))
    {
        moveX -= player.dir.x * moveStep;
        moveY -= player.dir.y * moveStep;
    }
    if (IsKeyDown(KEY_D))
    {
        moveX += -player.dir.y * moveStep;
        moveY += player.dir.x * moveStep;
    }
    if (IsKeyDown(KEY_A))
    {
        moveX -= -player.dir.y * moveStep;
        moveY -= player.dir.x * moveStep;
    }



    float newPosX = player.pos.x + moveX;

    int mapX = (int)(newPosX);
    int mapY = (int)(player.pos.y);

    if ((mapX >= 0 && mapX < MAP_WIDITH) && world_map[mapX][mapY] == 0)
    {
        player.pos.x = newPosX;
    }


        float newPosY = player.pos.y + moveY;

        mapX = (int)(player.pos.x);
        mapY = (int)(newPosY);
        
    if (mapY >= 0 && mapY < MAP_HEIGHT && world_map[mapX][mapY] == 0)
    {
        player.pos.y = newPosY;
    }

        if (IsKeyDown(KEY_LEFT))
        {
            double oldDirX = player.dir.x;
            player.dir.x = player.dir.x * cos(-rotStep) - player.dir.y * sin(-rotStep);
            player.dir.y = oldDirX * sin(-rotStep) + player.dir.y * cos(-rotStep);

            double oldPlaneX = player.plane.x;
            player.plane.x = player.plane.x * cos(-rotStep) - player.plane.y * sin(-rotStep);
            player.plane.y = oldPlaneX * sin(-rotStep) + player.plane.y * cos(-rotStep);
        }
        if (IsKeyDown(KEY_RIGHT)) 
        {
            double oldDirX = player.dir.x;
            player.dir.x = player.dir.x * cos(rotStep) - player.dir.y * sin(rotStep);
            player.dir.y = oldDirX * sin(rotStep) + player.dir.y * cos(rotStep);

            double oldPlaneX = player.plane.x;
            player.plane.x = player.plane.x * cos(rotStep) - player.plane.y * sin(rotStep);
            player.plane.y = oldPlaneX * sin(rotStep) + player.plane.y * cos(rotStep);
        }
    
}
    void DrawPlayer2D(void)
    {
        int screenX = (int)(player.pos.x * TILE_SIZE);
        int screenY = (int)(player.pos.y * TILE_SIZE);
        DrawCircle(screenX, screenY, 5 , RED);
        DrawLine(screenX, screenY, screenX + (int)(player.dir.x * 20), screenY + (int)(player.dir.y * 20), RED) ;
    }
    

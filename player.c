#include "player.h"
#include <math.h>

Player player;

const float MOVE_SPEED = 3.0f;
const float ROT_SPEED = 3.0f;

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

    if (IsKeyDown(KEY_W))
    {
        player.pos.x += player.dir.x * moveStep;
        player.pos.y += player.dir.y * moveStep;
    }
    if (IsKeyDown(KEY_S))
    {
        player.pos.x -= player.dir.x * moveStep;
        player.pos.y -= player.dir.y * moveStep;
    }
    if (IsKeyDown(KEY_D))
    {
        player.pos.x += -player.dir.y * moveStep;
        player.pos.y += player.dir.x * moveStep;
    }
    if (IsKeyDown(KEY_A))
    {
        player.pos.x -= -player.dir.y * moveStep;
        player.pos.y -= player.dir.x * moveStep;
    }
    

    if (IsKeyDown(KEY_RIGHT))
    {
        double oldDirX = player.dir.x;
        player.dir.x = player.dir.x * cos(-rotStep) - player.dir.y * sin(-rotStep);
        player.dir.y = oldDirX * sin(-rotStep) + player.dir.y * cos(-rotStep);

        double oldPlaneX = player.plane.x;
        player.plane.x = player.plane.x * cos(-rotStep) - player.plane.y * sin(-rotStep);
        player.plane.y = oldPlaneX * sin(-rotStep) + player.plane.y * cos(-rotStep);
    }

    if (IsKeyDown(KEY_LEFT)) 
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
        int screenX = (int)(player.pos.x * 64);
        int screenY = (int)(player.pos.y * 64);

        DrawCircle(screenX, screenY, 5 , RED);

        DrawLine(screenX, screenY, screenX + (int)(player.dir.x * 20), screenY + (int)(player.dir.y * 20), RED) ;
    }
    

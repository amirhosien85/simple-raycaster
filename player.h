#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct 
{
    vector2 pos;
    vector2 dir;
    vector2 plane;
    
}Player;

extern Player player;

void InitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer2D(void);

#endif
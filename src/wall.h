#ifndef WALL_H
#define WALL_H

#include "SDL2/SDL.h"
// #include "draw.h"
// #include "init.h"
#include "structs.h"
// #include "input.h"
#include <stdbool.h>

extern App app;

typedef struct Wall Wall;
struct Wall
{
    Entity *wall;
    Wall *next;
};

void *initWall(Entity *newWall);
void updateWalls();
void drawWalls();
bool checkCollision(Entity *player);

#endif
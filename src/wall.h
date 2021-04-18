#ifndef WALL_H
#define WALL_H

#include "SDL2/SDL.h"
// #include "init.h"
#include "structs.h"
// #include "input.h"
#include <stdbool.h>
#include "draw.h"

extern App app;

typedef struct Wall Wall;
struct Wall
{
    Entity structure;
    Wall *next;
};

void initWall(Entity where);
// void updateWalls();
void drawWalls();
bool checkWallCollision(Entity *object); // returns true if entity overlaps with any walls
// void freeWall(Wall *wall);
void freeAllWalls();

#endif
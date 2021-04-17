#include "wall.h"

static Wall *wallHead = NULL;

void initWall(Entity where)
{
    Wall *newWall = malloc(sizeof(Wall));
    newWall->structure = where;
    newWall->next = wallHead;
    wallHead = newWall;
}

void drawWalls()
{
    for (Wall *pointer = wallHead; pointer != NULL; pointer = pointer->next)
    {
        drawEntity(pointer->structure);
    }
}

bool checkWallCollision(Entity object)
{
    for (Wall *pointer = wallHead; pointer != NULL; pointer = pointer->next)
    {
        if (checkCollision(pointer->structure, object))
        {
            return true;
        }
    }
    return false;
}
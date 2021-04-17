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

bool checkWallCollision(Entity *object)
{
    bool returnVal = false;
    for (Wall *pointer = wallHead; pointer != NULL; pointer = pointer->next)
    {
        for (size_t i = 0; i < 10; i++)
        {
            if (!checkCollision(pointer->structure, *object))
            {
                break;
            }
            returnVal = true;
            object->position.x -= object->velocity.x * 0.1;
            object->position.y -= object->velocity.y * 0.1;
        }
    }
    return returnVal;
}
#include "wall.h"

static Wall *wallHead = NULL;

const SDL_Color wallColor = {255, 165, 0, 255};

void initWall(Entity where)
{
    where.color = wallColor;
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

            // try to "push out" the object until it doesn't collide
            object->position.x -= object->velocity.x * 0.1;
            object->position.y -= object->velocity.y * 0.1;
        }
    }
    return returnVal;
}

void freeAllWalls()
{
    Wall *tmp;
    while (wallHead != NULL)
    {
        tmp = wallHead;
        wallHead = wallHead->next;
        free(tmp);
    }
}
#include "killzone.h"

static Killzone *killzoneHead = NULL;

const SDL_Color killzoneColor = {155, 0, 155, 255};

void initKillzone(Entity where)
{
    where.color = killzoneColor;
    Killzone *newKillzone = malloc(sizeof(Killzone));
    newKillzone->structure = where;
    newKillzone->next = killzoneHead;
    killzoneHead = newKillzone;
}

void drawKillzones()
{
    for (Killzone *pointer = killzoneHead; pointer != NULL; pointer = pointer->next)
    {
        drawEntity(pointer->structure);
    }
}

bool checkKillzoneCollision(Entity *object)
{
    for (Killzone *pointer = killzoneHead; pointer != NULL; pointer = pointer->next)
    {
        if (checkCollision(pointer->structure, *object))
        {
            return true;
        }
    }
    return false;
}

void freeAllKillzones()
{
    Killzone *tmp;
    while (killzoneHead != NULL)
    {
        tmp = killzoneHead;
        killzoneHead = killzoneHead->next;
        free(tmp);
    }
}
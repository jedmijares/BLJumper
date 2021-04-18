#ifndef KILLZONE_H
#define KILLZONE_H

#include "SDL2/SDL.h"
// #include "init.h"
#include "structs.h"
// #include "input.h"
#include <stdbool.h>
#include "draw.h"

extern App app;

typedef struct Killzone Killzone;
struct Killzone
{
    Entity structure;
    Killzone *next;
};

void initKillzone(Entity where);
void drawKillzones();
bool checkKillzoneCollision(Entity *object); // returns true if entity overlaps with any killzones
void freeAllKillzones();

#endif
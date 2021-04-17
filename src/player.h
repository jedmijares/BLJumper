#ifndef PLAYER_H
#define PLAYER_H

#include "SDL2/SDL.h"
#include "draw.h"
#include "init.h"
#include "structs.h"
#include <stdbool.h>

extern App app;
// extern SDL_Texture *loadTexture(char *filename);
// extern void blit(SDL_Texture *texture, int x, int y);

Entity *initPlayer();
bool doPlayer(Entity *player);
void drawPlayer(Entity *player);

#endif
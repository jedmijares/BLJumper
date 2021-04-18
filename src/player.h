#ifndef PLAYER_H
#define PLAYER_H

#include "SDL2/SDL.h"
#include "draw.h"
#include "init.h"
#include "structs.h"
#include "input.h"
#include <stdbool.h>
#include "wall.h"

extern App app;
// extern SDL_Texture *loadTexture(char *filename);
// extern void blit(SDL_Texture *texture, int x, int y);

void initPlayer(void);
Entity getPlayer(void);
bool updatePlayer(void);
void drawPlayer(void);

#endif
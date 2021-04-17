#ifndef DRAW_H
#define DRAW_H

#include "SDL2/SDL_image.h"
#include "structs.h"
#include "SDL2/SDL.h"

extern App app;

void prepareScene(void);
void presentScene(void);
void blit(SDL_Texture *texture, Vector2 position, int width);
void drawEntity(Entity entity);
SDL_Texture *loadTexture(char *filename);

#endif
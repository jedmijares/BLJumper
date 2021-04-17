#ifndef INIT_H
#define INIT_H

// #include "common.h"
#include "SDL2/SDL_Image.h"
#include "structs.h"

#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720

void initSDL(void);
void cleanup(void);

#endif
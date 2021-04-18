#ifndef PLAYER_H
#define PLAYER_H

#include "SDL2/SDL.h"
#include "draw.h"
#include "init.h"
#include "structs.h"
#include "input.h"
#include <stdbool.h>
#include "wall.h"
#include "killzone.h"
#include "stage.h"

extern App app;

static const int PLAYER_SIZE = 50;

void initPlayer(Vector2 position);
Entity getPlayer(void);
bool updatePlayer(void);
void drawPlayer(void);

#endif
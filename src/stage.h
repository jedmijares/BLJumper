#ifndef STAGE_H
#define STAGE_H

#include "SDL2/SDL.h"
#include <stdbool.h>
#include "structs.h"
#include "player.h"
#include "wall.h"
#include "goal.h"
#include "killzone.h"

void initStage0(void);
void initStage1(void);
void initStage2(void);
void initStage3(void);
void initStage4(void);

void nextStage(void);
void resetStage(void);

#endif
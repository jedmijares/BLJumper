#ifndef GOAL_H
#define GOAL_H

#include "SDL2/SDL.h"
#include "structs.h"
#include "player.h"
#include "killzone.h"
#include "wall.h"
#include "stage.h"

static const int GOAL_SIZE = 100;

void initGoal(Vector2 position);
void updateGoal(void);
void drawGoal(void);

#endif

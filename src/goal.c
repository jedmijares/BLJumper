#include "goal.h"

static Entity goal;

void initGoal(void)
{
    memset(&goal, 0, sizeof(Entity));

    goal.position.x = SCREEN_WIDTH / 2 + 200;
    goal.position.y = SCREEN_HEIGHT / 2;
    goal.w = 100;
    goal.h = 100;
    goal.color.r = 0x00;
    goal.color.g = 0xff;
    goal.color.b = 0x00;
    goal.color.a = 0xff;
}

void updateGoal(void)
{
    if (checkCollision(goal, getPlayer()))
    {
        freeAllWalls();
    }
}

void drawGoal(void)
{
    drawEntity(goal);
}
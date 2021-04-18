#include "goal.h"

static Entity goal;

void initGoal(Vector2 position)
{
    // memset(&goal, 0, sizeof(Entity));
    goal.position = position;
    goal.w = GOAL_SIZE;
    goal.h = GOAL_SIZE;
    goal.color.r = 0x00;
    goal.color.g = 0xff;
    goal.color.b = 0x00;
    goal.color.a = 0xff;
}

void updateGoal(void)
{
    if (checkCollision(goal, getPlayer()) && getPlayer().velocity.x == 0 && getPlayer().velocity.y == 0)
    {
        freeAllKillzones();
        freeAllWalls();
        nextStage();
    }
}

void drawGoal(void)
{
    drawEntity(goal);
}
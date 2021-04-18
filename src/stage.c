#include "stage.h"

static int stage;

void nextStage(void)
{
    switch (stage)
    {
    case 0:
        initStage1();
        break;
    }
}

void initStage0(void)
{
    stage = 0;
    Vector2 playerPos = {50, SCREEN_HEIGHT / 2 - PLAYER_SIZE / 2};
    initPlayer(playerPos);
    Entity wallEntity;
    wallEntity.position.x = SCREEN_WIDTH / 2 - 150;
    wallEntity.position.y = 0;
    wallEntity.h = SCREEN_HEIGHT;
    wallEntity.w = 300;
    initWall(wallEntity);
    Vector2 goalPos = {SCREEN_WIDTH - 300, SCREEN_HEIGHT / 2 - GOAL_SIZE / 2};
    initGoal(goalPos);
}

void initStage1(void)
{
    stage = 1;
    Entity wall;
    wall.position.x = 1600;
    wall.position.y = 0;
    wall.h = SCREEN_HEIGHT;
    wall.w = 20;
    initWall(wall);
    wall.w = 200;
    wall.position.x = 1600 - wall.w;
    wall.position.y = 300;
    wall.h = SCREEN_HEIGHT - 300;
    initWall(wall);
    wall.w = 600;
    wall.position.x = 1600 - wall.w;
    wall.position.y = 600;
    wall.h = SCREEN_HEIGHT - 600;
    initWall(wall);
    Vector2 goalPos = {50, 50};
    initGoal(goalPos);
}
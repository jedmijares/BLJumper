#include "stage.h"

static int stage;
static Vector2 lastSpawnPos;

void nextStage(void)
{
    lastSpawnPos = getPlayer().position;
    switch (stage)
    {
    case 0:
        initStage1();
        break;
    case 1:
        initStage2();
        break;
    case 2:
        initStage3();
        break;
    case 3:
        initStage4();
        break;
    }
}

void resetStage(void)
{
    switch (stage)
    {
    case 0:
        initStage0();
        break;
    case 1:
        initStage1();
        break;
    case 2:
        initStage2();
        break;
    case 3:
        initStage3();
        break;
    case 4:
        initStage4();
        break;
    }
}

void initStage0(void)
{
    stage = 0;
    initPlayer(lastSpawnPos);
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
    initPlayer(lastSpawnPos);
    Entity wall;
    wall.position.x = 1500;
    wall.position.y = 0;
    wall.h = SCREEN_HEIGHT;
    wall.w = 20;
    initWall(wall);
    wall.w = 200;
    wall.position.x = 1500 - wall.w;
    wall.position.y = 300;
    wall.h = SCREEN_HEIGHT - 300;
    initWall(wall);
    wall.w = 600;
    wall.position.x = 1500 - wall.w;
    wall.position.y = 600;
    wall.h = SCREEN_HEIGHT - 600;
    initWall(wall);
    Vector2 goalPos = {50, 50};
    initGoal(goalPos);
}

void initStage2(void)
{
    stage = 2;
    initPlayer(lastSpawnPos);
    Entity killzone;
    killzone.position.x = 400;
    killzone.position.y = 300;
    killzone.h = SCREEN_HEIGHT - 600;
    killzone.w = SCREEN_WIDTH - 800;
    initKillzone(killzone);
    Vector2 goalPos = {SCREEN_WIDTH - 200, SCREEN_HEIGHT - 200};
    initGoal(goalPos);
}

void initStage3(void)
{
    stage = 3;
    initPlayer(lastSpawnPos);
    Entity wallEntity;
    wallEntity.position.x = SCREEN_WIDTH / 2 + 300;
    wallEntity.position.y = 0;
    wallEntity.h = SCREEN_HEIGHT / 2;
    wallEntity.w = 300;
    initWall(wallEntity);
    Entity killzone;
    killzone.position.x = SCREEN_WIDTH / 2 - 300;
    killzone.position.y = 0;
    killzone.h = SCREEN_HEIGHT;
    killzone.w = 600;
    initKillzone(killzone);
    Vector2 goalPos = {400, 50};
    initGoal(goalPos);
}

void initStage4(void)
{
    stage = 4;
    initPlayer(lastSpawnPos);
    Entity wallEntity;
    wallEntity.position.x = 0;
    wallEntity.position.y = 0;
    wallEntity.h = SCREEN_HEIGHT - 450;
    wallEntity.w = 300;
    initWall(wallEntity);
    wallEntity.position.x = 300;
    wallEntity.position.y = 450;
    wallEntity.h = SCREEN_HEIGHT - 450;
    wallEntity.w = 300;
    initWall(wallEntity);
    wallEntity.position.x = 600;
    wallEntity.position.y = 0;
    wallEntity.h = SCREEN_HEIGHT;
    wallEntity.w = 50;
    initWall(wallEntity);
    Entity killzone;
    killzone.position.x = 650;
    killzone.position.y = 0;
    killzone.h = SCREEN_HEIGHT;
    killzone.w = 1000;
    initKillzone(killzone);
    Vector2 goalPos = {SCREEN_WIDTH - 200, SCREEN_HEIGHT - 200};
    initGoal(goalPos);
}
#include "player.h"

static Entity nextPos;

Entity *initPlayer()
{
    Entity *player = malloc(sizeof(Entity));
    memset(player, 0, sizeof(Entity));

    player->position.x = SCREEN_WIDTH / 2;
    player->position.y = SCREEN_HEIGHT / 2;
    player->w = 50;
    player->h = 50;
    player->color.r = 0x00;
    player->color.g = 0xff;
    player->color.b = 0x00;
    player->color.a = 0xff;
    nextPos = *player; // nextPos is identical to player, except for transparency
    nextPos.color.a = 0x77;
    return player;
}

bool updatePlayer(Entity *player)
{
    const float SPEED = 5;
    bool inputting = false;
    if (getKeyHeld(SDL_SCANCODE_UP))
    {
        player->velocity.y -= SPEED;
        inputting = true;
    }

    if (getKeyHeld(SDL_SCANCODE_DOWN))
    {
        player->velocity.y += SPEED;
        inputting = true;
    }

    if (getKeyHeld(SDL_SCANCODE_LEFT))
    {
        player->velocity.x -= SPEED;
        inputting = true;
    }

    if (getKeyHeld(SDL_SCANCODE_RIGHT))
    {
        player->velocity.x += SPEED;
        inputting = true;
    }

    player->position.x += player->velocity.x;
    player->position.y += player->velocity.y;
    nextPos.position = player->position;

    bool colliding = checkWallCollision(player);

    if (!colliding || !inputting)
    {
        player->velocity.y *= 0.7;
        player->velocity.x *= 0.7;
    }

    return true;
}

void drawPlayer(Entity player)
{
    drawEntity(player);
    drawEntity(nextPos);
}
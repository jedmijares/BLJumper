#include "player.h"

Entity *initPlayer()
{
    Entity *player = malloc(sizeof(Entity));
    memset(player, 0, sizeof(Entity));

    player->position.x = SCREEN_WIDTH / 2;
    player->position.y = SCREEN_HEIGHT / 2;
    player->w = 100;
    player->h = 100;
    player->color.r = 0xff;
    player->color.g = 0x00;
    player->color.b = 0xff;
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
}
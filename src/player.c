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
    // player->texture = loadTexture("assets/player.png");
    // SDL_QueryTexture(player->texture, NULL, NULL, &player->w, &player->h);
    return player;
}

bool updatePlayer(Entity *player)
{
    const float SPEED = 5;

    if (getKeyHeld(SDL_SCANCODE_UP))
    {
        player->velocity.y -= SPEED;
    }

    if (getKeyHeld(SDL_SCANCODE_DOWN))
    {
        player->velocity.y += SPEED;
    }

    if (getKeyHeld(SDL_SCANCODE_LEFT))
    {
        player->velocity.x -= SPEED;
    }

    if (getKeyHeld(SDL_SCANCODE_RIGHT))
    {
        player->velocity.x += SPEED;
    }

    player->velocity.y *= 0.8;
    player->velocity.x *= 0.8;

    player->position.x += player->velocity.x;
    player->position.y += player->velocity.y;

    if(checkWallCollision(*player))
    {
        player->position.x -= player->velocity.x;
        player->position.y -= player->velocity.y;
    }

    return true;
}

void drawPlayer(Entity player)
{
    drawEntity(player);
}
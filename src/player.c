#include "player.h"

Entity *initPlayer()
{
    Entity *player = malloc(sizeof(Entity));
    memset(player, 0, sizeof(Entity));

    player->position.x = SCREEN_WIDTH / 2;
    player->position.y = SCREEN_HEIGHT / 2;
    player->w = 100;
    player->h = 100;
    // player->texture = loadTexture("assets/player.png");
    // SDL_QueryTexture(player->texture, NULL, NULL, &player->w, &player->h);
    return player;
}

bool doPlayer(Entity *player)
{
    if (app.held[SDL_SCANCODE_UP])
    {
        player->velocity.y -= 5;
    }

    if (app.held[SDL_SCANCODE_DOWN])
    {
        player->velocity.y += 5;
    }

    if (app.held[SDL_SCANCODE_LEFT])
    {
        player->velocity.x -= 5;
    }

    if (app.held[SDL_SCANCODE_RIGHT])
    {
        player->velocity.x += 5;
    }

    player->position.x += player->velocity.x;
    player->position.y += player->velocity.y;

    return true;
}

void drawPlayer(Entity *player)
{
    // blit(player->texture, player->position, 100);
    SDL_Rect rect = {player->position.x, player->position.y, player->w, player->h};
    SDL_SetRenderDrawColor(app.renderer, 0x00, 0xFF, 0x00, 0xFF);
    SDL_RenderFillRect(app.renderer, &rect);
}
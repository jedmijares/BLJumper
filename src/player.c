#include "player.h"

static Entity player;
static Entity nextPos; // "shadow" of position on the next frame

void initPlayer(Vector2 position)
{
    memset(&player, 0, sizeof(Entity));

    player.position = position;
    player.w = PLAYER_SIZE;
    player.h = PLAYER_SIZE;
    player.color.r = 0xff;
    player.color.g = 0x00;
    player.color.b = 0x00;
    player.color.a = 0xff;
    nextPos = player; // nextPos is identical to player, except for transparency
    nextPos.color.a = 0x77;
}

Entity getPlayer(void)
{
    return player;
}

typedef struct
{
    bool up, down, left, right;
} DisabledInputs;

bool updatePlayer(void)
{
    static bool colliding = false;
    static DisabledInputs disabled = {false, false, false, false};

    const float SPEED = 5;
    bool inputting = false;
    if (getKeyHeld(SDL_SCANCODE_UP))
    {
        if (!colliding || !disabled.up)
        {
            player.velocity.y -= SPEED;
            inputting = true;
        }
    }

    if (getKeyHeld(SDL_SCANCODE_DOWN))
    {
        if (!colliding || !disabled.down)
        {
            player.velocity.y += SPEED;
            inputting = true;
        }
    }

    if (getKeyHeld(SDL_SCANCODE_LEFT))
    {
        if (!colliding || !disabled.left)
        {
            player.velocity.x -= SPEED;
            inputting = true;
        }
    }

    if (getKeyHeld(SDL_SCANCODE_RIGHT))
    {
        if (!colliding || !disabled.right)
        {
            player.velocity.x += SPEED;
            inputting = true;
        }
    }

    player.position.x += player.velocity.x;
    player.position.y += player.velocity.y;
    nextPos.position = player.position;

    static bool oldColliding = false;
    oldColliding = colliding;
    colliding = checkWallCollision(&player);

    if (colliding && !oldColliding)
    {
        if (!getKeyHeld(SDL_SCANCODE_LEFT))
            disabled.left = true;
        else
            disabled.left = false;
        if (!getKeyHeld(SDL_SCANCODE_RIGHT))
            disabled.right = true;
        else
            disabled.right = false;
        if (!getKeyHeld(SDL_SCANCODE_DOWN))
            disabled.down = true;
        else
            disabled.down = false;
        if (!getKeyHeld(SDL_SCANCODE_UP))
            disabled.up = true;
        else
            disabled.up = false;
    }
    else if (!colliding)
    {
        memset(&disabled, 0, sizeof(disabled));
    }

    if (!colliding || !inputting)
    {
        player.velocity.y *= 0.7;
        player.velocity.x *= 0.7;
        if (fabs(player.velocity.x) < 2.0)
            player.velocity.x = 0;
        if (fabs(player.velocity.y) < 2.0)
            player.velocity.y = 0;
    }

    keepOnscreen(&player);
    return true;
}

void drawPlayer(void)
{
    drawEntity(player);
    drawEntity(nextPos);
}
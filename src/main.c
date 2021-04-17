#include "SDL2/SDL.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "player.h"
#include "wall.h"

App app;
static Entity *player;

static void logic(void);
static void draw(void);
// static void reset(void);

int main(int argc, char *argv[])
{
	memset(&app, 0, sizeof(App));
	initSDL();
	atexit(cleanup);
	app.delegate.logic = logic;
	app.delegate.draw = draw;

	player = initPlayer();
	Entity wallEntity;
	wallEntity.position.x = SCREEN_WIDTH / 3;
	wallEntity.position.y = SCREEN_HEIGHT / 3;
	wallEntity.h = 300;
	wallEntity.w = 200;
	initWall(wallEntity);

	while (1)
	{
		prepareScene();
		updateInput();
		app.delegate.logic();
		app.delegate.draw();
		presentScene();
	}

	return 0;
}

static void logic(void)
{
	updatePlayer(player);
}

static void draw(void)
{
	drawWalls();
	drawPlayer(*player);
}

// static void reset(void)
// {
// }
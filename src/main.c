#include "SDL2/SDL.h"
#include "init.h"

App app;

static void logic(void)
{
}

static void draw(void)
{
}

static void reset(void)
{
}

int main(int argc, char *argv[])
{
	memset(&app, 0, sizeof(App));
	initSDL();
	atexit(cleanup);
	app.delegate.logic = logic;
	app.delegate.draw = draw;
	
	// player = initPlayer();

	while (1)
	{
		// prepareScene();
		doInput();
		app.delegate.logic();
		app.delegate.draw();
		// presentScene();
	}

	return 0;
}
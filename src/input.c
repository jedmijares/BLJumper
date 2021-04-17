#include "input.h"

static Keyboard keyboard;

static void doKeyUp(SDL_KeyboardEvent *event)
{
	if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
	{
		keyboard.held[event->keysym.scancode] = 0;
	}
}

static void doKeyDown(SDL_KeyboardEvent *event)
{
	if (event->repeat == 0 && event->keysym.scancode < MAX_KEYBOARD_KEYS)
	{
		keyboard.held[event->keysym.scancode] = 1;
		keyboard.pressed[event->keysym.scancode] = 1;
	}
}

void updateInput(void)
{
	memset(&keyboard.pressed, 0, sizeof(keyboard.pressed));
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			exit(0);
			break;

		case SDL_KEYDOWN:
			doKeyDown(&event.key);
			break;

		case SDL_KEYUP:
			doKeyUp(&event.key);
			break;

		default:
			break;
		}
	}
}

bool getKeyPressed(SDL_Scancode key)
{
	return keyboard.pressed[key];
}

bool getKeyHeld(SDL_Scancode key)
{
	return keyboard.held[key];
}
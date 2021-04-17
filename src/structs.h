#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_KEYBOARD_KEYS 350

#include "SDL2/SDL.h"

typedef struct {
	void (*logic)(void);
	void (*draw)(void);
} Delegate;

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
	Delegate delegate;
	int held[MAX_KEYBOARD_KEYS];
	int pressed[MAX_KEYBOARD_KEYS];
} App;

typedef struct Entity Entity;
struct Entity {
	float x;
	float y;
	int w;
	int h;
	float dx;
	float dy;
	SDL_Texture *texture;
	Entity *next;
};

#endif
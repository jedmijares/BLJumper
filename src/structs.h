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

typedef struct {
	float x, y;
} Vector2;

typedef struct Entity Entity;
struct Entity {
	Vector2 position;
	int w;
	int h;
	Vector2 velocity;
	SDL_Texture *texture;
	Entity *next;
};

#endif
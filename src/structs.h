#ifndef STRUCTS_H
#define STRUCTS_H

#include "SDL2/SDL.h"

typedef struct
{
	void (*logic)(void);
	void (*draw)(void);
} Delegate;

typedef struct
{
	SDL_Renderer *renderer;
	SDL_Window *window;
	Delegate delegate;
} App;

typedef struct
{
	float x, y;
} Vector2;

typedef struct Entity Entity;
struct Entity
{
	Vector2 position;
	int w;
	int h;
	Vector2 velocity;
	// SDL_Texture *texture;
	// Entity *next;
};

#endif
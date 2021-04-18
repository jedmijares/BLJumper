#ifndef STRUCTS_H
#define STRUCTS_H

#include "SDL2/SDL.h"
#include <stdbool.h>
#include "init.h"

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
	float x;
	float y;
} Vector2;

typedef struct Entity Entity;
struct Entity
{
	Vector2 position;
	float w;
	float h;
	Vector2 velocity;
	SDL_Color color;
	// SDL_Texture *texture;
	// Entity *next;
};

// returns true if the entities overlap
bool checkCollision(Entity e1, Entity e2);

void keepOnscreen(Entity *entity);

#endif
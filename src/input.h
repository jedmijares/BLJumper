#ifndef INPUT_H
#define INPUT_H

#define MAX_KEYBOARD_KEYS 350

#include "SDL2/SDL.h"
#include <stdbool.h>

typedef struct
{
    int held[MAX_KEYBOARD_KEYS];
    int pressed[MAX_KEYBOARD_KEYS];
} Keyboard;

void updateInput(void);
bool getKeyPressed(SDL_Scancode key);
bool getKeyHeld(SDL_Scancode key);

#endif
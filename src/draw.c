#include "draw.h"
#include <stdio.h>

void prepareScene(void)
{
	SDL_SetRenderDrawColor(app.renderer, 96, 128, 255, 255);
	SDL_RenderClear(app.renderer);
}

void presentScene(void)
{
	SDL_RenderPresent(app.renderer);
}

SDL_Texture *loadTexture(char *filename)
{
	SDL_Texture *texture;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	texture = IMG_LoadTexture(app.renderer, filename);

	return texture;
}

void blit(SDL_Texture *texture, Vector2 position, int width)
{
	SDL_Rect dest;

	dest.x = position.x;
	dest.y = position.y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	if (width != 0)
	{
		dest.h = ((float)width) / dest.w * dest.h;
		dest.w = width;
		// printf("Decimals: %d %ld\n", dest.h, dest.w);
	}

	SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}

void drawEntity(Entity entity)
{
	SDL_Rect rect = {entity.position.x, entity.position.y, entity.w, entity.h};
	SDL_SetRenderDrawColor(app.renderer, entity.color.r, entity.color.g, entity.color.b, entity.color.a);
	SDL_RenderFillRect(app.renderer, &rect);
}
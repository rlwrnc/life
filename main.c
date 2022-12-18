#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "render.h"
#include "logic.h"

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Could not initialize SDL! Error: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow("The Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        fprintf(stderr, "Could not initialize window! Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        fprintf(stderr, "Could not initialize renderer! Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    Game game;
    for (int i = 0; i < BOARD_SIZE; i++)
        game.board[i] = 0;
    game.state = PLACE;

    SDL_Event e;
    while (game.state != QUIT) {
        while (SDL_PollEvent(&e) != 0)
            handleInput(&game, &e);
        
        SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(renderer);
        renderGame(renderer, &game);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}

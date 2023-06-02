#include <stdio.h>
#include "SDL.h"
#include "Draw_Grids.h"
#include "SolveMaze1.h"
#include "RenderCells.h"
#include "AStarAlgorithm.h"

#define square_length 64
int height = 1000, width = 1000;
int i = 0, j = 0;

int main() {
    int running = 1, status = 0;
    node *obstacles = NULL, *path = NULL;
    SDL_Window *window = SDL_CreateWindow("Game Engine", 10, 10, width, height, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //SDL_SetWindowFullscreen(window, 1);
    SDL_GetWindowSize(window, &width, &height);
    SDL_Color obstacle_color = {255, 100, 240, 30}, target_color = {255, 100, 40, 30}, path_color = {200, 10, 80, 20};


    grid_details *grid = malloc(sizeof(grid_details));
    grid->path_color = &path_color;
    grid->target_color = &target_color;
    grid->obstacle_color = &obstacle_color;

    grid->length = height;
    grid->width = width;
    grid->square_dimensions = height / square_length;
    grid->squarelength = square_length;

    unsigned int a = SDL_GetTicks();
    unsigned int b = SDL_GetTicks();
    double delta = 0;


    while (running) {
        //Limiting framerate
        a = SDL_GetTicks();
        delta = a - b;


        if (delta > 1000 / 60.0) {
            b = a;

            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT)
                    running = 0;
                else if (event.type == SDL_KEYDOWN) {


                    if (event.key.keysym.sym == SDLK_ESCAPE) {
                        running = 0;

                    }

                    if (event.key.keysym.sym == SDLK_w) {
                        i--;

                    } else if (event.key.keysym.sym == SDLK_s) {
                        i++;

                    } else if (event.key.keysym.sym == SDLK_a) {
                        j--;

                    } else if (event.key.keysym.sym == SDLK_d) {
                        j++;

                    } else if (event.key.keysym.sym == SDLK_p) {
                        running = 2;

                    } else if (event.key.keysym.sym == SDLK_k) {
                        running = 3;

                    } else if (event.key.keysym.sym == SDLK_f) {
                        running = 0;
                        status = 1;
                        break;

                    }


                }
            }


            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            draw_grid(renderer, grid);
            color_rect(renderer, i, j, grid, &path_color);
            obstacles = mouse_handle(running);
            RenderLinkedCells(renderer, obstacles, grid, &obstacle_color);
            color_rect(renderer, square_length / 2, square_length / 2, grid, &target_color);
            SDL_RenderPresent(renderer);

        }


    }


    if (status) {
        //path = SolveMaze1(renderer, grid, obstacles, i, j, square_length / 2, square_length / 2);
        path = SolveUsingA(renderer, grid, obstacles, i, j, square_length / 2, square_length / 2);
        running = 1;
        while (running) {
            a = SDL_GetTicks();
            delta = a - b;


            if (delta > 1000 / 60.0) {
                b = a;

                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT)
                        running = 0;
                    else if (event.type == SDL_KEYDOWN) {
                        if (event.key.keysym.sym == SDLK_ESCAPE) {
                            running = 0;

                        }
                    }

                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL_RenderClear(renderer);
                    draw_grid(renderer, grid);
                    color_rect(renderer, i, j, grid, &path_color);
                    obstacles = mouse_handle(running);
                    color_rect(renderer, square_length / 2, square_length / 2, grid, &target_color);

                    RenderLinkedCells(renderer, obstacles, grid, &obstacle_color);
                    RenderLinkedCells(renderer, path, grid, grid->path_color);


                    SDL_RenderPresent(renderer);
                }


            }

        }

    }


    SDL_Quit();

    return 1;
}
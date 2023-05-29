#include <stdio.h>
#include "SDL.h"
#include "Draw_Grids.h"

#define square_length 64
int height = 1000, width = 1000;
int i = 0, j = 0;

int main() {
    int running = 1;

    SDL_Window *window = SDL_CreateWindow("Game Engine", 10, 10, width, height, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //SDL_SetWindowFullscreen(window, 1);
    SDL_GetWindowSize(window, &width, &height);
    SDL_Color color, mouse_color,target_color;
    color.r = 100;
    color.g = 200;
    color.b = 10;
    color.a = 10;

    mouse_color.r = 255;
    mouse_color.g = 100;
    mouse_color.b = 240;
    mouse_color.a = 30;
    grid_details *grid = malloc(sizeof(square_length));

    target_color.r = 255;
    target_color.g = 100;
    target_color.b = 40;
    target_color.a = 30;





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


        if (delta > 1000 / 120.0) {
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

                    }

                    else if (event.key.keysym.sym == SDLK_p) {
                        running=2;

                    }

                    else if (event.key.keysym.sym == SDLK_k) {
                        running=3;

                    }




                }
            }


            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            draw_grid(renderer, grid);
            color_rect(renderer, i, j, grid, &color);
            mouse_handle(renderer, grid, &mouse_color,running);

            color_rect(renderer,square_length/2,square_length/2,grid,&target_color);

            SDL_RenderPresent(renderer);






        }


    }


    SDL_Quit();

    return 1;
}
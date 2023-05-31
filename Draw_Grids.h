//
// Created by gr on 29/05/23.
//

#ifndef MICROMOUSE_DRAW_GRIDS_H
#define MICROMOUSE_DRAW_GRIDS_H

#include "LinkedList.h"
#include "SDL.h"


typedef struct grid_details {
    int length;
    int width;
    int squarelength;
    int square_dimensions;


    SDL_Color* path_color;
    SDL_Color* obstacle_color;
    SDL_Color* target_color;

} grid_details;

void draw_grid(SDL_Renderer *renderer, grid_details *grid);

void color_rect(SDL_Renderer *renderer, int top, int left, grid_details *grid, SDL_Color *color);

node *mouse_handle(int running);


#endif //MICROMOUSE_DRAW_GRIDS_H

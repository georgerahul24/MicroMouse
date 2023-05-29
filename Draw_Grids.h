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
    int*  grid;
} grid_details;

void draw_grid(SDL_Renderer *renderer, grid_details *grid);

void color_rect(SDL_Renderer *renderer, int top, int left, grid_details *grid, SDL_Color *color);

void mouse_handle(SDL_Renderer *renderer, grid_details *grid, SDL_Color *color);


#endif //MICROMOUSE_DRAW_GRIDS_H

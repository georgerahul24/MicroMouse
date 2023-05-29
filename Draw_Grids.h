//
// Created by gr on 29/05/23.
//

#ifndef MICROMOUSE_DRAW_GRIDS_H
#define MICROMOUSE_DRAW_GRIDS_H

#include "SDL.h"
typedef struct grid_details{
    int length;
    int width;
    int squarelength;
    int square_dimensions;
} grid_details;
void draw_grid(SDL_Renderer *renderer, grid_details* grid);
void color_rect(SDL_Renderer *renderer, int top, int left, grid_details *grid);
#endif //MICROMOUSE_DRAW_GRIDS_H

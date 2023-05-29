#include "Draw_Grids.h"

void draw_grid(SDL_Renderer *renderer, grid_details *grid) {
    //drawing rows
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 125);
    int incr = grid->width / grid->squarelength;
    int current_measure = 0;


    while (current_measure < grid->length) {

        SDL_RenderDrawLine(renderer, current_measure, 0, current_measure, grid->width);

        current_measure += incr;
    }


    incr = grid->length / grid->squarelength;
    current_measure = 0;


    while (current_measure < grid->length) {

        SDL_RenderDrawLine(renderer, 0, current_measure, grid->length, current_measure);

        current_measure += incr;
    }


}

void color_rect(SDL_Renderer *renderer, int top, int left, grid_details *grid) {

    int starting_top = grid->square_dimensions * top;
    int starting_left = grid->square_dimensions * left;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 125);
    SDL_Rect rect_coord;
    rect_coord.y = starting_top;
    rect_coord.x = starting_left;
    rect_coord.w = grid->square_dimensions;
    rect_coord.h = grid->square_dimensions;
    SDL_RenderFillRect(renderer, &rect_coord);




}
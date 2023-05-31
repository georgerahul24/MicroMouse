//
// Created by gr on 31/05/23.
//

#include "RenderCells.h"

void delay(float number_of_seconds) {
    // Converting time into milli_seconds
    unsigned long milli_seconds = 1000.00 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}


void RenderLinkedCells(SDL_Renderer *renderer, node *head, grid_details *grid, SDL_Color *color) {
    node *curr = head;
    while (curr != NULL) {
        RenderRect(renderer, curr->x, curr->y, grid, color);
        curr = curr->next;
    }
}

void RenderLinkedCellsAnimated(SDL_Renderer *renderer, node *head, grid_details *grid, SDL_Color *color) {
    node *curr = head;
    unsigned int a = SDL_GetTicks();
    unsigned int b = SDL_GetTicks();
    double delta = 0;


    while (curr != NULL) {
        a = SDL_GetTicks();
        delta = a - b;
       // if (delta > 1000 / 120.0)
        {
            b = a;
            RenderRect(renderer, curr->x, curr->y, grid, color);
            SDL_RenderPresent(renderer);


        }
        curr=curr->next;



    }
}


void RenderRect(SDL_Renderer *renderer, int top, int left, grid_details *grid, SDL_Color *color) {
    int starting_top = grid->square_dimensions * top;
    int starting_left = grid->square_dimensions * left;
    SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
    SDL_Rect rect_coord;
    rect_coord.y = starting_top;
    rect_coord.x = starting_left;
    rect_coord.w = grid->square_dimensions;
    rect_coord.h = grid->square_dimensions;
    SDL_RenderFillRect(renderer, &rect_coord);


}
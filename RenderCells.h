//
// Created by gr on 31/05/23.
//

#ifndef MICROMOUSE_RENDERCELLS_H
#define MICROMOUSE_RENDERCELLS_H

#include "SDL.h"
#include "LinkedList.h"
#include "Draw_Grids.h"

void RenderLinkedCells(SDL_Renderer *renderer, node *head, grid_details *grid, SDL_Color *color);
void RenderRect(SDL_Renderer *renderer, int top, int left, grid_details *grid, SDL_Color *color);
void RenderLinkedCellsAnimated(SDL_Renderer *renderer, node *head, grid_details *grid, SDL_Color *color);

#endif //MICROMOUSE_RENDERCELLS_H

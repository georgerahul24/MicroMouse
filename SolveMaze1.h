//
// Created by gr on 30/05/23.
//

#ifndef MICROMOUSE_SOLVEMAZE1_H
#define MICROMOUSE_SOLVEMAZE1_H

#include "LinkedList.h"
#include "RenderCells.h"


node *SolveMaze1(SDL_Renderer *renderer, grid_details *grid,node *obstacles, int sx, int sy, int tx,
                 int ty);

#endif //MICROMOUSE_SOLVEMAZE1_H

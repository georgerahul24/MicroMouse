//
// Created by gr on 30/05/23.
//

#include "SolveMaze1.h"

#define animation_Steps 5

void RenderScene(SDL_Renderer *renderer, grid_details *grid, node *obstacles, node *path, int tx, int ty) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    RenderLinkedCells(renderer, obstacles, grid, grid->obstacle_color);
    RenderLinkedCellsAnimated(renderer, path, grid, grid->path_color);
    color_rect(renderer, tx, ty, grid, grid->target_color);
    draw_grid(renderer, grid);
    SDL_RenderPresent(renderer);

}


node *SolveMaze1(SDL_Renderer *renderer, grid_details *grid, node *obstacles, int sx, int sy, int tx,
                 int ty) {
    node *head = NULL;
    int anim_step = 0;
    for (int i = sx; i <= tx; i++) {
        node *new = malloc(sizeof(node));
        new->next = head;
        head = new;
        new->x = sy;
        new->y = i;
        anim_step++;
        if (anim_step == animation_Steps) {
            RenderScene(renderer, grid, obstacles, head, tx, ty);
            anim_step = 0;
        }


    }

    for (int i = sy; i <= ty; i++) {
        node *new = malloc(sizeof(node));
        new->next = head;
        head = new;
        new->x = i;
        new->y = tx;
        anim_step++;
        if (anim_step == animation_Steps) {
            RenderScene(renderer, grid, obstacles, head, tx, ty);
            anim_step = 0;
        }

    }


    return head;
}

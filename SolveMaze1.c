//
// Created by gr on 30/05/23.
//

#include "SolveMaze1.h"

#define animation_Steps 3

node *SolveMaze1(SDL_Renderer *renderer, grid_details *grid, SDL_Color *color, node *obstacles, int sx, int sy, int tx,
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
        if (anim_step == 10) {
            RenderLinkedCellsAnimated(renderer, head, grid, color);
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
        if (anim_step == 10) {
            RenderLinkedCellsAnimated(renderer, head, grid, color);
            anim_step = 0;
        }

    }


    return head;
}

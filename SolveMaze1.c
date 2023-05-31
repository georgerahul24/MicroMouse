//
// Created by gr on 30/05/23.
//

#include "SolveMaze1.h"


node *SolveMaze1(SDL_Renderer *renderer, grid_details *grid, SDL_Color *color, node *obstacles, int sx, int sy, int tx,
                 int ty) {
    node *head = NULL;

    for (int i = sx; i <= tx; i++) {
        node *new = malloc(sizeof(node));
        new->next = head;
        head = new;
        new->x = sy;
        new->y = i;
        RenderLinkedCellsAnimated(renderer, head, grid, color);

    }

    for (int i = sy; i <= ty; i++) {
        node *new = malloc(sizeof(node));
        new->next = head;
        head = new;
        new->x = i;
        new->y = tx;

    }


    return head;
}

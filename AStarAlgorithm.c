//
// Created by gr on 01/06/23.
//

#include "AStarAlgorithm.h"
#define max_iterations 4096

int max(int a1, int a2) {
    return a1 > a2 ? a1 : a2;
}

int min(int a1, int a2) {
    return a1 < a2 ? a1 : a2;
}


double distance(node *n1, node *n2) {
    return sqrt(pow(n1->x - n2->x, 2) + pow(n1->y - n2->y, 2));
}


int checkInList(node *head, int x, int y) {
    node *curr = head;
    if (curr == NULL) return 0;

    while (curr != NULL) {
        if (curr->x == x && curr->y == y) return 1;
        curr = curr->next;
    }
    return 0;
}

node *getNode(node *head, int x, int y) {
    node *curr = head;
    if (curr == NULL)
        return NULL;

    while (curr != NULL) {
        if (curr->x == x && curr->y == y)
            return curr;
        curr = curr->next;
    }
    return
            NULL;
}


node *SolveUsingA(SDL_Renderer *renderer, grid_details *grid, node *obstacles, int sx, int sy, int tx,
                  int ty) {
    node *closed_list = obstacles;
    int count = 0;
    node *open_list = NULL;
    node *path = NULL;
    node *target = malloc(sizeof(node));
    target->x = tx;
    target->y = ty;
    target->visited = 0;

    node *start = malloc(sizeof(node));
    start->x = sx;
    start->y = sy;
    start->visited = 0;


    node *neighbours[8];


    //creating the openlist
    for (int x = 0; x <= 61; x++) {
        for (int y = 0; y <= 67; y++) {
            //if (!checkInList(obstacles, x, y))
            {
                node *new = malloc(sizeof(node));
                new->x = x;
                new->y = y;
                new->next = open_list;
                new->visited = 0;
                open_list = new;
            }
        }
    }


    int found = 0;
    node *curr = start;
    curr->visited = 1;
    // get the first node
    while (found == 0 && open_list != NULL && count<max_iterations) {


        int neighbour_count = 0;
        for (int m = max(0, curr->x - 1); m <= min(60, curr->x + 1); m++) {
            for (int n = max(0, curr->y - 1); n <= min(66, curr->y + 1); n++) {
                if (!(curr->x == m && curr->y == n)) {

                    if (!checkInList(obstacles, m, n) && !checkInList(path,m,n)) {
                        node *nd = getNode(open_list, m, n);
                        if (nd != NULL && nd->visited == 0) {
                            nd->h = distance(nd, target);
                            nd->g = distance(nd, start);
                            nd->f = nd->h + nd->g;
                            neighbours[neighbour_count++] = nd;
                        }


                    }

                }

            }

        }

        if (neighbour_count == 0) {
            found = 1;
            break;
        }
        int index = 0;
        double nearest = neighbours[index++]->h;
        int nearest_index = 0;
        while (index < neighbour_count) {
            if (neighbours[index]->x == target->x && neighbours[index]->y == target->y) {
                found = 1;
                printf("Hi hiell");
                break;
            }
            if (neighbours[index++]->h < nearest) {
                nearest_index = index - 1;
                nearest = neighbours[index - 1]->h;

            }

        }

        node *nd = malloc(sizeof(node));
        nd->x = neighbours[nearest_index]->x;
        nd->y = neighbours[nearest_index]->y;
        nd->next = path;
        nd->visited = 1;
        path = nd;
        curr = path;
        curr->visited = 1;

        count++;


    }

    curr = open_list;
    while (curr != NULL) {
        node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    printf("End");
    return path;
}



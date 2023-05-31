//
// Created by gr on 30/05/23.
//

#ifndef MICROMOUSE_LINKEDLIST_H
#define MICROMOUSE_LINKEDLIST_H

#include <stdlib.h>
#include "SDL.h"
typedef struct node {
    struct node *next;
    int x;
    int y;
} node;


void push(node **head, int x, int y);

node* check(node **head, int x, int y);
node* remove_element(node **head, int x, int y);
#endif //MICROMOUSE_LINKEDLIST_H

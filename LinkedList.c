//
// Created by gr on 30/05/23.
//

#include "LinkedList.h"
#define prec 5

void check(node **head, int x, int y) {
    node *curr = *head;

    if (curr == NULL) {
        push(head, x / prec, y / prec);
        return;
    }

    while (curr != NULL) {

        if (curr->x == x / prec && curr->y == y / prec) {
            return;
        }

        curr = curr->next;
    }

    push(head, x / prec, y / prec);
    return;


}

void push(node **head, int x, int y) {
    node *new = malloc(sizeof(node));
    new->x = x;
    new->y = y;
    new->next = *head;

    *head = new;
    return;
}

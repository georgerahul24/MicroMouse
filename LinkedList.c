//
// Created by gr on 30/05/23.
//

#include "LinkedList.h"

#define prec 15

//TODO:Problem with mouse alignment


node *check(node **head, int x, int y) {
    node *curr = *head;

    if (curr == NULL) {
        push(head, x / prec, y / prec);
        return head;
    }

    while (curr != NULL) {

        if (curr->x == x / prec && curr->y == y / prec) {
            return head;
        }

        curr = curr->next;
    }

    push(head, x / prec, y / prec);
    return head;


}

void push(node **head, int x, int y) {
    node *new = malloc(sizeof(node));
    new->x = x;
    new->y = y;
    new->next = *head;

    *head = new;

}


node *remove_element(node **head, int x, int y) {
    node *curr = *head;

    if (curr == NULL) {
        //If the list is empty
        return NULL;
    } else if (curr->x == x / prec && curr->y == y / prec) {
        //deleting the first element
        *head = curr->next;
        free(curr);
        return *head;
    } else {
        node *prev = *head;
        curr = (*head)->next;
        while (curr != NULL) {
            if (curr->x == x / prec && curr->y == y / prec) {
                prev->next = curr->next;
                node *temp = curr;
                free(temp);
                return *head;

            }
            prev = curr;
            curr = curr->next;


        }
    }

}

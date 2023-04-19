#include "line.h"
#include <stdlib.h>
#include <stdio.h>
Line *create_line(Point * p1, Point * p2){
    Line *l1 = (Line*) malloc(sizeof(Line));
    l1->p1 = p1;
    l1->p2 = p2;
    return l1;
}
void delete_line(Line * line){
    free(line);
}

void print_line(Line * line){
    printf("LINE: &d &d &d &d", line ->p1->pos_x, line->p1->pos_y, line->p2->pos_x, line->p2->pos_y);
}


#include "circle.h"
#include <stdlib.h>
#include <stdio.h>

Circle *create_circle(Point * center, int radius){
    Circle  *circle= (Circle*) malloc(sizeof(circle));
    circle->point = center;
    circle->radius = radius;
    return circle;
}
void delete_circle(Circle * circle){
    free(circle);
}
void print_circle(Circle * circle){
    printf("CIRCLE: %d %d %d", circle->point->pos_x, circle->point->pos_y, circle->radius);
}

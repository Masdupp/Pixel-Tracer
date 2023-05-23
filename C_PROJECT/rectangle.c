#include "rectangle.h"
#include <stdlib.h>
#include <stdio.h>
Rectangle *create_rectangle(Point * point, int width, int height){
    Rectangle *rectangle= (Rectangle*) malloc(sizeof(Rectangle));
    rectangle->corner = point;
    rectangle->width = width;
    rectangle->length = height;
    return rectangle;

}
void delete_rectangle(Rectangle * rectangle){
    free(rectangle);

}
void print_rectangle(Rectangle * rectangle){
    printf("RECTANGLE: %d %d %d %d", rectangle->corner->pos_x, rectangle->corner->pos_y, rectangle->width, rectangle->length);


}


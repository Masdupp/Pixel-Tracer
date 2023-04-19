#ifndef CPROJECT_RECTANGLE_H
#define CPROJECT_RECTANGLE_H
#include "point.h"

typedef struct {
    Point *corner;
    int length;
    int width;
}Rectangle;

Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);

#endif //CPROJECT_RECTANGLE_H

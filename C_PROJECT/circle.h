#ifndef CPROJECT_CIRCLE_H
#define CPROJECT_CIRCLE_H

#include "point.h"

typedef struct {
    Point * point;
    int radius;
}Circle;

Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);
#endif //CPROJECT_CIRCLE_H

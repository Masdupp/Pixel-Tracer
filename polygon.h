#include "point.h"
#ifndef CPROJECT_POLYGON_H
#define CPROJECT_POLYGON_H

typedef struct polygon {
    int n;
    Point ** points;
}Polygon;

Polygon *create_polygon(int n);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);

#endif //CPROJECT_POLYGON_H
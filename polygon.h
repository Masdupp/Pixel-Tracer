#include "point.h"
#ifndef CPROJECT_POLYGON_H
#define CPROJECT_POLYGON_H

typedef  struct polygon{
    int n;
    Point **points; //tableau 1D dynamique de Point*

}Polygon;

#endif //CPROJECT_POLYGON_H

Polygon *create_polygon(int n);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);


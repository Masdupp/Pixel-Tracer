#include "polygon.h"
#include <stdio.h>
#include <stdlib.h>

Polygon *create_polygon(int n){
    Polygon *polygon = (Polygon*) malloc(sizeof(Polygon));
    polygon->n=n;
    polygon->points = (Point**)malloc(n * sizeof(Point*));
    for(int i=0; i<n; i++){
        polygon->points[i] = create_point();

    }
    return polygon;
}
void delete_polygon(Polygon * polygon){
    for(int i=0; i< polygon->n; i++){
        delete_point(polygon->points[i]);
    }
    free(polygon->points);
    free(polygon);
}
void print_polygon(Polygon * polygon){
    printf("Polygon with %d points:\n", polygon->n);
    for(int i=0; i< polygon->n; i++){
        printf("Point %d: ", i+1);
        print_point(polygon->points[i]);
    }
}

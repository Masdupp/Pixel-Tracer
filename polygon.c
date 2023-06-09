#include "polygon.h"
#include "point.h"
#include <stdio.h>
#include <stdlib.h>

Polygon *create_polygon(int n){
    Polygon *p1 = (Polygon *) malloc(sizeof(Polygon));
    p1->points = (Point**)malloc(sizeof (Point)*n);
    p1->n = n;
    int i=0;
    int x,y;
    while (i<n){
        printf("Enter your point coordinates: x y \n");
        scanf("%d %d",&x,&y);
        p1->points[i] = create_point(x, y);
        i++;
    }
    return p1;
}

void delete_polygon(Polygon * polygon){
    free(polygon);
}

void print_polygon(Polygon * polygon){
    printf("POLYGON : %d points \n", polygon->n);
    int i;
    for (i = 0; i < polygon->n; i++){
        print_point(polygon->points[i]);
    }
}
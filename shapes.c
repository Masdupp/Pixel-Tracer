#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "line.h"
#include "circle.h"
#include "square.h"
#include "rectangle.h"
#include "polygon.h"
#include "id.h"

Shape *create_empty_shape(SHAPE_TYPE shape_type)
{
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = get_next_id();
    shp->shape_type = shape_type;
    return shp;
}

Shape *create_point_shape(int px, int py)
{
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    shp->id = get_next_id();
    return shp;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2){
    Shape *shp = create_empty_shape(LINE);
    Point *p1 = create_point(px1, py1);
    Point *p2 = create_point(px2, py2);
    Line *line = create_line(px1,py1, px2, py2);
    shp ->ptrShape = line;
    shp->id = get_next_id();
    return shp;
}

Shape *create_square_shape(int px, int py, int length){
    Shape *shp = create_empty_shape(SQUARE);
    Point *p = create_point(px,py);
    Square *square = create_square(p, length);
    shp-> ptrShape = square;
    shp->id = get_next_id();
    return shp;
}

Shape *create_rectangle_shape(int px, int py, int width, int height){
    Shape *shp = create_empty_shape(RECTANGLE);
    Point *p = create_point(px, py);
    Rectangle *rectangle = create_rectangle(p, width, height);
    shp->ptrShape = rectangle;
    shp->id = get_next_id();
    return shp;
}

Shape *create_circle_shape(int px, int py, int radius){
    Shape *shp = create_empty_shape(CIRCLE);
    Point *p = create_point(px, py);
    Circle *circle = create_circle(p, radius);
    shp-> ptrShape = circle;
    shp->id = get_next_id();
    return shp;
}

Shape *create_polygon_shape(int n){
    Shape *shp = create_empty_shape(POLYGON);
    Polygon *poly = create_polygon(n);
    shp->ptrShape = poly;
    return shp;
}

void delete_shape(Shape * shape){
    if(shape){
        if(shape->ptrShape){
            free(shape->ptrShape);
        }
        free(shape);
    }
    }
void print_shape(Shape * shape){
    printf("ID : %d", shape->id);
    if (shape->ptrShape == POINT) {
        print_point(shape->ptrShape);
    }
    else if(shape->ptrShape == LINE){
        print_line(shape->ptrShape);
    }
    else if(shape->ptrShape == SQUARE){
        print_square(shape->ptrShape);
    }
    else if(shape->ptrShape == CIRCLE){
        print_circle(shape->ptrShape);
    }
    else if(shape->ptrShape == RECTANGLE){
        print_rectangle(shape->ptrShape);
    }
    else if(shape->ptrShape == POLYGON){
        print_polygon(shape->ptrShape);
    }
}

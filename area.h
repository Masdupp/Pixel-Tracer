#include "shapes.h"
#include "pixel.h"
#ifndef CPROJECT_AREA_H
#define CPROJECT_AREA_H

#define SHAPE_MAX 100
#define BOOL int

struct area {
    unsigned int width;
    unsigned int height;
    BOOL** mat;
    Shape* shapes[SHAPE_MAX];
    int nb_shape;
};
typedef struct area Area;

Area* create_area(unsigned int width, unsigned int height);
void add_shape_to_area(Area* area, Shape* shape);
void remove_shape_from_area(Area* area, int ID);
void clear_area(Area* area);
void erase_area(Area* area);
void delete_area(Area* area);
int in_list(Pixel** p1, int nb_pixels, int x, int y);
void draw_area(Area* area);
void display_shapes(Area* area);
void print_area(Area* area);

#endif //CPROJECT_AREA_H
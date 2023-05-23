#ifndef CPROJECT_PIXEL_H
#define CPROJECT_PIXEL_H
#include "point.h"
#include "shapes.h"
#include "square.h"
#include "line.h"
#include "rectangle.h"
#include "polygon.h"


typedef struct pixel {
    int px;
    int py;
}Pixel;

Pixel* create_pixel(int px, int py);
void delete_pixel(Pixel* pixel);
int min(int v1,int v2);
int max(int v1, int v2);
void pixel_point(Point* point, Pixel*** pixel_tab, int* nb_pixels);
void pixel_line(Line* line, Pixel*** pixel, int* nb_pixels);
void pixel_square(Square* square, Pixel*** pixel_tab, int* nb_pixels);
Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels);
void delete_pixel_shape(Pixel** pixel, int nb_pixels);
void pixel_rectangle(Rectangle* rectangle, Pixel*** pixel_tab, int* nb_pixels);
void pixel_polygon(Polygon* polygon, Pixel*** pixel_tab, int* nb_pixels);

#endif //CPROJECT_PIXEL_H
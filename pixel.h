#ifndef PIXEL_TRACER_PIXEL_H
#define PIXEL_TRACER_PIXEL_H
#include "point.h"
#include "shapes.h"

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


#endif //C_PROJECT_PIXEL_H
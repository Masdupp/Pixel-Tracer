#include <assert.h>
#include "pixel.h"
#include "stdlib.h"
#include "stdio.h"
#include "shapes.h"
#include "line.h"
#include "point.h"
#include "square.h"

Pixel* create_pixel(int px, int py){
    Pixel *p1 = (Pixel*)malloc(sizeof (Pixel));
    p1->px = px;
    p1->py = py;
    return p1;
}

void delete_pixel(Pixel* pixel){
    free(pixel);
}

void pixel_point(Point* point, Pixel*** pixel_tab, int* nb_pixels)
{
    *pixel_tab = (Pixel**) malloc (sizeof (Pixel*));
    (*pixel_tab)[0] = create_pixel(point->pos_x, point->pos_y);
    *nb_pixels = 1;
}


int min(int v1, int v2){
    if (v1<v2){
        return v1;
    } else {
        return v2;
    }
}

int max(int v1, int v2){
    if (v1>v2){
        return v1;
    } else {
        return v2;
    }
}

void pixel_line(Line* line, Pixel*** pixel, int* nb_pixels){
    int x1 = line->p1->pos_x;
    int y1 = line->p1->pos_y;
    int x2 = line->p2->pos_x;
    int y2 = line->p2->pos_y;

    int dx;
    int dy;

    if (x2>x1){
        dx = x2 - x1;
        dy = y2 - y1;
    } else {
        dx = x1 - x2;
        dy = y1 - y2;
    }

    int dmin = min(dx, abs(dy));
    int dmax = max(dx, abs(dy));

    int nb_segs = dmin + 1;

    int taille_de_base = (dmax + 1)/(dmin +1 );

    int segments[nb_segs];

    for (int i = 0; i < nb_segs; i++) {
        segments[i] = taille_de_base;
    }

    int restants = (dmax + 1) % (dmin +1);

    int nombre_total_pixel = nb_segs * taille_de_base + restants;

    *nb_pixels = nombre_total_pixel;

    *pixel = (Pixel **) malloc(sizeof(Pixel **) * *nb_pixels);

    int *cumuls = (int*)malloc(nb_segs*sizeof(int));

    cumuls[0]=0;
    for (int i = 1; i < nb_segs ; i++){
        cumuls[i] = ((i+1)*restants)%(dmin+1) < ((i*restants)%(dmin+1));
        segments[i] = segments[i] + cumuls[i];
    }

    if (dy < 0){
        if (dx > abs(dy)){
            int idx = 0;
            segments[0] = segments[0] - 1;
            Pixel* p1 = create_pixel(x1, y1);
            *pixel[idx] = p1;
            idx++;
            for (int i=0; i<nb_segs;i++){
                for (int j=0; j<segments[i]; j++){
                    x1++;
                    Pixel* p1 = create_pixel(x1, y1);
                    (*pixel)[idx] = p1;
                    idx++;
                }
                y1--;
            }
        } else {
            int idx = 0;
            segments[0] = segments[0] - 1;
            Pixel* p1 = create_pixel(x1, y1);
            *pixel[idx] = p1;
            idx++;
            for (int i=0; i<nb_segs;i++){
                for (int j=0; j<segments[i]; j++){
                    y1++;
                    Pixel* p1 = create_pixel(x1, y1);
                    (*pixel)[idx] = p1;
                    idx++;
                }
                x1--;
            }
        }
    } else {
        if (dx > dy){
            int idx = 0;
            segments[0] = segments[0] - 1;
            Pixel* p1 = create_pixel(x1, y1);
            *pixel[idx] = p1;
            idx++;
            for (int i=0; i<nb_segs;i++){
                for (int j=0; j<segments[i]; j++){
                    x1++;
                    Pixel* p1 = create_pixel(x1, y1);
                    (*pixel)[idx] = p1;
                    idx++;
                }
                y1++;
            }
        } else {
            int idx = 0;
            segments[0] = segments[0] - 1;
            Pixel *p1 = create_pixel(x1, y1);
            *pixel[idx] = p1;
            idx++;
            for (int i = 0; i < nb_segs; i++) {
                for (int j = 0; j<segments[i]; j++) {
                    y1++;
                    Pixel *p1 = create_pixel(x1, y1);
                    (*pixel)[idx] = p1;
                    idx++;
                }
                x1++;
            }
        }
    }

}

void pixel_square(Square* square, Pixel*** pixel_tab, int* nb_pixels) {
    int px = square->p1->pos_x;
    int py = square->p1->pos_y;
    int n = square->n;

    int tempo_nb_pixels;

    *pixel_tab = (Pixel **)malloc(sizeof(Pixel *) * n * 4);

    Pixel **pixels_bis = NULL;
    pixels_bis = (Pixel **) malloc(sizeof(Pixel *) * (n+1)*4);

    Line* l1 = create_line(px, py, px, py + n);
    pixel_line(l1, &pixels_bis, nb_pixels);

    tempo_nb_pixels = *nb_pixels;
    printf("tmp nb pixels : %d", tempo_nb_pixels);

    for (int i = 0; i < tempo_nb_pixels; i++) {
        (*pixel_tab)[i] = pixels_bis[i];
        printf(" 1 pixel : %d %d\n", (*pixel_tab)[i]->px, (*pixel_tab)[i]->py);
    }

    delete_line(l1);

    Line* l2 = create_line(px, py + n, px + n, py + n);
    pixel_line(l2, &pixels_bis, nb_pixels);

    for (int i = tempo_nb_pixels; i < 2*tempo_nb_pixels; i++) {
        (*pixel_tab)[i] = pixels_bis[i - tempo_nb_pixels];
        printf(" 2 pixel : %d %d\n", (*pixel_tab)[i]->px, (*pixel_tab)[i]->py);
    }

    delete_line(l2);

    Line* l3 = create_line(px + n, py, px + n, py + n);
    pixel_line(l3, &pixels_bis, nb_pixels);

    for (int i = 2*tempo_nb_pixels; i < 3*tempo_nb_pixels; i++) {
        (*pixel_tab)[i] = pixels_bis[i - 2*tempo_nb_pixels];
        printf(" 3 pixel : %d %d\n", (*pixel_tab)[i]->px, (*pixel_tab)[i]->py);
    }

    delete_line(l3);

    Line* l4 = create_line(px, py, px + n, py);
    pixel_line(l4, &pixels_bis, nb_pixels);

    for (int i=3*tempo_nb_pixels; i<4*tempo_nb_pixels ;i++){
        (*pixel_tab)[i] = pixels_bis[i - 3*tempo_nb_pixels];
        printf(" 4 pixel : %d %d\n", (*pixel_tab)[i]->px, (*pixel_tab)[i]->py);
    }

    delete_line(l4);

    *nb_pixels = (n+1)*4;

    free(pixels_bis);

    printf("--------------------------------------------------------\n");
    for (int i = 0; i < *nb_pixels; i++) {
        printf(" %d %d \n", (*pixel_tab)[i]->px, (*pixel_tab)[i]->py);
    }
}



Pixel** create_shape_to_pixel(Shape* shape, int* nb_pixels){
    if (shape->shape_type==POINT){
        Pixel **pixels = NULL;
        pixel_point(shape->ptrShape, &pixels, nb_pixels);
        return pixels;

    } else if (shape->shape_type==LINE){
        Pixel **pixels = NULL;
        pixel_line(shape->ptrShape, &pixels, nb_pixels);
        return pixels;

    } else if (shape->shape_type==SQUARE){
        Pixel **pixels = NULL;
        pixel_square(shape->ptrShape, &pixels, nb_pixels);
        return pixels;
    }
}

void delete_pixel_shape(Pixel** pixel, int nb_pixels){
    free(pixel);
}
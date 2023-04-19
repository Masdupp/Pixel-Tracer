#ifndef CPROJECT_POINT_H
#define CPROJECT_POINT_H

typedef struct {
    int pos_x;
    int pos_y;
}Point;

Point *create_point(int px, int py);

void delete_point(Point * point);

void print_point(Point * p);
#endif //CPROJECT_POINT_H

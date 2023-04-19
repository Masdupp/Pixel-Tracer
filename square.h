
#ifndef CPROJECT_SQUARE_H
#define CPROJECT_SQUARE_H
#include "point.h"
typedef struct {
    Point *corner;
    int length;

}Square;
Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);

#endif //CPROJECT_SQUARE_H

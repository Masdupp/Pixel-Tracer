#include <stdlib.h>
#include <stdio.h>
#include "square.h"
Square *create_square(Point * point, int length){
    Square *square = (Square*) malloc(sizeof(Square) );
    square->corner = point;
    square->length = length;
    return square;
}

void delete_square(Square * square){
    free(square);
}
void print_square(Square * square){
    printf("SQUARE: %d %d %d", square->corner->pos_x, square->corner->pos_y, square->length);
}

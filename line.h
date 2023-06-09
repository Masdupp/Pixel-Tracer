#include "point.h"
#ifndef CPROJECT_LINE_H
#define CPROJECT_LINE_H

typedef struct line {
    Point *p1;
    Point *p2;
}Line;

Line *create_line(int x1, int y1, int x2, int y2);
void delete_line(Line * line);
void print_line(Line * line);

#endif //CPROJECT_LINE_H


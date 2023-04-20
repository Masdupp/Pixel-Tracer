#include <stdio.h>
#include "shapes.h"
int main () {
    while (1) {


        char c;
        printf("Please select one action:\n");
        printf("    A- Add a shape\n");
        printf("    B- Display the list of shapes\n");
        printf("    C- Delete a shape\n");
        printf("    D- Drawing the shapes\n");
        printf("    E- Help\n");
        printf("    [Other actions]\n");

        scanf("%c", &c);
        while ((c > 70) || (c < 65)) {
            printf("Please select one action:\n");
            printf("    A- Add a shape\n");
            printf("    B- Display the list of shapes\n");
            printf("    C- Delete a shape\n");
            printf("    D- Drawing the shapes\n");
            printf("    E- Help\n");
            printf("    [Other actions]\n");
            scanf("%c", &c);
        }
        if (c == 65) {
            printf("Your choice : A\n"
                   "Please select an action:\n"
                   "1- Add a point\n"
                   "2- Add a line\n"
                   "3- Add circle\n"
                   "4- Add a square\n"
                   "5- Add a rectangle\n"
                   "6- Add a polygon\n"
                   "7- Return to previous menu \n");
        }
        if (c==66){

        }
        if (c==67){

        }
        if (c==68){

        }
        if (c==69){

        }
            int d;
            scanf("%d", &d);
            while ((d < 0) || (d > 7)) {
                printf("Your choice : A\n"
                       "Please select an action:\n"
                       "1- Add a point\n"
                       "2- Add a line\n"
                       "3- Add circle\n"
                       "4- Add a square\n"
                       "5- Add a rectangle\n"
                       "6- Add a polygon\n"
                       "7- Return to previous menu\n");
            }
            int px, py, x1, x2, y1, y2, length, width, radius;
            if (d == 1) {
                printf("Your choice : 1\n"
                       "Enter the coordinates of the point px py:");
            }
            if (d == 2) {
                printf("Your choice : 2\n"
                       "Enter the information of the line:\n"
                       "Enter the first point x1 y1:");
                scanf("%d %d", &x1, &y1);
                printf("Enter the second point x2 y2:");
                scanf("%d %d", &x2, &y2);
                create_line_shape(x1, y1, x2, y2);
            }
            if (d == 3) {
                printf("Enter the circle information:\n"
                       "Enter the center point x1 y1:");
                scanf("%d %d",&x1,&y1);
                printf("Enter the radius of the circle:");
                scanf("%d", radius);
                create_circle_shape(x1, y1, radius);
            }
            if (d == 4) {

            }
            if (d == 5) {

            }
            if (d == 6) {

            }

}
    return 0;
}

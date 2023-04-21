#include <stdio.h>
#include "shapes.h"
#include <stdbool.h>

int main () {
    char decision;
    int action;
    bool cond = true;

    while (cond == true) {
        printf("Please select one action:\n");
        printf("    A- Add a shape\n");
        printf("    B- Display the list of shapes\n");
        printf("    C- Delete a shape\n");
        printf("    D- Drawing the shapes\n");
        printf("    E- Help\n");
        printf("    [Other actions]\n");
        printf("----------Your action----------\n");

        scanf(" %c", &decision); // add a space before %c to skip leading whitespace

        while ((decision > 70) || (decision < 65)) {
            printf("Please select one action:\n");
            printf("    A- Add a shape\n");
            printf("    B- Display the list of shapes\n");
            printf("    C- Delete a shape\n");
            printf("    D- Drawing the shapes\n");
            printf("    E- Help\n");
            printf("    [Other actions]\n");
            printf("----------Your action----------\n");

            scanf(" %c", &decision); // add a space before %c to skip leading whitespace
        }

        if (decision == 'A') {
            int px, py, x1, y1, x2, y2, width, radius, length;
            printf("Your choice : A\n"
                   "Please select an action:\n"
                   "1- Add a point\n"
                   "2- Add a line\n"
                   "3- Add circle\n"
                   "4- Add a square\n"
                   "5- Add a rectangle\n"
                   "6- Add a polygon\n"
                   "7- Return to previous menu \n"
                   "----------Your action----------\n");

            scanf("%d", &action);

            while ((action < 1) || (action > 7)) {
                printf("Your choice : A\n"
                       "Please select an action:\n"
                       "1- Add a point\n"
                       "2- Add a line\n"
                       "3- Add circle\n"
                       "4- Add a square\n"
                       "5- Add a rectangle\n"
                       "6- Add a polygon\n"
                       "7- Return to previous menu \n"
                       "----------Your action----------\n");

                scanf("%d", &action);
            }

            if (action == 1) {
                printf("Your choice: 1\nEnter the coordinates of the point (px, py): ");
                scanf("%d %d", &px, &py);
                Shape *shape = create_point_shape(px, py);
                printf("Your point has been created!\n");
            }

            if(action==2){
            printf("Your choice : 2\n"
                   "Enter the information of the line:\n"
                   "Enter the first point x1 y1: ");
            scanf("%d %d", &x1, &y1);
            printf("Enter the second point x2 y2: ");
            scanf("%d %d", &x2, &y2);
            create_line_shape(x1, y1, x2, y2);
            printf("Your line has been created !\n");
            }
            if(action==3){
                printf("Your choice : 3\n"
                        "Enter the information of the circle px py and radius :\n"
                        "Enter the coordinates of the center px py: ");
                scanf("%d %d", &px, &py);
                printf("Enter the length of the radius :");
                scanf("%d", &radius);
                create_circle_shape(px, py, radius);
                printf("Your circle has been created !\n");

            }
            }


            if (decision==66){

            }
            if (decision==67){

            }
            if (decision==68){

            }
            if (decision==69){

            }


}
    return 0;
}

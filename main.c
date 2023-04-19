#include <stdio.h>
int main ()


{
    char c;
    printf("Please select an action:\n");
    printf("    A- Add a shape\n");
    printf("    B- Display the list of shapes\n");
    printf("    C- Delete a shape\n");
    printf("    D- Drawing the shapes\n");
    printf("    E- Help\n");
    printf("    [Other actions]\n");

    scanf("%c",&c );
    while((c>70) || (c<65)){
        printf("Please select an action:\n");
        printf("    A- Add a shape\n");
        printf("    B- Display the list of shapes\n");
        printf("    C- Delete a shape\n");
        printf("    D- Drawing the shapes\n");
        printf("    E- Help\n");
        printf("    [Other actions]\n");

        scanf("%c",&c );
    }
    if (c=="A"){
        
    }


    return 0;
}
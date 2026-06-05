#include <stdio.h>
#include "graphics.h"

int main()
{
    int choice;
    int row, startCol, endCol;

    initializeCanvas();

    while(1)
    {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Display Canvas\n");
        printf("2. Draw Horizontal Line\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        if(scanf("%d", &choice) != 1)
        {
            printf("Please enter a valid number!\n");
            while(getchar() != '\n');
            continue;
        }

        switch(choice)
        {
            case 1:
                displayCanvas();
                break;

            case 2:
                printf("Enter row: ");
                scanf("%d", &row);

                printf("Enter start column: ");
                scanf("%d", &startCol);

                printf("Enter end column: ");
                scanf("%d", &endCol);

                drawHorizontalLine(row, startCol, endCol);

                printf("Line Drawn Successfully!\n");
                break;

            case 3:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
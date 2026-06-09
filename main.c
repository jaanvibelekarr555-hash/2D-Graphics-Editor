#include <stdio.h>
#include "graphics.h"

int main()
{
    int choice;
    int row, startCol, endCol;
    int col, startRow, endRow;
    int rectStartRow, rectStartCol;
    int rectEndRow, rectEndCol;
    int triRow, triCol, triHeight;
    int circleRow, circleCol, radius;
    initializeCanvas();

    while (1)
    {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Display Canvas\n");
        printf("2. Draw Horizontal Line\n");
        printf("3. Draw Vertical Line\n");
        printf("4. Draw Rectangle\n");
        printf("5. Draw Triangle\n");
        printf("6. Draw Circle\n");
        printf("7. Clear Canvas\n");
        printf("8. Save Canvas\n");
        printf("9. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Please enter a valid number!\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice)
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
            printf("Enter column: ");
            scanf("%d", &col);

            printf("Enter start row: ");
            scanf("%d", &startRow);

            printf("Enter end row: ");
            scanf("%d", &endRow);

            drawVerticalLine(col, startRow, endRow);

            printf("Vertical Line Drawn Successfully!\n");
            break;
        case 4:

            printf("Enter start row: ");
            scanf("%d", &rectStartRow);

            printf("Enter start column: ");
            scanf("%d", &rectStartCol);

            printf("Enter end row: ");
            scanf("%d", &rectEndRow);

            printf("Enter end column: ");
            scanf("%d", &rectEndCol);

            drawRectangle(
                rectStartRow,
                rectStartCol,
                rectEndRow,
                rectEndCol);

            printf("Rectangle Drawn Successfully!\n");
            displayCanvas();
            break;
        case 5:

            printf("Enter top row: ");
            scanf("%d", &triRow);

            printf("Enter center column: ");
            scanf("%d", &triCol);

            printf("Enter height: ");
            scanf("%d", &triHeight);

            drawTriangle(triRow, triCol, triHeight);

            printf("Triangle Drawn Successfully!\n");
            break;
        case 6:

            printf("Enter center row: ");
            scanf("%d", &circleRow);

            printf("Enter center column: ");
            scanf("%d", &circleCol);

            printf("Enter radius: ");
            scanf("%d", &radius);

            drawCircle(circleRow, circleCol, radius);

            printf("Circle Drawn Successfully!\n");
            break;
        case 7:

            clearCanvas();

            printf("Canvas Cleared Successfully!\n");
            break;
        case 8:
{
            char filename[50];

            printf("Enter file name: ");
            scanf("%s", filename);

            saveCanvasToFile(filename);

            break;
}
        case 9:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
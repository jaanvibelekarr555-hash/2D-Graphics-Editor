#include <stdio.h>
#include "graphics.h"

char canvas[ROWS][COLS];

void initializeCanvas()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = ' ';
        }
    }
}

void displayCanvas()
{
    int i, j;

    for(j = 0; j < COLS + 2; j++)
    {
        printf("-");
    }

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        printf("|");

        for(j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }

        printf("|\n");
    }

    for(j = 0; j < COLS + 2; j++)
    {
        printf("-");
    }

    printf("\n");
}
void drawHorizontalLine(int row, int startCol, int endCol)
{
    int i;

    if(row < 0 || row >= ROWS)
        return;

    for(i = startCol; i <= endCol && i < COLS; i++)
    {
        if(i >= 0)
            canvas[row][i] = '*';
    }
}
void drawVerticalLine(int col, int startRow, int endRow)
{
    int i;

    if(col < 0 || col >= COLS)
        return;

    for(i = startRow; i <= endRow && i < ROWS; i++)
    {
        if(i >= 0)
            canvas[i][col] = '*';
    }
}
void drawRectangle(int startRow, int startCol, int endRow, int endCol)
{
    drawHorizontalLine(startRow, startCol, endCol);
    drawHorizontalLine(endRow, startCol, endCol);

    drawVerticalLine(startCol, startRow, endRow);
    drawVerticalLine(endCol, startRow, endRow);
}
void drawTriangle(int row, int col, int height)
{
    int i, j;

    for(i = 0; i < height; i++)
    {
        for(j = col - i; j <= col + i; j++)
        {
            if(row + i < ROWS && j >= 0 && j < COLS)
            {
                canvas[row + i][j] = '*';
            }
        }
    }
}
void drawCircle(int centerRow, int centerCol, int radius)
{
    int row, col;

    for(row = 0; row < ROWS; row++)
    {
        for(col = 0; col < COLS; col++)
        {
            int dx = row - centerRow;
            int dy = col - centerCol;

            int distanceSquared = dx * dx + dy * dy;
            int radiusSquared = radius * radius;

            if(distanceSquared >= radiusSquared - radius &&
               distanceSquared <= radiusSquared + radius)
            {
                canvas[row][col] = '*';
            }
        }
    }
}
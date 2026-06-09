#include <stdio.h>
#include "graphics.h"

char canvas[ROWS][COLS];
char backupCanvas[ROWS][COLS];

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
void clearCanvas()
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
void saveCanvasToFile(char filename[])
{
    FILE *fp = fopen(filename, "w");

    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            fputc(canvas[i][j], fp);
        }
        fputc('\n', fp);
    }

    fclose(fp);

    printf("Canvas saved successfully!\n");
}
void loadCanvasFromFile(char filename[])
{
    FILE *fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            canvas[i][j] = fgetc(fp);
        }

        fgetc(fp); // consume newline
    }

    fclose(fp);

    printf("Canvas loaded successfully!\n");
}
void drawText(int row, int col, char text[])
{
    int i = 0;

    while(text[i] != '\0' && (col + i) < COLS)
    {
        canvas[row][col + i] = text[i];
        i++;
    }
}
void saveState()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            backupCanvas[i][j] = canvas[i][j];
        }
    }
}
void undoLastAction()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = backupCanvas[i][j];
        }
    }

    printf("Undo successful!\n");
}
void deleteRectangle(int startRow, int startCol, int endRow, int endCol)
{
    int i, j;

    for(i = startRow; i <= endRow; i++)
    {
        for(j = startCol; j <= endCol; j++)
        {
            if(i >= 0 && i < ROWS && j >= 0 && j < COLS)
            {
                canvas[i][j] = ' ';
            }
        }
    }

    printf("Rectangle Deleted Successfully!\n");
}
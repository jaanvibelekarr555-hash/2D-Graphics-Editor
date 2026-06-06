#ifndef GRAPHICS_H
#define GRAPHICS_H

#define ROWS 20
#define COLS 50

void initializeCanvas();
void displayCanvas();
void drawHorizontalLine(int row, int startCol, int endCol);
void drawVerticalLine(int col, int startRow, int endRow);
#endif
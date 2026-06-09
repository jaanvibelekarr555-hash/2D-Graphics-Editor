#ifndef GRAPHICS_H
#define GRAPHICS_H

#define ROWS 20
#define COLS 50

void initializeCanvas();
void displayCanvas();
void drawHorizontalLine(int row, int startCol, int endCol);
void drawVerticalLine(int col, int startRow, int endRow);
void drawRectangle(int startRow, int startCol, int endRow, int endCol);
void drawTriangle(int row, int col, int height);
void drawCircle(int centerRow, int centerCol, int radius);
void clearCanvas();
void saveCanvasToFile(char filename[]);
void loadCanvasFromFile(char filename[]);
void drawText(int row, int col, char text[]);
void saveState();
void undoLastAction();
void deleteRectangle(int startRow, int startCol, int endRow, int endCol);
void modifyRectangle(
    int oldStartRow,
    int oldStartCol,
    int oldEndRow,
    int oldEndCol,
    int newStartRow,
    int newStartCol,
    int newEndRow,
    int newEndCol);
#endif
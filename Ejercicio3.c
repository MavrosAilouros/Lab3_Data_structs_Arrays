/*
 *  Excercise 3 - Diagonal of 1s in a binary matrix
 *  ---------------------------------------------------------------
 *  Compile: gcc -Wall ejercicio3.c -o ej3
 */

 #include <stdio.h>
 #include <stdlib.h>   /* rand, srand */
 #include <time.h>     /* time        */
 
 #define SIZE 4       /* Changes Size of random matrix 
                       * for example matrix change this value to 6*/

 #define RAND_FILL 1   /*   change to "0" to use the example matrix */
 
 #if RAND_FILL == 0
 /* -------- Example Matrix From the PDF file -------- */
 int matrix[SIZE][SIZE] = {
     {1,0,1,0,1,1},
     {1,0,1,1,1,0},
     {0,1,1,1,1,1},
     {1,1,1,1,1,1},
     {0,0,1,1,1,0},
     {0,0,0,1,0,0}
 };
 #else
 int matrix[SIZE][SIZE];
 #endif
 
 /* ---------- Outputs longest "1" sequence ---------- */

 int findLargestLine(int m[][SIZE])
 {
     int maxLen = 0;
 
     /* Descending diagonals that begin in column 0 */
     for (int col = 0; col < SIZE; ++col) {
         int len = 0;
         for (int r = 0, c = col; r < SIZE && c < SIZE; ++r, ++c) {
             if (m[r][c] == 1) {
                 ++len;
                 if (len > maxLen) maxLen = len;
             } else {
                 len = 0;
             }
         }
     }
 
     /* Descending diagonals that start from rows other than the first row (row > 0) */
     for (int startRow = 1; startRow < SIZE; ++startRow) {
         int len = 0;
         for (int r = startRow, c = 0; r < SIZE && c < SIZE; ++r, ++c) {
             if (m[r][c] == 1) {
                 ++len;
                 if (len > maxLen) maxLen = len;
             } else {
                 len = 0;
             }
         }

     }

    /* Ascending diagonals that begin in the first column */
     for (int row = SIZE - 1; row >= 0; --row) {
        int len = 0;
        for (int r = row, c = 0; r >= 0 && c < SIZE; --r, ++c) {
            if (m[r][c] == 1) {
                ++len;
                if (len > maxLen) maxLen = len;
            } else {
                len = 0;
            }
        }
    }
    
    /* Ascending diagonals that begin from the last row from columns > 0*/
    for (int col = 1; col < SIZE; ++col) {
        int len = 0;
        for (int r = SIZE - 1, c = col; r >= 0 && c < SIZE; --r, ++c) {
            if (m[r][c] == 1) {
                ++len;
                if (len > maxLen) maxLen = len;
            } else {
                len = 0;
            }
        }
    }
 
     /* Returns the length of the longest diagonal sequence of 1s found in the matrix */
     return maxLen;
 }
 
 /* ---------- Prints the Matrix in the terminal ---------- */

 void printMatrix(int m[][SIZE])
 {
     puts("La matriz utilizada corresponde a:");
     for (int i = 0; i < SIZE; ++i) {
         for (int j = 0; j < SIZE; ++j)
             printf("%d ", m[i][j]);
         putchar('\n');
     }
     putchar('\n');
 }
 
 int main(void)
 {
        /* --------- Randomly fills the matrix with 0s and 1s --------- */

 #if RAND_FILL

     srand((unsigned)time(NULL));
     for (int i = 0; i < SIZE; ++i)
         for (int j = 0; j < SIZE; ++j)
             matrix[i][j] = rand() % 2;
 #endif
 
     printMatrix(matrix);
 
     int largestLine = findLargestLine(matrix);
 
     printf("El tamaño de la secuencia en diagonal de 1's más grande es: %d\n",
            largestLine);
 
     return 0;
 }
 